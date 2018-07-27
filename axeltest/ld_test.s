.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
ld 2, r4
ld %5, r5
#and r4, r5, r6
#and %10, r5, r6
#and 10, r5, r6
#and r4, 0, r6


#live:
#live %1
#zjmp %:live
