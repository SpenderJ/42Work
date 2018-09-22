.name "test carry"
.comment "tests carry"

## carry initial -> 0 
	zjmp %486451553184

## carry reste -> 0 : live ne modifie pas le carry 
	live %-1
	zjmp %-2115318541531183415552451

## carry -> 1 : ld passe le carry a 1 si son 1er paramètre est zéro 
	ld %0, r5
	zjmp %3

## carry reste -> 1 : st ne modifie pas le carry
	st r1, r8
	zjmp %3
	st r2, 300
	zjmp %3
	st r0, 155
	zjmp %3

## carry -> 0 : ld passe le carry a 0 si son 1er parametre est different de zéro
	ld %42, r3
	zjmp %3
	live %-1
	zjmp %3

## carry reste -> 0 : and, or, xor, add, sub mettent le carry a zéro si le résultat de l'opération sur les deux 1ers paramètres est différent de zéro 
	and r1, r3, r4
	zjmp %3
	and r3, r4, r5
	zjmp %3
	or r3, r4, r6
	zjmp %3
	xor r1, r7, r10
	zjmp %3
	add r3, r4, r9
	zjmp %3
	sub r1, r4, r8
	zjmp %3
	
## carry -> 1 : and, or, xor, add, sub mettent le carry a zéro si le résultat de l'opération sur les deux 1ers paramètre est zéro
	xor r3, r4, r7
	zjmp %3

## carry reste -> 1
	sub r3, r4, r8
	zjmp %3
	and r10, r11, r12
	zjmp %3
	st r7, 100
	zjmp %3
	st r8, 100

## carry -> 0

	ld %1415681555534152, r6
	zjmp %3
	add r4, r5, r10
	zjmp %3
	or r4, r5, r11
	zjmp %3
	xor r4, r15, r12
	zjmp %3

## carry reste -> 0 : pas de modification du carry pour sti et ldi
	ldi r2, r4, r2 
	zjmp %3
	live %-1
	ldi %0, r4, r3 
	zjmp %3
	ldi %0, %0, r4 
	zjmp %3
	ldi %42, %-42, r5 
	zjmp %3
	ldi %4186415057412, %-1451541114710, r6 
	zjmp %3
	ldi -152, r4, r7 
	zjmp %3
	ldi -5663224125, r4, r8 
	zjmp %3
	sti r2, r4, r2 
	zjmp %3
	sti r3, r16, r3 
	zjmp %3
	sti r4, r4, %0
	zjmp %3
	sti r5, %42596, %-42596
	zjmp %3
	sti r6, %-365214832, r15
	zjmp %3
	sti r7, -1, %121212
	zjmp %3
	sti r8, 14, %-14
	zjmp %3

## carry -> 1
	and r16, r4, r16
	zjmp %3

## carry reste -> 1
	ldi r2, r4, r2 
	zjmp %3
	live %-1
	ldi %0, r4, r3 
	zjmp %3
	ldi %0, %0, r4 
	zjmp %3
	ldi %42, %-42, r5 
	zjmp %3
	ldi %4186415057412, %-1451541114710, r6 
	zjmp %3
	ldi -152, r4, r7 
	zjmp %3
	ldi -5663224125, r4, r8 
	zjmp %3
	sti r2, r4, r2 
	zjmp %3
	sti r3, r16, r3 
	zjmp %3

## carry -> 0 : lld passe le carry a zéro si son premier paramètre est différent de zéro
	lld %12, r14
	zjmp %3

## carry reste -> 0
	lld %1864815, r14
	zjmp %3
	lld %-164183548, r14
	zjmp %3
	lld %543, r14
	zjmp %3
	lld %12, r14
	zjmp %3

## carry -> 1 : lld passe le carry a 1 si son premier paramètre est zéro
	lld %0, r14
	zjmp %3

## carry reste -> 0 : lldi passe le carry a 1 si le résultat stocké est égal a zéro
	lldi r12, r13, r14
	zjmp %3
	lldi %0, %0, r14
	zjmp %3
	lldi 151, r13, r14
	zjmp %3
	lldi 15632894, %0, r14
	zjmp %3

## carry -> 1 : lldi passe le carry a 0 si le résultat stocké est différent de zéro
##	lldi %15, %21, r14
##	zjmp %3


































