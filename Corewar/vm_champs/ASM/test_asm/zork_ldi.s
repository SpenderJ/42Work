.name "zork_ldi"
.comment "testing ldi"

test:
	st		r2, 500
	ldi		%:beef, r2, r4
beef:
	live	%4242
