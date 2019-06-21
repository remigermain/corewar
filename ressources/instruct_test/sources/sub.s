.name	"sub instruct"
.comment "yo bitch !"

	sub	r1, r2, r3  # number player - 0 to registre 3
	st	r3, 50
	
	ld	%50,	r2
	sub	r1, r2, r3  # number player - 50 to registre 3
	st	r3, 50
	
	
	sub	r1, r1, r3  # number player - number plauyer ( so is zero ) to registre 3
	st	r3, 200


	sub	r4, r6, r3  # 0 - 0 to registre 3
	st	r3, 400

	zjmp	%500			#carry





