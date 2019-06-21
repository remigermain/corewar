#!/bin/bash

score='0';
check='0';

	usage()
	{
		nb_arg="$#";
		extension=`echo $1 | grep -c ".cor"`
		if [ $# -ne 1 ]; then
			echo "Usage : sh test.sh <champ_to_train_against.cor>";
		elif [ $extension -ne 1 ]; then
			echo "Error : Your champion must have \".cor\" extension.";
		elif [ ! -f "$1" ]; then
			echo "Error : File doesn't exist !";
			exit;
		fi
	}

	# launch game until a random player can beat $1
	launch_game()
	{
		sh script/champion_generator.sh >> /dev/null;
		haystack=`./ressources/original_corewar -a $1 -a ressources/compile/Randomize_Commodore.cor`;
		score=`echo $haystack | grep -c "\"Randomize Commodore\", has won"`
	
	}

	# check if random_champ can beat basic champion
	checker()
	{
		check='0';
		haystack=`./ressources/original_corewar -a $1 -a ressources/compile/zork.cor`;
		v1=`echo $haystack | grep -c "\"Randomize Commodore\", has won"`
		haystack=`./ressources/original_corewar -a $1 -a ressources/compile/helltrain.cor`;
		v2=`echo $haystack | grep -c "\"Randomize Commodore\", has won"`
		haystack=`./ressources/original_corewar -a $1 -a ressources/compile/Octobre_Rouge_V4.2.cor`;
		v3=`echo $haystack | grep -c "\"Randomize Commodore\", has won"`
		haystack=`./ressources/original_corewar -a $1 -a ressources/compile/Gagnant.cor`;
		v4=`echo $haystack | grep -c "\"Randomize Commodore\", has won"`
		echo "zork : $v1 || helltrain : $v2 || octobre : $v3 || gagnant : $v4";
		if [ $v1 -eq 1 -a $v2 -eq 1 -a $v3 -eq 1 -a $v4 -eq 1 ]; then
			sed -i -e '1s/Randomize Commodore/Darwin/g' ressources/sources/Randomize_Commodore.s;
			sed -i -e "2s/I'm the result of hasard, what could you do against that ?/I evolved to kick your ass !/g" ressources/sources/Randomize_Commodore.s
			mv ressources/compile/Randomize_Commodore.cor ressources/compile/Darwin.cor;
			mv ressources/sources/Randomize_Commodore.s ressources/compile/Darwin.s;
			check='1';
		fi
	}

	usage $1;
	if [ ! -f "asm" ]; then
		make;
	fi
	if [ $nb_arg -eq 1 -a $extension -eq 1 ]; then
		while [ $check -eq 0 ]; do
			launch_game $1;
			if [ $score -eq 1 ]; then
				checker ressources/compile/Randomize_Commodore.cor;
			fi
		done;
		echo "A better champion has been created !";
	fi
