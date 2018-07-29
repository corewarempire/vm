.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
		;change live by the right value
ld %17, r1
ld %1, r5
ld %6, r7
add	r5, r7, r16
ldi r5, r7, r13
ldi r16, r16, r16

ld %15, r3
add r3, r3, r16
ldi r3, r3, r13
ldi r16, r16, r16
ld %17000, r3
add r3, r5, r16
ldi r3, r5, r13
ldi r16, r16, r16
ld %-1, r6
add r3, r6, r16
ldi r3, r6, r13
ldi r16, r16, r16
ld %-2000000000, r6
add r6, r1, r16
ldi r6, r1, r13
ldi r16, r16, r16
ld %-4000000000, r6
add r6, r16, r16
ldi r6, r16, r13
ldi r16, r16, r16
ld %1500000000, r6
add r1, r1, r16
ldi r1, r1, r13
ldi r16, r16, r16
ld %4000000000, r6
add r6, r1, r16
ldi r6, r1, r13
ldi r16, r16, r16

ld 1, r5
add	r5, r1, r16
ldi r5, r1, r13
ldi r16, r16, r16
ld 15, r3
add r3, r3, r16
ldi r3, r3, r13
ldi r16, r16, r16
ld 17000, r3
add r3, r5, r16
ldi r3, r5, r13
ldi r16, r16, r16
ld -1, r6
add r3, r6, r16
ldi r3, r6, r13
ldi r16, r16, r16
ld -2000000000, r6
add r6, r1, r16
ldi r6, r1, r13
ldi r16, r16, r16
ld -4000000000, r6
add r6, r16, r16
ldi r6, r16, r13
ldi r16, r16, r16
ld 1500000000, r6
add r1, r1, r16
ldi r1, r1, r13
ldi r16, r16, r16
ld 4000000000, r6
add r6, r1, r16
ldi r6, r1, r13
ldi r16, r16, r16
#live:
#live %1
#zjmp %:live
