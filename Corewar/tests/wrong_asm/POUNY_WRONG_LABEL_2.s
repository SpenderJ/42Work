.name "Pouny"
.comment "just a expert living prog"

l2: sti r1,%:live,%1
and r1,%0,r1
aff r0
aff r0
aff r0
aff r0
aff r0
fork %1
livee:   live    %1 #wrong
zjmp    %:live
