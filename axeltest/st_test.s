.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value


ld %-1, r6
# st r6, r3
# st r6, r4
# st r6, r5
st r6, 70000
st r2, 50000
st r3, 60000
st r6, 70000000000
st r16, 500000000000
st r2, 5000000
st r6, 50000000000000

#live:
#live %1
#zjmp %:live
