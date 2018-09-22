.name "YOU SHALL NOT PASS"
.comment "defensive wall of nothing"

setup_live:
sti r1, %:creat_process, %1
sti r1, %:live_boucle, %1
sti r1, %:start, %1
sti r1, %:creat_process, %9
sti r1, %:restart, %7
sti r1, %:wall_1, %1
sti r1, %:start2, %1
sti r1, %:start2, %9

start:
live %0
ld %0, r2
fork %:start2

wall_1:
live %0
ld %0, r2
st r2, -24
st r2, -33
st r2, -42
st r2, -51
st r2, -60
st r2, -69
st r2, -78
st r2, -87
st r2, -96
st r2, -105
st r2, -114
st r2, -123
st r2, -132
st r2, -141
st r2, -150
st r2, -159
st r2, -168
st r2, -177
st r2, -186
st r2, -195
st r2, -204
st r2, -213
st r2, -222
st r2, -231
st r2, -240
st r2, -249
st r2, -258
st r2, -267
st r2, -276
st r2, -285
st r2, -294
st r2, -303
st r2, -312
st r2, -321
st r2, -330
st r2, -339
st r2, -348
st r2, -357
st r2, -366
st r2, -375
st r2, -384
st r2, -393
st r2, -402
st r2, -411
st r2, -420
zjmp %:wall_1

live_boucle:
live %0
ld %0, r16
zjmp %:live_boucle

start2:
live %0
fork %:wall_1
live %0
fork %:live_boucle

##creat_proc_prep:
##ld %0, r16
creat_process:
live %0
fork %:creat_process
live %0
fork %:start2

restart:
ld %0, r16
live %0
zjmp %:start
