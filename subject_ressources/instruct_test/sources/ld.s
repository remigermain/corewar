.name	"ld instruct"
.comment "yo bitch !"

	ld	0,	r2			
	st	r2,	50

	ld	513, r2			#Adressage Restreint
	st	r2,	50

	ld	-513, r2		#Adressage Restreint
	st	r2,	50

	ld	%4294967295, r4  	#ff ff ff ff
	st	r4,	200

	ld	%0,	r2
	zjmp	%500		#carry

