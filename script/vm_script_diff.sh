#!/bin/bash

WORSE="0"
BEST="16777216"
COUNTER=$1
SUM="0"

echo "[ START ]\n"
./corewar -d 1 -p $3 > .diff_core && ./subject_ressources/original_corewar -d 1 -a $3 > .diff_oricore
BASE=`diff .diff_core .diff_oricore | wc -l | bc`
echo "diff is $BASE\n"
while [[ ${COUNTER} -lt $2 ]]
do
		./corewar -d $COUNTER -p $3 > .diff_core && ./subject_ressources/original_corewar -d $COUNTER -a $3 > .diff_oricore
		MED=`diff .diff_core .diff_oricore | wc -l | bc`
		echo "\033[1A\c"
		echo "count = "${COUNTER}
		if [[ ${MED} -ne $BASE ]]
		then
			TEST=`./subject_ressources/original_corewar -d 500000 -a $3 | wc -l | bc`
			NOW=`./subject_ressources/original_corewar -d $COUNTER -a $3 | wc -l | bc`
			if [[ ${TEST} -ne ${NOW} ]]
			then
				echo "[ ENDING ]\n[ KO ]count = "${COUNTER}
				diff .diff_core .diff_oricore
			else
				echo "[ ENDING ]\nzaz vm ending !\n[ OK ]count = "${COUNTER}
			fi
			exit
		fi
		(( COUNTER += 1 ))
done
echo "[ ENDING ]\n[ OK ]\ncount = "${COUNTER}
rm -rf .diff_core .diff_oricore
