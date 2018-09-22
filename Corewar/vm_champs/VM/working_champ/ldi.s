.name "zjmp!"
.comment "Test de l'instruction Jump en avant et en arriere"



	lldi 1, %685, r2
	lldi 0, %65, r5
	lldi 666666666, %688888888888888885, r2
	lldi %1, %68, r2
	lldi %-51, %685, r2
	lldi %547353545, %685, r2
	lldi r1, %685, r2
	lldi r10, %68354245, r2
	lldi r15, %66835685, r2

	lldi 1, r5, r1
	lldi 0, r0, r2
	lldi 666666666, r1, r3
	lldi %1, r3, r4
	lldi %-51, r12, r5
	lldi %547353545, r16, r6
	lldi r1, r4, r7
	lldi r0, r10, r8
	lldi r15, r6, r9

