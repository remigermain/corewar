#!/bin/bash

ERROR="0"

	function	run_test()
	{
		./corewar --diff $1 -d $2 > .diff_core && ./subject_ressources/original_corewar -v 31 $1  -d $2> .diff_oricore
		echo "[finish]"
		DIFF=`diff .diff_core .diff_oricore`
		DIFF_LINE=`diff .diff_core .diff_oricore | wc -l`

		if [[ ${DIFF_LINE} -ne 0 ]]
		then
			echo "[ KO is a diff ]"
			echo "diff = $DIFF_LINE"
			echo $DIFF
			sleep 1
		fi
		rm -rf .diff_core .diff_oricore
	}

if [[ $# -ne 2 ]]
then
	echo "You need 3 params\nscript [cycle start] [cycle_end] folder whith many <champion.cor>."
	exit;
fi

if ! [[ "$2" =~ ^[0-9]+$ ]]
then
	echo "your param 1 \"$1\" is not integers."
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

FOLDER=${1: -1};
if [[ ${FOLDER} != "/" ]]
then
	NEW=`echo $1"/"`
else
	NEW=$1
fi


awk -v prefix="${NEW}" '{print prefix $0}' .script_1 > .script_2
input=".script_2"
while IFS= read -r line
do
	echo "\n[Player = $line ]\n"
	run_test $line $2;
done < "$input"
rm -rf .script_1 .script_2
