.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
ld %5, r6
st r6, 10
and r2, r6, r2

#live:
#live %1
#zjmp %:live
