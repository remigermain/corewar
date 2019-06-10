#!/bin/bash

score='0';

	usage()
	{
		extension=`echo $1 | grep -c ".cor"`
		if [ $nb_arg -ne 1 ]; then
			echo "Usage : sh test.sh <champ_to_beat.cor>";
			exit;
		elif [ $extension -ne 1 ]; then
			echo "Error : Your champion must have \".cor\" extension !";
			exit;
		elif [ ! -f "$1" ]; then
			echo "Error : File doesn't exist !";
			exit;
		fi
	}

	# launch game until a random player can beat $1
	launch_game()
	{
		sh script/champion_generator.sh "$2 Nemesis" "I'm sure to beat $2, that's a good start !" >> /dev/null;
		haystack=`./subject_ressources/original_corewar -a $1 -a subject_ressources/champs_total/compile/Randomize_Commodore.cor`;
		score=`echo $haystack | grep -c "\"$2 Nemesis\", has won"`
	}


	nb_arg="$#";
	usage $1;
	if [ ! -f "asm" ]; then
		make;
	fi
	if [ $# -eq 1 -a $extension -eq 1 ]; then
		name=`basename $1 | sed 's/.cor//'`;
		foo="$(tr '[:lower:]' '[:upper:]' <<< ${name:0:1})${name:1}"
		while [ $score -eq 0 ]; do
			launch_game $1 $foo;
		done;
				echo "Congratulations ! $foo Nemesis has been created !";
		foo2="$foo";
		foo+="_Nemesis.cor";
		foo2+="_Nemesis.s";
		mv subject_ressources/champs_total/compile/Randomize_Commodore.cor subject_ressources/champs_total/compile/$foo;
		mv subject_ressources/champs_total/sources/Randomize_Commodore.s subject_ressources/champs_total/sources/$foo2;
	fi
