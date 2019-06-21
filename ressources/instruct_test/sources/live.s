.name	"live instruct"
.comment "yo bitch !"

live:
	live	%-2147483647
	live	%-1
	live	%1
	live	%0
	ld		%0, r2
	zjmp %:live

