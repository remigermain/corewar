# Corewar



https://user-images.githubusercontent.com/66946113/138447893-bc6b397b-a8ec-483e-a07e-d7c47ae5de72.mp4




### :heavy_check_mark: Loiberti - Rcepre - Rgermain

Corewar is a very particular game.
It consists in gathering around a "virtual machine" of "players",
who will load "champions" who will fight with the help of processes,
in order, among other things, to make sure that they are said to be "alive".
The processes run sequentially within the same virtual machine
and the same memory space. They can therefore, among other things, write to each other in order to
on each other in order to corrupt each other, to force each other to
instructions that harm them, to try to recreate on the fly the software equivalent of a
the software equivalent of a 1982 Côtes du Rhône, etc ...
The game ends when no process is left alive.
At this point, the winner is the last player to have been reported as "alive".
"II.2 Breakdown of the projectThe project consists in making three distinct parts
distinct:

1.  The assembler: This is the program that will compile your champions and
    translate them from the language in which you will write them (the assembler)
    to a "bytecode", that is to say a machine code which will be directly interpreted
    by the virtual machine.
2.  The virtual machine: This is the "arena" in which the champions will run.
    run.
    It offers many functionalities, all useful to the combat of the
    cham-pions.
3.  The champion: it is written in assembly language, is compiled by the
    program, and can be launched by the corewar VM.

<br />
<img src="/readme_img/corewar.jpg" />
Original screen made in sdl2.

![corewar](/readme_img/corewar2.png)

![corewar](/readme_img/corewar3.png)

Handling clang-like errors of the asm, and verbose mode:

![asm](/readme_img/asm_pict.png)

Verbose of the VM:

![verbose](/readme_img/verbose_vm.png)

### You need

```bash
#for linux
dnf install SDL2-devel SDL2_ttf-devel SDL2_mixer-devel

#for macos you need brew in your home ( .brew )
brew install SDL2 SDL2_ttf SDL2_mixer

```

#### Usage corewar

```
usage : ./corewar [ -flags ] -p [ -n <number> ] <champion.cor> ...

 [ -flags ]
  	--visu	 (-V)			:  Visual made in SDL2.

	[ visu flags ]
	--screen			:  Change screen resolution (1080 or 4k).
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

 [ -champion ]
	--player (-p)   <Number>	:  Set champion, <Number> for set number to player.
			(Default is UNSIGNED INT MAX less the numbers of player)

 [ -visu events ]
	m   : turn ON/OFF music (when turn ON speed is limited to 1).
	+/- : inscrease/decrease speed.
	r   : switch to responsive mode.
	p   : change background ( only with fullscreen mode ).
	s   : step mode.
	esc : quit sdl.

Corewar © 2019 le-101 Loiberti - Rcepre - Rgermain
```

#### usage assembler

```
usage : ./asm [-flags] <champion.s>

[ -flags ]
	--verbose (-v) :  Print compilation information.
	--output  (-o) :  Define the output name.
	--help    (-h) :  Print this Help.
Corewar	© 2019 le-101   Loiberti - Rcepre - Rgermain
```

#### Usage de-assembler

```
Usage: ./dsm [ -flags ] <champions.cor>

 [ -flags ]
	--labels (l)	Disassembly with labels.
	--hexa (h)	Print hex values for eachs intructions.
				ex: for `DIR = %436432209` ->  #1A 03 70 06

	--help		Display help

corewar © 2019 le-101  Loiberti - Rcepre - Rgermain
```

#### Scripts

you have many scripts, generate random champions, diff verbse with zaz's vm ...

#### Helper

```
corewar © 2019 le-101  Loiberti - Rcepre - Rgermain
```

## Credits :fr:

This Corewar mad by Loiberti - Rcepre - Rgermain , for le-101 shool's projects
