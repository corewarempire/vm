.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
# R, R

ld	%-1, r1
or r1, r1, r1
ldi r1, r1, r1

ld %-100, r1
or r1, r1, r1
ldi r1, r1, r1

ld %-4685687123, r2
or r2, r1, r13
ldi r13, r13, r13

ld %1, r2
or r2, r1, r13
ldi r13, r13, r13

ld %1512182432122, r2
or r2, r2, r13
ldi r13, r13, r13

ld %1512182432122, r2
or r2, r13, r13
ldi r13, r13, r13

# R, IND

label:

ld %1, r2
or r2, 0, r13
ldi r13, r13, r13

ld %1, r2
or r2, 12568, r13
ldi r13, r13, r13

ld %123, r2
or r2, 135765413216854, r13
ldi r13, r13, r13

ld %-57, r2
or r2, -15641, r13
ldi r13, r13, r13

ld %16484560135, r2
or r2, :label, r13
ldi r13, r13, r13

ld %0, r2
or r2, -68745312123, r13
ldi r13, r13, r13

# R, DI

ld %1, r2
or r2, %0, r13
ldi r13, r13, r13

ld %1, r2
or r2, %12568, r13
ldi r13, r13, r13

ld %123, r2
or r2, %135765413216854, r13
ldi r13, r13, r13

ld %-57, r2
or r2, %-15641, r13
ldi r13, r13, r13

ld %16484560135, r2
or r2, :label, r13
ldi r13, r13, r13

ld %0, r2
or r2, %-68745312123, r13
ldi r13, r13, r13


# DI, R

ld %1, r2
or %0, r2, r13
ldi r13, r13, r13

ld %1, r2
or %12568, r2, r13
ldi r13, r13, r13

ld %123, r2
or %135765413216854, r2, r13
ldi r13, r13, r13

ld %-57, r2
or %-15641, r2, r13
ldi r13, r13, r13

ld %16484560135, r2
or :label, r2, r13
ldi r13, r13, r13

ld %0, r2
or %-68745312123, r2, r13
ldi r13, r13, r13
