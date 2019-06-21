.name	"ldi instruct"
.comment "yo bitch !"


## registre
	ldi	r1, r2, r3
	st	r3, 500		# so is zero
	
	ldi	r1, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
##	dir et reg
	ldi	%5000, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
	ldi	%5000, %9999, r3  # number player & 50 to registre 3
	st	r3, 500


	ldi	%9999, %5000, r3  # number player & 50 to registre 3
	st	r3, 500

##	reg et indirect
	
	ldi	5000, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
	ldi	r2, %5000, r3  # number player & 50 to registre 3
	st	r3, 500
	
	ldi	5000, %9999, r3  # number player & 50 to registre 3
	st	r3, 500

##	dir et indirect
	
	ldi	-12, %40, r3  # number player & 50 to registre 3
	st	r3, 500
	
	ldi	%500, %-15, r3  # number player & 50 to registre 3
	st	r3, 500
	



	ldi	r4, r6, r3  	#carry
	st	r3, 400
	zjmp	%500
