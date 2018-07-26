.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
sti	r1, %:live, %1			;change live by the right value
ld %0, r4

live:
live %1
zjmp %:live
