.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value


#ld %5, r6
ld %2000000, r6

#st r6, r3
#and r6, r3, r1
#st r1, 5
#and r1, r1, r1
#st r6, 5000000000
#and r6, r6, r6
#st r6, 7000000
#st r17, 50000000


#live:
#live %1
#zjmp %:live
