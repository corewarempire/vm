.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
#ld %200, r6
ld %1, r5
lldi r6, %15, r3
lldi r6, %17000, r3
lldi r6, r4, r3
lldi r6, r5, r4
lldi r6, r4, r4
lldi r6, %5, r3
lldi %5, %10, r4
lldi %5, %10, r2
lldi %2000000000, %10, r2
lldi %20000000000, %10, r2
lldi %-5, %10, r2
lldi %-5, %-10, r2
lldi %-5, %1000000000000, r2
lldi r6, %5, r3
lldi 50, %5, r2
lldi 2500, %5, r7
lldi -5000, %-5, r4
lldi 5, %10, r4
lldi r6, %5000000000, r3

lldi 50000000002, r5, r2
#and r2, r2, r2


lldi 2500, r5, r5
lldi -5000, r5, r4
lldi -5, r2, r4
lldi r6, %50, r3
lldi r2, r6, r2
lldi r2, r6, r2

#live:
#live %1
#zjmp %:live
