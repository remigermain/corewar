.name	"lld instruct"
.comment "yo bitch !"

	lld	0,	r2			
	st	r2,	50

	lld	513, r2			#Adressage Restreint
	st	r2,	50

	lld	-513, r2		#Adressage Restreint
	st	r2,	50

	lld	%4294967295, r4  	#ff ff ff ff
	st	r4,	200

	lld	%0,	r2
	zjmp	%500		#carry

