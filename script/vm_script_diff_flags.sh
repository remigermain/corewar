#!/bin/bash

ERROR="0"

	function	run_test()
	{
		./corewar --diff $1 -d $2 > .diff_core && ./subject_ressources/original_corewar -v 31 $1 -d $2> .diff_oricore
	echo -e "[finish]"
		DIFF=`diff .diff_core .diff_oricore`
		DIFF_LINE=`diff .diff_core .diff_oricore | wc -l`

		if [[ ${DIFF_LINE} -ne 0 ]]
		then
		echo -e "[ KO is a diff ]"
		echo -e "diff = $DIFF_LINE"
		echo -e $DIFF
			sleep 1
		fi
	}

if [[ $# -ne 2 ]]
then
echo -e "You need 3 params\nscript [cycle start] [cycle_end] folder whith many <champion.cor>."
	exit;
fi

if ! [[ "$2" =~ ^[0-9]+$ ]]
then
echo -e "your param 1 \"$1\" is not integers."
	ERROR="1"
fi

ls -1 $1 | cat > .script_1
RET=`cat .script_1 | grep ".cor" | wc -l | bc`

if [[ ${ERROR} = "1" ]]
then
	exit;
fi

if [ ! -f "corewar" ]
then
	make ;
fi

run_test $1 $2;
