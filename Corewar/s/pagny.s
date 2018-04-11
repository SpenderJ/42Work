.name "Pagny comme le chanteur"
.comment "just a expert living prog"

l2: and r1,%0,r1
and r1,%0,r1
sti r1,%:live,%1
fork %1
live:   live    %1
zjmp    %:live
aff r0
aff r1
