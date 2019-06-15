#!/bin/bash

COUNTER=0
SUM="0"

function	run_test()
{
	echo "[ START ]\n"
	./corewar -d 1 -p $1 > .diff_core && ./subject_ressources/original_corewar -d 1 -a $1 > .diff_oricore
	BASE=`diff .diff_core .diff_oricore | wc -l | bc`
	echo "diff is $BASE\n"
	while [[ ${COUNTER} -lt 700000 ]]
	do
			./corewar -d $COUNTER -p $1 > .diff_core && ./subject_ressources/original_corewar -d $COUNTER -a $1 > .diff_oricore
			MED=`diff .diff_core .diff_oricore | wc -l | bc`
			echo "\033[1A\c"
			echo "count = "${COUNTER}
			if [[ ${MED} -ne $BASE ]]
			then
				TEST=`./subject_ressources/original_corewar -d 500000 -a $1 | wc -l | bc`
				NOW=`./subject_ressources/original_corewar -d $COUNTER -a $1 | wc -l | bc`
				if [[ ${TEST} -ne ${NOW} ]]
				then
					echo "[ ENDING ]\n[ KO ]count = "${COUNTER}
						diff .diff_core .diff_oricore
					else
						echo "[ ENDING ]\nzaz vm ending !\n[ OK ]count = "${COUNTER}
				fi
				return ;
			fi
		(( COUNTER += 1 ))
	done
	echo "[ ENDING ]\n[ OK ]\ncount = "${COUNTER}
	rm -rf .diff_core .diff_oricore
}

if [[ $# -le 0 ]]
then
	echo "Need folder !"
	exit;
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

awk -v prefix="$NEW" '{print prefix $0}' .script_1 > .script_2
input=".script_2"
while IFS= read -r line
do
	echo "\n[Player = $line ]\n"
	run_test $line;
done < "$input"
rm -rf .script_1 .script_2
