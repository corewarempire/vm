.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"

# DI, DI
ld %1, r2
and %0, %150, r13
ldi r13, r13, r13

label:

ld %1, r2
and %12568, %150000000000000, r13
ldi r13, r13, r13

ld %123, r2
and %135765413216854, %1, r13
ldi r13, r13, r13

ld %-57, r2
and %-15641, %-1, r13
ldi r13, r13, r13

ld %16484560135, r2
and :label, %0, r13
ldi r13, r13, r13

ld %0, r2
and %-68745312123, %1, r13
ldi r13, r13, r13

# DI, IND

ld %1, r2
and %0, 150, r13
ldi r13, r13, r13

ld %1, r2
and %12568, 150000000000000, r13
ldi r13, r13, r13

ld %123, r2
and %135765413216854, 1, r13
ldi r13, r13, r13

ld %-57, r2
and %-15641, -1, r13
ldi r13, r13, r13

ld %16484560135, r2
and :label, 0, r13
ldi r13, r13, r13

ld %0, r2
and %-68745312123, 1, r13
ldi r13, r13, r13

# IND, R
ld %1, r2
and 0, 150, r13
ldi r13, r13, r13

ld %1, r2
and 12568, r13, r13
ldi r13, r13, r13

ld %123, r2
and 135765413216854, r2, r13
ldi r13, r13, r13

ld %-57, r2
and -15641, r1, r13
ldi r13, r13, r13

ld %16484560135, r2
and :label, r1, r13
ldi r13, r13, r13

ld %0, r2
and -68745312123, r2, r13
ldi r13, r13, r13


# IND, DI,

ld %1, r2
and 0, %150, r13
ldi r13, r13, r13

ld %1, r2
and 12568, %13, r13
ldi r13, r13, r13

ld %123, r2
and 135765413216854, %-15683, r13
ldi r13, r13, r13

ld %-57, r2
and -15641, %68415320867, r13
ldi r13, r13, r13

ld %16484560135, r2
and :label, %-1, r13
ldi r13, r13, r13

ld %0, r2
and -68745312123, %1, r13
ldi r13, r13, r13

# IND, IND 

ld %1, r2
and 0, 150, r13
ldi r13, r13, r13

ld %1, r2
and 12568, 13, r13
ldi r13, r13, r13

ld %123, r2
and 135765413216854, -15683, r13
ldi r13, r13, r13

ld %-57, r2
and -15641, 68415320867, r13
ldi r13, r13, r13

ld %16484560135, r2
and :label, -1, r13
ldi r13, r13, r13

ld %0, r2
and -68745312123, 1, r13
ldi r13, r13, r13


