.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value

lld %5, r6
and r6, r6, r6
lld %5, r6
and r6, r6, r6
lld %5000000000, r6
and r6, r6, r6
lld 5, r6
and r2, r6, r6
lld -100, r6
and r7, r6, r6
