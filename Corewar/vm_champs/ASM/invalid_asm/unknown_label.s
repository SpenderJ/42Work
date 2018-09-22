.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:toto, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
