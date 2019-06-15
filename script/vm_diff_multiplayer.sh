#!/bin/bash

COUNTER=0
ERROR="0"

function	run_test()
{
	COUNTER=$3
	echo "[ START ]\n"
	./corewar --diff -d 1 $1 > .diff_core && ./subject_ressources/original_corewar -d 1 -v 31 $1 > .diff_oricore
	BASE=`diff .diff_core .diff_oricore | wc -l | bc`
	echo "diff is $BASE\n"
	while [[ ${COUNTER} -lt $2 ]]
	do
			./corewar -d $COUNTER --diff $1 > .diff_core && ./subject_ressources/original_corewar -d $COUNTER -v 31 $1 > .diff_oricore
			MED=`diff .diff_core .diff_oricore | wc -l | bc`
			echo "\033[1A\c"
			echo "count = "${COUNTER}
			if [[ ${MED} -ne $BASE ]]
			then
				TEST=`./subject_ressources/original_corewar -d 500000 $1 | wc -l | bc`
				NOW=`./subject_ressources/original_corewar -d $COUNTER $1 | wc -l | bc`
				if [[ ${TEST} -ne ${NOW} ]]
				then
					echo "[ ENDING ]\n[ KO ]count = "${COUNTER}
					{
						diff .diff_core .diff_oricore
						echo "[ diff ][ cycle = ${COUNTER} ]  $1 " >> script/log_diff
					}
					else
					{
						echo "[ ENDING ]\nzaz vm ending !\n[ OK ]count = "${COUNTER}
						rm -rf .diff_core .diff_oricore
					}
				fi
				return ;
			fi
		(( COUNTER += $4 ))
	done
	echo "[ ENDING ]\n[ OK ]\ncount = "${COUNTER}
	rm -rf .diff_core .diff_oricore
}

if [[ $# -ne 4 ]]
then
	echo "You need 3 params\nscript [ folder whith many <champion.cor>. ] [ cycle_start ] [ cycle_end ] [ cycle_add ]"
	exit;
fi

if ! [[ "$2" =~ ^[0-9]+$ ]]
then
	echo "your param 2 \"$2\" is not integers."
	ERROR="1"
fi

if ! [[ "$3" =~ ^[0-9]+$ ]]
then
	echo "your param 3 \"$3\" is not integers."
	ERROR="1"
fi

if ! [[ "$4" =~ ^[0-9]+$ ]]
then
	echo "your param 3 \"$4\" is not integers."
	ERROR="1"
fi


if [[ $2 -gt $3 ]]
then
	echo "your param 1 can't be greater than param 2."
	ERROR="1"
fi

if	[[ ! -d $1 ]]
then
	echo "Need a valid folder !"
	exit;
fi

ls -1 $1 | cat > .script_1
RET=`cat .script_1 | grep ".cor" | wc -l | bc`

if [[ ${RET} -le 0 ]]
then
	echo "No champions in your folder!"
	ERROR="1"
fi

if [ ! -f "corewar" ]
then
	echo "can't find corewar!"
	ERROR="1"
fi

if [[ ${ERROR} = "1" ]]
then
	exit;
fi


FOLDER=${1: -1};
if [[ ${FOLDER} != "/" ]]
then
	NEW=`echo $1"/"`
else
	NEW=$1
fi

DATE=`date`
echo "[ $DATE ]\n" >> script/log_diff

awk -v prefix="${NEW}" '{print prefix $0}' .script_1 > .script_2
input=".script_2"
while IFS= read -r line
do
	echo "\n[Player = $line ]\n"
	run_test $line $3 $2 $4;
done < "$input"
rm -rf .script_1 .script_2
