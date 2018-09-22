.name "xor test"
.comment ""

xor r1, r7, r10
zjmp 
and r10, r11, r12
st r12, 120
or r10, r11, r12
st r12, 140
