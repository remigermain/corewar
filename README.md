# Corwar :heavy_check_mark:
<br />
<img src="https://i.imgur.com/ZkxLhCo.jpg" height="700" width="1300">
original screen made in sdl2.

### You need
```
you need brew in your home ( .brew )
and install sdl2
    install sdl2_ttf
    install sdl2_mixer

```

#### usage corewar
```
usage : ./corewar [ -flags ] -p [ -n <number> ] <champion.cor>

 [ flags ]
  	--visu	 (-V)			:  Visual made in SDL2.

	[ visu flags ]
		--animation (-a)	:  Print annimation in start and end ( default is off ).
	--dump	 (-d)   <Number>	:  Dumps memory after <Number> cyles and exits.
	--color	 (-c)			:  Dumps with color player.
	--diff				:  Print verbose same as zaz's VM.
  	--verbose (-v)   <Number>	:  Print information , <Number> for verbose mode ( Default is 1 ).
		verbose mode :
				1 : print base
				2 : Print cycle_to_die
				4 : Print instruction
				8 : Print Kill process
				16 : Print pc mouvement

	--step	(-s)			:  Verbose step by step. ( default if off ).
	--aff	(-f)			:  print aff result in stdin ( in verbose is same as mode 4 ).

 [ champion ]
	--player (-p)   <Number>	:  Set champion, <Number> for set number to player.
			(Default is UNSIGNED INT MAX less the numbers of player)

 [ visu events ]
	m   : turn ON/OFF music (when turn ON speed is limited to 1).
	+/- : inscrease/decrease speed.
	r   : switch to responsive mode.
	p   : change background ( only with fullscreen mode ).
	esc : quit sdl.

Corewar © 2019 le-101 Loiberti - Rcepre - Rgermain
```

#### usage assembler
```
usage : ./asm [-flags] <champion.s>

[ flags ]
	--verbose (-v) :  Print compilation information.
	--output  (-o) :  Define the output name.
	--help    (-h) :  Print this Help.
Corewar	© 2019 le-101   Loiberti - Rcepre - Rgermain
```

#### usage de-assembler
```
Usage: ./dsm [ -flags ] <champions.cor>

 [ -flags ]
	--labels (l)	Disassembly with labels.
	--hexa (h)	Print hex values for eachs intructions.
				ex: for `DIR = %436432209` ->  #1A 03 70 06

	--help		Display help

corewar © 2019 le-101  Loiberti - Rcepre - Rgermain
```

#### Helper
```
corewar © 2019 le-101  Loiberti - Rcepre - Rgermain
````

 
 ## Credits :fr:
 
 This Corwar mad by Loiberti - Rcepre - Rgermain , for le-101 shool's projects