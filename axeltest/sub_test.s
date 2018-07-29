.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
		;change live by the right value
ld %17, r1
ld %1, r5
ld %6, r7
sub	r5, r7, r16
ldi r5, r7, r13
ldi r16, r16, r16

ld %15, r3
sub r3, r3, r16
ldi r3, r3, r13
ldi r16, r16, r16

ld %17000, r3
sub r3, r5, r16
ldi r3, r5, r13
ldi r16, r16, r16

ld %-1, r6
sub r3, r6, r16
ldi r3, r6, r13
ldi r16, r16, r16

ld %-2000000000, r6
sub r6, r1, r16
ldi r6, r1, r13
ldi r16, r16, r16

ld %-4000000000, r6
sub r6, r16, r16
ldi r6, r16, r13
ldi r16, r16, r16

ld %1500000000, r6
sub r1, r1, r16
ldi r1, r1, r13
ldi r16, r16, r16

ld %4000000000, r6
sub r6, r1, r16
ldi r6, r1, r13
ldi r16, r16, r16

ld 1, r5
sub	r5, r1, r16
ldi r5, r1, r13
ldi r16, r16, r16

ld 15, r3
sub r3, r3, r16
ldi r3, r3, r13
ldi r16, r16, r16

ld 17000, r3
sub r3, r5, r16
ldi r3, r5, r13
ldi r16, r16, r16

ld -1, r6
sub r3, r6, r16
ldi r3, r6, r13
ldi r16, r16, r16

ld -2000000000, r6
sub r6, r1, r16
ldi r6, r1, r13
ldi r16, r16, r16

ld -4000000000, r6
sub r6, r16, r16
ldi r6, r16, r13
ldi r16, r16, r16

ld 1500000000, r6
sub r1, r1, r16
ldi r1, r1, r13
ldi r16, r16, r16

ld 4000000000, r6
sub r6, r1, r16
ldi r6, r1, r13
ldi r16, r16, r16

ld %0, r3
sub r3, r5, r16
ldi r3, r5, r13
ldi r16, r16, r16

ld -1, r6
sub r9, r6, r16
ldi r9, r6, r13
ldi r16, r16, r16

ld -2000000000, r6
sub r6, r9, r16
ldi r6, r9, r13
ldi r16, r16, r16

ld -4000000000, r6
sub r12, r12, r16
ldi r12, r12, r13
ldi r16, r16, r16

ld 1500000000, r6
sub r15, r1, r16
ldi r15, r1, r13
ldi r16, r16, r16

ld %0, r11
sub r6, r11, r16
ldi r6, r11, r13
ldi r16, r16, r16
