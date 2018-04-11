.name "while_loop"
.comment "When a process becomes a Backward great grandpa"

		sti r1,%:live,%1	# setting the programm id after live
		sti r1,%:live2,%1	# setting the programm id after live2
		ld %6,r1			# setiing r1 to 6
		ld %1,r2			# setting r2 to 1

while:						# while label
		add r1,r2,r1		# add r2 to r1 (r1++)
		or %15,r1,r3

 # if r1 | 15 = 0 the carry is set to 0
# the first unsigned integer wich is a solution
# of the "equation" above is 0 and the second is 16
# at the beggining r1 = 6 so we need to increment r1
# ten times to set the carry to 1 else the carry is set to 0

live:						# live label
		live %1				# live
		zjmp %:endwhile		# jump to endwhile only if r1 = 16 (see above)
		fork %:while		# duplicate the process and create a new one at while
		ld %0,r3			# setting the carry to 0
		zjmp %:while		# jump to while
endwhile:					# endwhile label

live2:						# live2 label
		live %1				# live
		zjmp %:live			# jump to live label
	
# with this while the first process create 10 new process
# the second process 9
# the third 8
# ...
# and every process leave the while to live in the "live2 loop"
