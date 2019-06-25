# Corwar :heavy_check_mark: Loiberti - Rcepre - Rgermain 

Le Corewar est un jeu très particulier.
Il consiste à rassembler autour d’une "ma-chine virtuelle" des "joueurs",
lesquels vont y charger des "champions" qui vont sebattre à l’aide de processus,
dans le but, entre autres, de faire en sorte qu’on dise d'eux qu’ils sont "en vie".
Les processus s’exécutent séquentiellement au sein de la même machine virtuelle,
et du même espace mémoire. Ils peuvent donc, entre autre chose, s’écrire les un 
ssur les autres afin de se corrompre mutuellement, de forcer les autres à 
exécuterdes instructions qui leur font du mal, de tenter de recréer à la volée 
l’équivalent logiciel d’unCôtes du Rhône 1982, etc ...
Le jeu se termine quand plus aucun processus n’est en vie. 
À ce moment là, legagnant est le dernier joueur à avoir été rapporté comme étant
"en vie".II.2  Découpage du projetLe projet consiste à rendre trois parties 
distinctes :


1.  L’assembleur: C’est le programme qui va compiler vos champions et les
    traduire du langage dans lequel vous allez les écrire (l’assembleur) 
    vers un "bytecode", à savoir un code machine qui sera directement interprété
    par la machine virtuelle.
2.  La machine virtuelle: C’est l’"arène" dans laquelle les champions vont 
    s’exécuter. 
    Elle offre de nombreuses fonctionnalités, toutes utiles au combat des 
    cham-pions. Il va de soi qu’elle permet d’exécuter plusieurs processus en 
    simultané ; onvous demande une arène, pas unsimulateur de one-man show.
3.  Le champion: il est ecrit en langage assembleur, est compileé par le 
    programme asm, et peut etre lanceé par la VM de corewar.

<br />
<img src="https://i.imgur.com/ZkxLhCo.jpg" />
Original screen made in sdl2.

![](https://gitlab.com/rcepre/corewar/raw/master/pictures/cw3.png)

![](https://gitlab.com/rcepre/corewar/raw/master/pictures/cw4.png)

Handling clang-like errors of the asm, and verbose mode:

![](https://gitlab.com/rcepre/corewar/raw/master/pictures/asm_pict.png)

Verbose of the VM: 

![](https://gitlab.com/rcepre/corewar/raw/master/pictures/verbsoe.png)

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