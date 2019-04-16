/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:41:57 by juspende          #+#    #+#             */
/*   Updated: 2019/04/16 15:03:06 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_whirlpool.h"
#include "../includes/error.h"

error_t whirlpoolCompute(const void *data, size_t length, uint8_t *digest)
{
	//Allocate a memory buffer to hold the Whirlpool context
	t_whirlpool *context = malloc(sizeof(t_whirlpool));
	//Failed to allocate memory?
	if(context == NULL)
		return ERROR_OUT_OF_MEMORY;
	//Initialize the Whirlpool context
	whirlpoolInit(context);
	//Digest the message
	whirlpoolUpdate(context, data, length);
	//Finalize the Whirlpool message digest
	whirlpoolFinal(context, digest);
	//Free previously allocated memory
	free(context);
	//Successful processing
	return NO_ERROR;
}

/**
  * @brief Initialize Whirlpool message digest context
  * @param[in] context Pointer to the Whirlpool context to initialize
  **/

void whirlpoolInit(t_whirlpool *context)
{
	unsigned int	i;

	//Set initial hash value
	i = 0;
	while (i < 8)
		context->h[i++] = 0;
	//Number of bytes in the buffer
	context->size = 0;
	//Total length of the message
	context->totalSize = 0;
}

/**
  * @brief Update the Whirlpool context with a portion of the message being hashed
  * @param[in] context Pointer to the Whirlpool context
  * @param[in] data Pointer to the buffer being hashed
  * @param[in] length Length of the buffer
**/

void whirlpoolUpdate(t_whirlpool *context, const void *data, size_t length)
{
	size_t n;

	//Process the incoming data
	while(length > 0)
	{
		//The buffer can hold at most 64 bytes
		n = MIN(length, 64 - context->size);
		//Copy the data to the buffer
		ft_memcpy(context->buffer + context->size, data, n);
		//Update the Whirlpool context
		context->size += n;
		context->totalSize += n;
		//Advance the data pointer
		data = (uint8_t *) data + n;
		//Remaining bytes to process
		length -= n;
		//Process message in 8-word blocks
		if(context->size == 64)
		{
			//Transform the 8-word block
			whirlpoolProcessBlock(context);
			//Empty the buffer
			context->size = 0;
		}
		}
}

uint64_t swapInt64(uint64_t value)
 {
    return SWAPINT64(value);
 }

/**
  * @brief Finish the Whirlpool message digest
  * @param[in] context Pointer to the Whirlpool context
  * @param[out] digest Calculated digest (optional parameter)
**/

void whirlpoolFinal(t_whirlpool *context, uint8_t *digest)
{
	unsigned int i;
	size_t paddingSize;
	uint64_t totalSize;

	//Length of the original message (before padding)
	totalSize = context->totalSize * 8;
	//Pad the message so that its length is congruent to 32 modulo 64
	if(context->size < 32)
		paddingSize = 32 - context->size;
	else
		paddingSize = 64 + 32 - context->size;
	//Append padding
	whirlpoolUpdate(context, padding, paddingSize);
	//Append the length of the original message
	context->x[4] = 0;
	context->x[5] = 0;
	context->x[6] = 0;
	context->x[7] = swapInt64((uint64_t) totalSize);
	//Calculate the message digest
	whirlpoolProcessBlock(context);
	//Convert from host byte order to big-endian byte order
	i = 0;
    while (i < 8)
	{
		context->h[i] = swapInt64((uint64_t) context->h[i]);
		++i;
	}
	//Copy the resulting digest
	if (digest != NULL)
		ft_memcpy(digest, context->digest, WHIRLPOOL_DIGEST_SIZE);
 }

/**
  * @brief Process message in 16-word blocks
  * @param[in] context Pointer to the Whirlpool context
**/

void whirlpoolProcessBlock(t_whirlpool *context)
{
	unsigned int i;

	uint64_t *x = context->x;
	uint64_t *k = context->k;
	uint64_t *l = context->l;
	uint64_t *state = context->state;

	i = 0;
    while (i < 8)
	{
		x[i] = swapInt64((uint64_t) x[i]);
		++i;
	}

	k[0] = context->h[0];
	k[1] = context->h[1];
	k[2] = context->h[2];
	k[3] = context->h[3];
	k[4] = context->h[4];
	k[5] = context->h[5];
	k[6] = context->h[6];
	k[7] = context->h[7];

	state[0] = x[0] ^ k[0];
	state[1] = x[1] ^ k[1];
	state[2] = x[2] ^ k[2];
	state[3] = x[3] ^ k[3];
	state[4] = x[4] ^ k[4];
	state[5] = x[5] ^ k[5];
	state[6] = x[6] ^ k[6];
	state[7] = x[7] ^ k[7];

	i = 0;
	while (i < 10)
	{
		RHO(l[0], k, 0, rc[i++]);
		RHO(l[1], k, 1, 0);
		RHO(l[2], k, 2, 0);
		RHO(l[3], k, 3, 0);
		RHO(l[4], k, 4, 0);
		RHO(l[5], k, 5, 0);
		RHO(l[6], k, 6, 0);
		RHO(l[7], k, 7, 0);

		k[0] = l[0];
		k[1] = l[1];
		k[2] = l[2];
		k[3] = l[3];
		k[4] = l[4];
		k[5] = l[5];
		k[6] = l[6];
		k[7] = l[7];

		RHO(l[0], state, 0, k[0]);
		RHO(l[1], state, 1, k[1]);
		RHO(l[2], state, 2, k[2]);
		RHO(l[3], state, 3, k[3]);
		RHO(l[4], state, 4, k[4]);
		RHO(l[5], state, 5, k[5]);
		RHO(l[6], state, 6, k[6]);
		RHO(l[7], state, 7, k[7]);

		state[0] = l[0];
		state[1] = l[1];
		state[2] = l[2];
		state[3] = l[3];
		state[4] = l[4];
		state[5] = l[5];
		state[6] = l[6];
		state[7] = l[7];
	}

	context->h[0] ^= state[0] ^ x[0];
	context->h[1] ^= state[1] ^ x[1];
	context->h[2] ^= state[2] ^ x[2];
	context->h[3] ^= state[3] ^ x[3];
	context->h[4] ^= state[4] ^ x[4];
	context->h[5] ^= state[5] ^ x[5];
	context->h[6] ^= state[6] ^ x[6];
	context->h[7] ^= state[7] ^ x[7];
}

void			whirlpool(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	t_whirlpool		whirlpool;
	uint64_t		*res;
	int				index;
	uint8_t			*digest;

	index = -1;
	res = NULL;
	digest = NULL;
	(void)ssl_flag;
	while (++index < ssl->size_printed)
	{
		if (ssl->to_hash[index] != NULL)
		{
			printf("begin\n");
			whirlpoolInit(&whirlpool);
			printf("Init ok\n");
			whirlpoolUpdate(&whirlpool, ssl->to_hash[index], ssl->f_size[index]);
			printf("Update ok\n");
			whirlpoolFinal(&whirlpool, digest);
			printf("Final ok\n");
			whirlpoolProcessBlock(&whirlpool);
			printf("Block ok\n");
		}
		uint64_t tmp;
		tmp = whirlpool.h[1];
		printf("%16.16lx", (unsigned long)tmp);
	}
	return ;
}

