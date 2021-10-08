#!/bin/bash

COUNTER=0
SUM="0"
ERROR="0"
function	run_test()
{
	COUNTER=$3
echo -e "[ START ]\n"
	./corewar -d 1 -p $1 > .diff_core && ./subject_ressources/original_corewar -d 1 $1 > .diff_oricore
	BASE=`diff .diff_core .diff_oricore | wc -l | bc`
echo -e "diff is $BASE\n"
	while [[ ${COUNTER} -lt $2 ]]
	do
			./corewar -d $COUNTER -p $1 > .diff_core && ./subject_ressources/original_corewar -d $COUNTER $1 > .diff_oricore
			MED=`diff .diff_core .diff_oricore | wc -l | bc`
		echo -e "\033[1A\c"
		echo -e "count = "${COUNTER}
			if [[ ${MED} -ne $BASE ]]
			then
				TEST=`./subject_ressources/original_corewar -d 500000 $1 | wc -l | bc`
				NOW=`./subject_ressources/original_corewar -d $COUNTER $1 | wc -l | bc`
				if [[ ${TEST} -ne ${NOW} ]]
				then
				echo -e "[ ENDING ]\n[ KO ]count = "${COUNTER}
						diff .diff_core .diff_oricore
					else
					echo -e "[ ENDING ]\nzaz vm ending !\n[ OK ]count = "${COUNTER}
				fi
				return ;
			fi
		(( COUNTER += 100 ))
	done
echo -e "[ ENDING ]\n[ OK ]\ncount = "${COUNTER}
	rm -rf .diff_core .diff_oricore
}

if [[ $# -ne 3 ]]
then
echo -e "You need 3 params\nscript [cycle start] [cycle_end] folder whith many <champion.cor>."
	exit;
fi

if ! [[ "$1" =~ ^[0-9]+$ ]]
then
echo -e "your param 1 \"$1\" is not integers."
	ERROR="1"
fi

if ! [[ "$2" =~ ^[0-9]+$ ]]
then
echo -e "your param 2 \"$2\" is not integers."
	ERROR="1"
fi

if [[ $1 -gt $2 ]]
then
echo -e "your param 1 can't be greater than param 2."
	ERROR="1"
fi

if	[[ ! -d $3 ]]
then
echo -e "Need a valid folder !"
	exit;
fi

ls -1 $3 | cat > .script_1
RET=`cat .script_1 | grep ".cor" | wc -l | bc`
if [[ ${RET} -le 0 ]]
then
echo -e "No champions in your folder!"
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

FOLDER=${3: -1};
if [[ ${FOLDER} != "/" ]]
then
	NEW=echo -e $3"/"`
else
	NEW=$3
fi


awk -v prefix="${NEW}" '{print prefix $0}' .script_1 > .script_2
input=".script_2"
while IFS= read -r line
do
echo -e "\n[Player = $line ]\n"
	run_test $line $2 $1;
done < "$input"
rm -rf .script_1 .script_2
