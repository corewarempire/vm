.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
ld %2000000, r6
ldi r6, %1500000000, r3
ldi r6, %17000, r3
#ldi r6, %5, r3

#ldi r6, %5, r3
#ldi r6, %5000000000, r3
#ldi r6, %50, r3
#ldi r6, 50, %7000000
#ldi r2, r6, r2
#ldi r2, r6, r2

#live:
#live %1
#zjmp %:live
