#!/bin/bash

	define_compilation_line()
	{
		if [ $1 -eq 1 ]; then
			line="./corewar -d $2 $5";
			line2="./subject_ressources/original_corewar -d $2 $5";
			b_line="./corewar -d 1 $5";
			b_line2="./subject_ressources/original_corewar -d 1 $5";
			m_test="./subject_ressources/original_corewar -d 500000 $5";
			m_now="./subject_ressources/original_corewar -d $3 $5";
		elif [ $1 -eq 2 ]; then
			line="./corewar -d $2 $5 $6";
			line3="./subject_ressources/original_corewar -d $2 $5 $6";
			b_line="./corewar -d 1 $5 $6";
			b_line2="./subject_ressources/original_corewar -d 1 $5 $6";
			m_test="./subject_ressources/original_corewar -d 500000 $5 $6";
			m_now="./subject_ressources/original_corewar -d $3 $5 $6";
		elif [ $1 -eq 3 ]; then
			line="./corewar -d $2 $5 $6 $7";
			line2="./subject_ressources/original_corewar -d $2 $5 $6 $7";
			b_line="./corewar -d 1 $5 $6 $7";
			b_line2="./subject_ressources/original_corewar -d 1 $5 $6 $7";
			m_test="./subject_ressources/original_corewar -d 500000 $5 $6 $7";
			m_now="./subject_ressources/original_corewar -d $3 $5 $6 $7";
		elif [ $1 -eq 4 ]; then
			line="./corewar -d $2 $5 $6 $7 $8";
			line2="./subject_ressources/original_corewar -d $2 $5 $6 $7 $8";
			b_line="./corewar -d 1 $5 $6 $7 $8";
			b_line2="./subject_ressources/original_corewar -d 1 $5 $6 $7 $8";
			m_test="./subject_ressources/original_corewar -d 500000 $5 $6 $7 $8";
			m_now="./subject_ressources/original_corewar -d $3 $5 $6 $7 $8";
		fi
	}

	display_diff()
	{
		COUNTER=1;
		echo "[ START ]\n"
		$b_line > .diff_oricore;
		$b_line2 > .diff_core;
		BASE=`diff .diff_core .diff_oricore | wc -l | bc`
		echo "diff is $BASE\n"
		bla=$2;
		while [ $bla -lt $3 ]
		do
			define_compilation_line $1 $bla $3 $4 $5 $6 $7 $8;
			$line > .diff_oricore;
			$line2 > .diff_core;
			MED=`diff .diff_core .diff_oricore | wc -l | bc`
			echo "\033[1A\c"
			echo "count = "${COUNTER}
			if [[ ${MED} -ne $BASE ]]
			then
				$m_test > .diff_oricore;
				TEST=`cat .diff_oricore`;
				$m_now > .diff_core;
				NOW=`cat .diff_core`;
				if [ ${TEST} -ne ${NOW} ]
				then
					echo "[ ENDING ]\n[ KO ]count = "${COUNTER}
					diff .diff_core .diff_oricore
				else
					echo "[ ENDING ]\nzaz vm ending !\n[ OK ]count = "${COUNTER}
				fi
				exit
			fi
			(( bla+=$4 ))
			(( COUNTER+=1 ))
		done
		echo "[ ENDING ]\n[ OK ]\ncount = "${COUNTER}
		rm -rf .diff_core .diff_oricore
	}

	if [ $# -lt 5 -o $# -gt 8 ]; then
		echo "coucou";
		exit;
	elif [ $1 -lt 1 -o $1 -gt 4 ]; then
		echo "usage";
		exit;
	fi

	define_compilation_line $1 $2 $3 $4 $5 $6 $7 $8;
	display_diff $1 $2 $3 $4 $5 $6 $7 $8;
