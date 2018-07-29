.name "test1"
.comment "test1"

# ERREURS :
#
#	- zjmp
#	- fork
#	- lfork
#	- aff
#



bonjour:

st		r1,		-0
live	%0
ld		5,		r2
ld		%0,		r1
#zjmp	%111111111111111111111111111111111
lld		%555555111151315351351351,		r1
lld		5,		r5
#fork   %55555555555555
#fork	%5
#lfork	%5

test:
