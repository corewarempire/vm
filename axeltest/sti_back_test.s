.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"


#sti r1, -5, %-150
ld %-1, r6
sti r6, -5, %-150
# Test avec registre neg
# ld %-18, r6
# sti r2, r6, %0
# Test avec grand registre neg
# ld %-500, r6
# sti r2, r6, %0
# Test avec registre pos
# ld %5, r6
# sti r2, r6, %0
# Test avec grand direct pos registre
# ld %5000000000, r6
# sti r2, r6, %0
# Test avec indirect
# sti r2, 0, %0
# Test avec grand indirect
# sti r2, -5, %0

# Faux vrai test
# sti r2, -25, %-150
# sti r2, r5, %-1500000000000000 # a priori faux 
# sti r2, -50, %-150
