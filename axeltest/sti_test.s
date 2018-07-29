.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
ld %5, r6
#ld %2000000, r6
#sti r6, %1500000000, %5
#sti r6, %1700000000, r3
#sti r6, %5, r3

#sti r6, %5, %1000000000
#sti r6, 5000000000, r3
#sti r6, 50, %7
#sti r6, 50, %7000000
#sti r6, r2, r3
#sti r6, r2, %12
#sti r6, r2, %2050000000
#and r2, r6, r2

#live:
#live %1
#zjmp %:live
