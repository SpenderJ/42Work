.name "42"
.comment "is that a 42?"

		sti r1,%:live,%1		# writting programm id after live
		sti r1,%:live_fork,%1	# writting programm id after live_fork
		sti r1,%:front,%1		# writting programm id after front
		sti r1,%:back,%1		# writting programm id after back
		ld %1111638594,r2		# setting r2 to the value 0x42424242
		ld %0,r16				# setting the carry on 1
		fork %:live				# fork to live
live_fork:
		live %1					# live
		fork %:back				# fork to back

front:							# front label
		live %1					# live
		st r2,350				# writting 42424242
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350				# ... many times...
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350
		st r2,350				# it was borring ? no ? then we jump to the begin !
		zjmp %:front			# jump to front label

live:							# live label
		live %1					# live
		zjmp %:live				# jump to live

back:
		live %1					# live
		st r2,-400				# wrtting 42424242
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400				# ...
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400
		st r2,-400				# Ctrl + C / Ctrl + V ...
		zjmp %:back				# jump to the back label