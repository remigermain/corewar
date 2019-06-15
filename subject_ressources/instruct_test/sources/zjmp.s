.name	"zjmp instruct"
.comment "yo bitch !"

	ld	%0,	r2
	zjmp	%:la		#carry
	live	%55
la:
	
	ldi	%0,	%0, r2
	zjmp	%:la1		#carry
	live	%55
la1:

	add	r2, r2, r3
	zjmp	%:la2		#carry
	live	%55
la2:

	sub	r2, r2, r3
	ld	%0,	r2
	zjmp	%:la3		#carry
	live	%55
la3:

	and	r2, r2, r3
	ld	%0,	r2
	zjmp	%:la4		#carry
	live	%55
la4:

	or	r2, r2, r3
	ld	%0,	r2
	zjmp	%:la5		#carry
	live	%55
la5:

	xor	r2, r2, r3
	zjmp	%:la6		#carry
	live	%55
la6:

