.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
ld %5, r4
ld %6, r5
add r4, r5, r6

#live:
#live %1
#zjmp %:live
