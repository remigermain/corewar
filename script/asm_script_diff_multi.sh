#!/bin/bash

ERRROR="0"
DIFF="0"
MEMCHECK="0"
if [[ $# -ne 1 ]] && [[ $# -ne 2 ]]
then
	echo "usage : sh script/asm_script_diff_multi.sh <folder> <memcheck>"
	exit;
fi

if [ $# -ne 1 ]
then
	if
	[ $2 = "--memcheck" ]
	then
		echo "memcheck"
		MEMCHECK=1
	else 
		echo "flags accepted: --memcheck"
		exit;
	fi
fi

if [[ ! -d $1 ]]
then
	echo "You need a valid folder!"
fi

if [[ ! -f "ressources/original_asm" ]]
then
	echo "can't find ressources/original_asm"
	ERROR="1";
fi

if [[ ! -f "asm" ]]
then
	echo "can't find asm"
	ERROR="1";
fi

if [[ ${ERROR} = "1" ]]
then
	exit;
fi


	function run_test()
	{
		cp $1 ".asm_your.s"
		cp $1 ".asm_orig.s"

		echo "\033[1;35mYOUR_ASM:\033[0m\n"
		if [ $MEMCHECK = "1" ]
		then
			~/.brew/Cellar/valgrind/3.14.0/bin/valgrind  --suppressions=101.supp --show-leak-kinds=all --leak-check=full --log-file="valgrind_output" ./asm .asm_your.s 
			echo "\n\033[1;31m"
			cat valgrind_output | grep -e lost -e reachable -e Invalid | grep -v -e possibly -e "lost: 0" -e "reachable: 0[^,]" 
			echo "\n\033[0m"
		fi
		./asm .asm_your.s > output
		RETURN=`cat output | grep "error" | wc -l`
		if [[ ${RETURN} -ge 1 ]]
		then
			echo "\033[31mYour asm can't compile $1"
			echo "($RETURN  errors)\033[0m"
			return;
		else
			cat output
		fi

		echo "\n\033[1;36mORIGINAL_ASM:\033[0m\n"

		./ressources/original_asm .asm_orig.s > output
		RETURN=`cat output | grep "error" | wc -l`
		if [[ ${RETURN} -ge 1 ]]
		then
			echo "\033[31mOriginal asm can't compile $1\033["
			return;
		else
			cat output
		fi
		
		hexdump .asm_your.cor > .new
		hexdump .asm_orig.cor > .base
		
		CCC=`diff .base .new | wc -l`
		if [[ ${CCC} -ge 1 ]]
		then
			echo "\033[1;31m[ diff  KO ]\033[0m"
			(( DIFF+=1 ))
			diff .base .new
		else
			echo "\033[1;32m[ diff OK ]\033[0m"
		fi
		rm -rf .base .new .asm_your.cor .asm_orig.cor .asm_your.s .asm_orig.s
	}

	ls -1 $1 | cat > .asm_multi_1
	RET=`cat .asm_multi_1 | grep ".s" | wc -l | bc`

	if [[ ${RET} -le 0 ]]
	then
		echo "No champions in your folder!"
		exit
	fi

	FOLDER=${1: -1};
	if [[ ${FOLDER} != "/" ]]
	then
		NEW=`echo $1"/"`
	else
		NEW=$1
	fi

	awk -v prefix="${NEW}" '{print prefix $0}' .asm_multi_1 > .asm_multi_2
	input=".asm_multi_2"
	while IFS= read -r line
	do
		echo "\033[1;33m\n[Player = $line ]\n\033[0m"
		run_test $line;
	done < "$input"
	rm -rf .asm_multi_1 .asm_multi_2 output valgrind_output .asm_orig.s .asm_your.s

	echo "\n[ Ending asm compare ]\n total diff = $DIFF\n"
