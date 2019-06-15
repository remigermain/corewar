#!/bin/bash

ERROR="0"

	function	run_test()
	{
	#	./corewar $1 -d $2 > .diff_core && ./subject_ressources/original_corewar $1 -d $2 > .diff_oricore
		./corewar --diff $1 -d $2 > .diff_core && ./subject_ressources/original_corewar -v 31 $1 -d $2 > .diff_oricore
		echo "[finish]"
		DIFF=`diff .diff_core .diff_oricore`
		DIFF_LINE=`diff .diff_core .diff_oricore | wc -l`
		if [[ ${DIFF_LINE} -ne 0 ]]
		then
			echo "[ KO is a diff ]"
			echo $DIFF
		else
			echo "[ OK no diff ]"
		fi
	}

if [[ $# -ne 2 ]]
then
	echo "You need 3 params\nscript <champion.cor> [ nb _cycle ]"
	exit;
fi

if ! [[ "$2" =~ ^[0-9]+$ ]]
then
	echo "your param 1 \"$1\" is not integers."
	ERROR="1"
fi

if [ ! -f "corewar" ]
then
	echo "Cant's find corewar"
	ERROR="1"
fi

if [ ! -f "subject_ressources/original_corewar" ]
then
	echo "Cant's find corewar"
	ERROR="1"
fi

if [ $ERROR -eq "1" ]
then
	exit
fi

run_test $1 $2;
