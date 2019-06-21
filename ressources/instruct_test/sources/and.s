.name	"amd instruct"
.comment "yo bitch !"


## registre
	and	r1, r2, r3
	st	r3, 500		# so is zero
	
	ld	%50,	r2
	and	r1, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
##	dir et reg
	ld	%50,	r2
	and	%5000, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
	ld	%50,	r2
	and	%5000, %9999, r3  # number player & 50 to registre 3
	st	r3, 500


	ld	%50,	r2
	and	%9999, %5000, r3  # number player & 50 to registre 3
	st	r3, 500

##	reg et indirect
	
	ld	%50,	r2
	and	5000, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
	ld	%50,	r2
	and	r2, 5000, r3  # number player & 50 to registre 3
	st	r3, 500
	
	ld	%50,	r2
	and	5000, 9999, r3  # number player & 50 to registre 3
	st	r3, 500

##	dir et indirect
	
	ld	%50,	r2
	and	-12, %40, r3  # number player & 50 to registre 3
	st	r3, 500
	
	ld	%50,	r2
	and	%500, -15, r3  # number player & 50 to registre 3
	st	r3, 500
	



	and	r4, r6, r3  	#carry
	st	r3, 400
	zjmp	%500
