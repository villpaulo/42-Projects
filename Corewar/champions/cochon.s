.name	"cochon"
.comment	""

sti	r1, %:cochon, %1
ld	%240, r2
ld	%159, r3
ld	%144, r4
ld	%183, r5
ld	%32, r6
ld	%10, r7
ld	%0, r8
cochon:
live %42
aff	r2
aff	r3
aff	r4
aff	r5
aff r6
aff	r2
aff	r3
aff	r4
aff	r5
aff r6
aff	r2
aff	r3
aff	r4
aff	r5
aff r6
aff	r2
aff	r3
aff	r4
aff	r5
aff r6
aff r7
zjmp	%:cochon
