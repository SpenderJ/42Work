.name "and"
.comment ""

and %123, %54335, r3
zjmp %3
st r3, 100
and r1, r3, r4
zjmp %3
st r4, 120
and %0, %0, r5
zjmp %3
st r5, 140
and r5, r6, r7
zjmp %3
st r7, 160
