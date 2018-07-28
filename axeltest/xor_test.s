.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
ld %5, r4
ld %6, r5
xor r4, r5, r6
and r6, r5, r4
#live:
#live %1
#zjmp %:live
