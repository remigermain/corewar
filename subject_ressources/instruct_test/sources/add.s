.name	"add instruct"
.comment "yo bitch !"

	add	r1, r2, r3  # number player + 0 to registre 3
	st	r3, 50
	
	ld	%50,	r2
	add	r1, r2, r3  # number player + 50 to registre 3
	st	r3, 50

	add	r4, r6, r3  # 0 + 0 to registre 3
	st	r3, 400

	zjmp	%500  # cary
