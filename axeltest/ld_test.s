.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
#ld 2, r4
#ld %5, r5

st r1, -0
live %0
ld 5, r2
ld %0, r1
#and r4, r5, r6
#and %10, r5, r6
#and 10, r5, r6
#and r4, 0, r6


#live:
#live %1
#zjmp %:live
