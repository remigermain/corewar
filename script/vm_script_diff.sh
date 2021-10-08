#!/bin/bash

WORSE="0"
BEST="16777216"
COUNTER=$1
SUM="0"
ERROR="0"

if [[ $# -ne 3 ]]
then
echo -e "You need 3 params\nscript [cycle start] [cycle_end] <champion.cor>"
	exit;
fi

if ! [[ "$1" =~ ^[0-9]+$ ]]
then
echo -e "your param 1 \"$1\" is not integers"
	ERROR="1"
fi

if ! [[ "$2" =~ ^[0-9]+$ ]]
then
echo -e "your param 2 \"$2\" is not integers"
	ERROR="1"
fi


RET=echo -e $3 | grep ".cor" | wc -l | bc`
if [[ ${RET} -le 0 ]]
then
echo -e "The file is not a champions!"
	ERROR="1"
fi

if [[ ${ERROR} = "1" ]]
then
	exit;
fi

if [ ! -f "corewar" ]
then
	make ;
fi

echo "[ START ]\n"
./corewar -d 1 -p $3 > .diff_core && ./subject_ressources/original_corewar -d 1 $3 > .diff_oricore
BASE=`diff .diff_core .diff_oricore | wc -l | bc`
echo "diff is $BASE\n"
while [[ ${COUNTER} -lt $2 ]]
do
		./corewar -d $COUNTER -p $3 > .diff_core && ./subject_ressources/original_corewar -d $COUNTER $3 > .diff_oricore
		MED=`diff .diff_core .diff_oricore | wc -l | bc`
	echo -e "\033[1A\c"
	echo -e "count = "${COUNTER}
		if [[ ${MED} -ne $BASE ]]
		then
			TEST=`./subject_ressources/original_corewar -d 500000 $3 | wc -l | bc`
			NOW=`./subject_ressources/original_corewar -d $COUNTER $3 | wc -l | bc`
			if [[ ${TEST} -ne ${NOW} ]]
			then
			echo -e "[ ENDING ]\n[ KO ]count = "${COUNTER}
				diff .diff_core .diff_oricore
			else
			echo -e "[ ENDING ]\nzaz vm ending !\n[ OK ]count = "${COUNTER}
			fi
			exit
		fi
		(( COUNTER += 1 ))
done
echo "[ ENDING ]\n[ OK ]\ncount = "${COUNTER}
rm -rf .diff_core .diff_oricore
