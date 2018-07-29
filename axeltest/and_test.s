.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
#ld %200, r6
ld %1, r5
add	r5, r1, r16
ld %15, r3
amd
ld %17000, r3
ld %-1, r6
ld %-2000000000, r6
ld %-4000000000, r6
ld %1500000000, r6
ld %4000000000, r6


ld 1, r5
ld 15, r3
ld 17000, r3
ld -1, r6
ld -2000000000, r6
ld -4000000000, r6
ld 1500000000, r6
ld 4000000000, r6
#live:
#live %1
#zjmp %:live
