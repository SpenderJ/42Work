.name "Pouny"
.comment "just a expert living prog"

l2: sti r1,%:live,%1
an_d r1,%0,r1   #and
aff r0
aff r0
aff r0
aff r0
aff r0
fork %1
live:   live    %1
zjmp    %:live
