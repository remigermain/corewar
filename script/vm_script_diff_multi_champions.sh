#!/bin/bash

	define_compilation_line()
	{
			line="./corewar --diff -d $2 $5 $6 $7 $8";
			line2="./ressources/original_corewar -v 31 -d $2 $5 $6 $7 $8";
			b_line="./corewar --diff -d 1 $5 $6 $7 $8";
			b_line2="./ressources/original_corewar -v 31 -d 1 $5 $6 $7 $8";
			m_test="./ressources/original_corewar -v 31 -d 500000 $5 $6 $7 $8";
			m_now="./ressources/original_corewar -v 31 -d $3 $5 $6 $7 $8";
	}

	display_diff()
	{
		COUNTER=$2;
		echo "[ START ]\n"
		$b_line > .diff_core;
		$b_line2 > .diff_oricore;
		BASE=`diff .diff_core .diff_oricore | wc -l | bc`
		echo "diff is $BASE\n"
		bla=$2;
		while [ $bla -lt $3 ]
		do
			define_compilation_line $1 $bla $3 $4 $5 $6 $7 $8;
			$line > .diff_core;
			$line2 > .diff_oricore;
			MED=`diff .diff_core .diff_oricore | wc -l | bc`
			echo "\033[1A\c"
			echo "cycles : "${COUNTER}
			if [[ ${MED} -ne 0 ]]
			then
				COUCOU=`diff $m_test .diff_oricore | wc -l | bc`;
				if [[ $COUCOU -ne 0 ]]; then
					echo "[ ENDING ]\n[ KO ]";
					diff .diff_core .diff_oricore
				else
					echo "[ ENDING ]\nzaz vm ending !\n[ OK ]";
				fi
				exit
			fi
			FINI=`tail .diff_oricore | grep "won" | wc -l`
			FINI2=`tail .diff_core | grep "won" | wc -l`
			if [ $FINI -eq 1 -a $FINI2 -eq 1 ]; then
				echo "[ ENDING ]\nNo differences were found !\n[ OK ]";
				rm -rf .diff_core .diff_oricore
				exit
			fi
			(( bla+=$4 ))
			(( COUNTER+=$4 ))
		done
		echo "[ ENDING ]\n[ OK ]\ncycles : "${COUNTER}
		rm -rf .diff_core .diff_oricore
	}

	if [ $# -lt 5 -o $# -gt 8 ]; then
		echo "Usage : sh script/vm_script_diff_multi_champions.sh <nb players> <cycle start> <cycle end> <dump slices> <player(s) path>";
		exit
	elif [ $1 -lt 1 -o $1 -gt 4 ]; then
		echo "Error : Number of player must be between 1 and 4";
		exit;
	elif [ ! -f "corewar" ]; then
		make;
	fi
	define_compilation_line $1 $2 $3 $4 $5 $6 $7 $8;
	display_diff $1 $2 $3 $4 $5 $6 $7 $8;
