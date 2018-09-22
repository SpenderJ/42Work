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
##	st r1, r8
	zjmp %3
	zjmp %3
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
##	st r1, 280
##	st r7, 300
	xor r1, r7, r10
##	st r10, 200 Good here
	zjmp %3
	st r10, 180
	add r3, r4, r9
	st r10, 200
	zjmp %3
	sub r1, r4, r8
	zjmp %3
##	st r10, 200 not good 
## carry -> 1 : and, or, xor, add, sub mettent le carry a zéro si le résultat de l'opération sur les deux 1ers paramètre est zéro
	xor r3, r4, r7
	zjmp %3

## carry reste -> 1
	sub r3, r4, r8
	zjmp %3
	st r10, 220
##	st r11, 240
	and r10, r11, r12
##	st r12, 260
