#!/bin/bash

ERROR="0"

	function	run_test()
	{
	#	./corewar $1 -d $2 > .diff_core && ./ressources/original_corewar $1 -d $2 > .diff_oricore
		./corewar --diff $1 -d $2 > .diff_core && ./ressources/original_corewar -v 31 $1 -d $2 > .diff_oricore
	echo -e "[finish]"
		DIFF=`diff .diff_core .diff_oricore`
		DIFF_LINE=`diff .diff_core .diff_oricore | wc -l`
		if [[ ${DIFF_LINE} -ne 0 ]]
		then
		echo -e "[ KO is a diff ]"
		echo -e $DIFF
		else
		echo -e "[ OK no diff ]"
		fi
	}

if [[ $# -ne 2 ]]
then
echo -e "You need 3 params\nscript <champion.cor> [ nb _cycle ]"
	exit;
fi

if ! [[ "$2" =~ ^[0-9]+$ ]]
then
echo -e "your param 1 \"$1\" is not integers."
	ERROR="1"
fi

if [ ! -f "corewar" ]
then
echo -e "Cant's find corewar"
	ERROR="1"
fi

if [ ! -f "ressources/original_corewar" ]
then
echo -e "Cant's find corewar"
	ERROR="1"
fi

if [ $ERROR -eq "1" ]
then
	exit
fi

run_test $1 $2;
