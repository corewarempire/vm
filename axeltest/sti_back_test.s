.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
#sti	r1, %:live, %1			;change live by the right value
ld %-1, r6
ld %-150, r4
ld %-150, r5
#sti r6, %-5, %-150


#sti r6, -5, %-150
#sti r6, -5, %-1500000000000000


#sti r6, r5, %-150 # ca a  l'air ok 
sti r6, r5, %-1500000000000000 # a priori faux 
