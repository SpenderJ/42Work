/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirpool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:41:57 by juspende          #+#    #+#             */
/*   Updated: 2019/04/15 19:02:02 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_whirpool.h"

void			whirlpooltransform(uint64_t *digest, const uint64_t *block)
	{
#if CRYPTOPP_BOOL_SSE2_ASM_AVAILABLE
	if (HasISSE())
	{
#ifdef __GNUC__
	#if CRYPTOPP_BOOL_X64
		CRYPTOPP_ALIGN_DATA(16) uint64 workspace[16];
	#endif
	__asm__ __volatile__
	(
		INTEL_NOPREFIX
		AS_PUSH_IF86(	bx)
		AS2(	mov		AS_REG_6, WORD_REG(ax))
#else
	#if _MSC_VER < 1300
		AS_PUSH_IF86(	bx)
	#endif
		AS2(	lea		AS_REG_6, [Whirlpool_C])
		AS2(	mov		WORD_REG(cx), digest)
		AS2(	mov		WORD_REG(dx), block)
#endif
#if CRYPTOPP_BOOL_X86 || CRYPTOPP_BOOL_X32
		AS2(	mov		eax, esp)
		AS2(	and		esp, -16)
		AS2(	sub		esp, 16*8)
		AS_PUSH_IF86( ax)

    #if CRYPTOPP_BOOL_X86
        #define SSE2_workspace	esp+WORD_SZ
    #elif CRYPTOPP_BOOL_X32
        #define SSE2_workspace	esp+(WORD_SZ*2)
    #endif
#else
    #define SSE2_workspace	%3
#endif
		AS2(	xor		esi, esi)
		ASL(0)
		AS2(	movq	mm0, [WORD_REG(cx)+8*WORD_REG(si)])
		AS2(	movq	[SSE2_workspace+8*WORD_REG(si)], mm0)		// k
		AS2(	pxor	mm0, [WORD_REG(dx)+8*WORD_REG(si)])
		AS2(	movq	[SSE2_workspace+64+8*WORD_REG(si)], mm0)	// s
		AS2(	movq	[WORD_REG(cx)+8*WORD_REG(si)], mm0)
		AS1(	inc		WORD_REG(si))
		AS2(	cmp		WORD_REG(si), 8)
		ASJ(	jne,	0, b)

		AS2(	xor		esi, esi)
		ASL(1)

#define KSL0(a, b)	AS2(movq	mm##a, b)
#define KSL1(a, b)	AS2(pxor	mm##a, b)

#define KSL(op, i, a, b, c, d)	\
	AS2(mov		eax, [SSE2_workspace+8*i])\
	AS2(movzx	edi, al)\
	KSL##op(a, [AS_REG_6+3*2048+8*WORD_REG(di)])\
	AS2(movzx	edi, ah)\
	KSL##op(b, [AS_REG_6+2*2048+8*WORD_REG(di)])\
	AS2(shr		eax, 16)\
	AS2(movzx	edi, al)\
	AS2(shr		eax, 8)\
	KSL##op(c, [AS_REG_6+1*2048+8*WORD_REG(di)])\
	KSL##op(d, [AS_REG_6+0*2048+8*WORD_REG(ax)])

#define KSH0(a, b)	\
	ASS(pshufw	mm##a, mm##a, 1, 0, 3, 2)\
	AS2(pxor	mm##a, b)
#define KSH1(a, b)	\
	AS2(pxor	mm##a, b)
#define KSH2(a, b)	\
	AS2(pxor	mm##a, b)\
	AS2(movq	[SSE2_workspace+8*a], mm##a)

#define KSH(op, i, a, b, c, d)	\
	AS2(mov		eax, [SSE2_workspace+8*((i+4)-8*((i+4)/8))+4])\
	AS2(movzx	edi, al)\
	KSH##op(a, [AS_REG_6+3*2048+8*WORD_REG(di)])\
	AS2(movzx	edi, ah)\
	KSH##op(b, [AS_REG_6+2*2048+8*WORD_REG(di)])\
	AS2(shr		eax, 16)\
	AS2(movzx	edi, al)\
	AS2(shr		eax, 8)\
	KSH##op(c, [AS_REG_6+1*2048+8*WORD_REG(di)])\
	KSH##op(d, [AS_REG_6+0*2048+8*WORD_REG(ax)])

#define TSL(op, i, a, b, c, d)	\
	AS2(mov		eax, [SSE2_workspace+64+8*i])\
	AS2(movzx	edi, al)\
	KSL##op(a, [AS_REG_6+3*2048+8*WORD_REG(di)])\
	AS2(movzx	edi, ah)\
	KSL##op(b, [AS_REG_6+2*2048+8*WORD_REG(di)])\
	AS2(shr		eax, 16)\
	AS2(movzx	edi, al)\
	AS2(shr		eax, 8)\
	KSL##op(c, [AS_REG_6+1*2048+8*WORD_REG(di)])\
	KSL##op(d, [AS_REG_6+0*2048+8*WORD_REG(ax)])

#define TSH0(a, b)	\
	ASS(pshufw	mm##a, mm##a, 1, 0, 3, 2)\
	AS2(pxor	mm##a, [SSE2_workspace+8*a])\
	AS2(pxor	mm##a, b)
#define TSH1(a, b)	\
	AS2(pxor	mm##a, b)
#define TSH2(a, b)	\
	AS2(pxor	mm##a, b)\
	AS2(movq	[SSE2_workspace+64+8*a], mm##a)
#define TSH3(a, b)	\
	AS2(pxor	mm##a, b)\
	AS2(pxor	mm##a, [WORD_REG(cx)+8*a])\
	AS2(movq	[WORD_REG(cx)+8*a], mm##a)

#define TSH(op, i, a, b, c, d)	\
	AS2(mov		eax, [SSE2_workspace+64+8*((i+4)-8*((i+4)/8))+4])\
	AS2(movzx	edi, al)\
	TSH##op(a, [AS_REG_6+3*2048+8*WORD_REG(di)])\
	AS2(movzx	edi, ah)\
	TSH##op(b, [AS_REG_6+2*2048+8*WORD_REG(di)])\
	AS2(shr		eax, 16)\
	AS2(movzx	edi, al)\
	AS2(shr		eax, 8)\
	TSH##op(c, [AS_REG_6+1*2048+8*WORD_REG(di)])\
	TSH##op(d, [AS_REG_6+0*2048+8*WORD_REG(ax)])

		KSL(0, 4, 3, 2, 1, 0)
		KSL(0, 0, 7, 6, 5, 4)
		KSL(1, 1, 0, 7, 6, 5)
		KSL(1, 2, 1, 0, 7, 6)
		KSL(1, 3, 2, 1, 0, 7)
		KSL(1, 5, 4, 3, 2, 1)
		KSL(1, 6, 5, 4, 3, 2)
		KSL(1, 7, 6, 5, 4, 3)
		KSH(0, 0, 7, 6, 5, 4)
		KSH(0, 4, 3, 2, 1, 0)
		KSH(1, 1, 0, 7, 6, 5)
		KSH(1, 2, 1, 0, 7, 6)
		KSH(1, 5, 4, 3, 2, 1)
		KSH(1, 6, 5, 4, 3, 2)
		KSH(2, 3, 2, 1, 0, 7)
		KSH(2, 7, 6, 5, 4, 3)

		AS2(	pxor	mm0, [AS_REG_6 + 16*1024 + WORD_REG(si)*8])
		AS2(	movq	[SSE2_workspace], mm0)

		TSL(0, 4, 3, 2, 1, 0)
		TSL(0, 0, 7, 6, 5, 4)
		TSL(1, 1, 0, 7, 6, 5)
		TSL(1, 2, 1, 0, 7, 6)
		TSL(1, 3, 2, 1, 0, 7)
		TSL(1, 5, 4, 3, 2, 1)
		TSL(1, 6, 5, 4, 3, 2)
		TSL(1, 7, 6, 5, 4, 3)
		TSH(0, 0, 7, 6, 5, 4)
		TSH(0, 4, 3, 2, 1, 0)
		TSH(1, 1, 0, 7, 6, 5)
		TSH(1, 2, 1, 0, 7, 6)
		TSH(1, 5, 4, 3, 2, 1)
		TSH(1, 6, 5, 4, 3, 2)

		AS1(	inc		WORD_REG(si))
		AS2(	cmp		WORD_REG(si), 10)
		ASJ(	je,		2, f)

		TSH(2, 3, 2, 1, 0, 7)
		TSH(2, 7, 6, 5, 4, 3)

		ASJ(	jmp,	1, b)
		ASL(2)

		TSH(3, 3, 2, 1, 0, 7)
		TSH(3, 7, 6, 5, 4, 3)

#undef KSL
#undef KSH
#undef TSL
#undef TSH

		AS_POP_IF86(	sp)
		AS1(	emms)

#if defined(__GNUC__) || (defined(_MSC_VER) && _MSC_VER < 1300)
		AS_POP_IF86(	bx)
#endif
#ifdef __GNUC__
		ATT_PREFIX
			:
			: "a" (Whirlpool_C), "c" (digest), "d" (block)
	#if CRYPTOPP_BOOL_X64
			, "r" (workspace)
	#endif
			: "%esi", "%edi", "memory", "cc"
	#if CRYPTOPP_BOOL_X64
			, "%r9"
	#endif
		);
#endif
	}
	else
#endif		// #ifdef CRYPTOPP_X86_ASM_AVAILABLE
	{
		union { unsigned char ch[64]; unsigned long long ll[8]; } K, state;
		unsigned long long L[8];
		int r, i;

		i = 0; do state.ll[i] = (K.ll[i] = digest[i]) ^ (block)[i]; while (++i < 8);

		r = 0; do {
			L[0] = g_whirpool_c[0 * 256 + K.ch[0 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + K.ch[7 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + K.ch[6 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + K.ch[5 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + K.ch[4 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + K.ch[3 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + K.ch[2 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + K.ch[1 * 8 + 0]] ^
				g_whirpool_c[2048 + r];
			L[1] = g_whirpool_c[0 * 256 + K.ch[1 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + K.ch[0 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + K.ch[7 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + K.ch[6 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + K.ch[5 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + K.ch[4 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + K.ch[3 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + K.ch[2 * 8 + 0]];
			L[2] = g_whirpool_c[0 * 256 + K.ch[2 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + K.ch[1 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + K.ch[0 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + K.ch[7 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + K.ch[6 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + K.ch[5 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + K.ch[4 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + K.ch[3 * 8 + 0]];
			L[3] = g_whirpool_c[0 * 256 + K.ch[3 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + K.ch[2 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + K.ch[1 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + K.ch[0 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + K.ch[7 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + K.ch[6 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + K.ch[5 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + K.ch[4 * 8 + 0]];
			L[4] = g_whirpool_c[0 * 256 + K.ch[4 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + K.ch[3 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + K.ch[2 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + K.ch[1 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + K.ch[0 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + K.ch[7 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + K.ch[6 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + K.ch[5 * 8 + 0]];
			L[5] = g_whirpool_c[0 * 256 + K.ch[5 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + K.ch[4 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + K.ch[3 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + K.ch[2 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + K.ch[1 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + K.ch[0 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + K.ch[7 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + K.ch[6 * 8 + 0]];
			L[6] = g_whirpool_c[0 * 256 + K.ch[6 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + K.ch[5 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + K.ch[4 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + K.ch[3 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + K.ch[2 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + K.ch[1 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + K.ch[0 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + K.ch[7 * 8 + 0]];
			L[7] = g_whirpool_c[0 * 256 + K.ch[7 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + K.ch[6 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + K.ch[5 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + K.ch[4 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + K.ch[3 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + K.ch[2 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + K.ch[1 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + K.ch[0 * 8 + 0]];

			L[0] = (K.ll[0] = L[0]) ^
				g_whirpool_c[0 * 256 + state.ch[0 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + state.ch[7 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + state.ch[6 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + state.ch[5 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + state.ch[4 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + state.ch[3 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + state.ch[2 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + state.ch[1 * 8 + 0]];
			L[1] = (K.ll[1] = L[1]) ^
				g_whirpool_c[0 * 256 + state.ch[1 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + state.ch[0 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + state.ch[7 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + state.ch[6 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + state.ch[5 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + state.ch[4 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + state.ch[3 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + state.ch[2 * 8 + 0]];
			L[2] = (K.ll[2] = L[2]) ^
				g_whirpool_c[0 * 256 + state.ch[2 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + state.ch[1 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + state.ch[0 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + state.ch[7 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + state.ch[6 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + state.ch[5 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + state.ch[4 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + state.ch[3 * 8 + 0]];
			L[3] = (K.ll[3] = L[3]) ^
				g_whirpool_c[0 * 256 + state.ch[3 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + state.ch[2 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + state.ch[1 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + state.ch[0 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + state.ch[7 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + state.ch[6 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + state.ch[5 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + state.ch[4 * 8 + 0]];
			L[4] = (K.ll[4] = L[4]) ^
				g_whirpool_c[0 * 256 + state.ch[4 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + state.ch[3 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + state.ch[2 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + state.ch[1 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + state.ch[0 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + state.ch[7 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + state.ch[6 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + state.ch[5 * 8 + 0]];
			L[5] = (K.ll[5] = L[5]) ^
				g_whirpool_c[0 * 256 + state.ch[5 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + state.ch[4 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + state.ch[3 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + state.ch[2 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + state.ch[1 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + state.ch[0 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + state.ch[7 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + state.ch[6 * 8 + 0]];
			L[6] = (K.ll[6] = L[6]) ^
				g_whirpool_c[0 * 256 + state.ch[6 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + state.ch[5 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + state.ch[4 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + state.ch[3 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + state.ch[2 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + state.ch[1 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + state.ch[0 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + state.ch[7 * 8 + 0]];
			L[7] = (K.ll[7] = L[7]) ^
				g_whirpool_c[0 * 256 + state.ch[7 * 8 + 7]] ^
				g_whirpool_c[1 * 256 + state.ch[6 * 8 + 6]] ^
				g_whirpool_c[2 * 256 + state.ch[5 * 8 + 5]] ^
				g_whirpool_c[3 * 256 + state.ch[4 * 8 + 4]] ^
				g_whirpool_c[4 * 256 + state.ch[3 * 8 + 3]] ^
				g_whirpool_c[5 * 256 + state.ch[2 * 8 + 2]] ^
				g_whirpool_c[6 * 256 + state.ch[1 * 8 + 1]] ^
				g_whirpool_c[7 * 256 + state.ch[0 * 8 + 0]];

			ft_memcpy(state.ll, L, sizeof(L));
		} while (++r < 10);

		i = 0; do digest[i] ^= L[i] ^ (block)[i]; while (++i < 8);
	}
}

static uint64_t	hashmultipleblocks(WHIRLPOOL_CTX *const ctx,
		const uint64_t *input, uint64_t length)
{
	uint64_t* dataBuf = ctx->data;
	do
	{
#if BYTE_ORDER == BIG_ENDIAN
		WhirlpoolTransform(ctx->state, input);
#else
		correctendianess(dataBuf, input, 64);
		whirlpooltransform(ctx->state, dataBuf);
#endif
		input += 8;
		length -= 64;
	}
	while (length >= 64);
	return length;
}

void WHIRLPOOL_init(WHIRLPOOL_CTX *const ctx) {
	ctx->countHi = 0;
	ctx->countLo = 0;
	ft_memset (ctx->data, 0, 8 * sizeof(uint64_t));
	ft_memset (ctx->state, 0, 8 * sizeof(uint64_t));
}

void WHIRLPOOL_add(const unsigned char * input, uint32_t sourcebytes,
		WHIRLPOOL_CTX *const ctx)
{
	return ;
}

void WHIRLPOOL_finalize(WHIRLPOOL_CTX *const ctx, unsigned char *result)
{
	return ;
}

void			whirpool(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	uint64_t	*res;
	int			index;

	index = -1;
	res = NULL;
	while (++index < ssl->size_printed)
	{
		if (ssl->to_hash[index] != NULL)
			;
	}
	return ;
}
