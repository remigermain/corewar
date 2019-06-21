.name	"lldi instruct"
.comment "yo bitch !"


## registre
	lldi	r1, r2, r3
	st	r3, 500		# so is zero
	
	lldi	r1, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
##	dir et reg
	lldi	%5000, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
	lldi	%5000, %9999, r3  # number player & 50 to registre 3
	st	r3, 500


	lldi	%9999, %5000, r3  # number player & 50 to registre 3
	st	r3, 500

##	reg et indirect
	
	lldi	5000, r2, r3  # number player & 50 to registre 3
	st	r3, 500
	
	lldi	r2, %5000, r3  # number player & 50 to registre 3
	st	r3, 500
	
	lldi	5000, %9999, r3  # number player & 50 to registre 3
	st	r3, 500

##	dir et indirect
	
	lldi	-12, %40, r3  # number player & 50 to registre 3
	st	r3, 500
	
	lldi	%500, %-15, r3  # number player & 50 to registre 3
	st	r3, 500
	



	lldi	r4, r6, r3  	#carry
	st	r3, 400
	zjmp	%500
