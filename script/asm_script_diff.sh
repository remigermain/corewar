#!/bin/bash

ERRROR="0"

if [[ $# -ne 1 ]]
then
	echo "usage: asm_script_diff.sh <file.s>"
	ERROR="1";
fi

if [[ ! -f "asm" ]]
then
	echo "usage: asm_script_diff.sh <file.s>"
	ERROR="1";
fi

if [[ ! -f "ressources/original_asm" ]]
then
	echo "can't find ressources/original_asm"
	ERROR="1";
fi

if [[ ! -f "asm" ]]
then
	echo "can't find ressources/original_asm"
	ERROR="1";
fi


if [[ ${ERROR} = "1" ]]
then
	exit;
fi


cp $1 .your_asm.s
cp $1 .original_asm.s

echo "\n[  ASM  $NAME ]\n"

echo "\033[1;35mYOUR_ASM:\033[0m\n"
./asm .your_asm.s
echo "\n\033[1;36mORIGINAL_ASM:\033[0m\n"
./ressources/original_asm .original_asm.s
echo ""
hexdump .your_asm.cor > .new
hexdump .original_asm.cor > .base

DIFF=`diff .base .new | wc -l`
if [[ ${DIFF} -ge 1 ]]
then
	echo "\033[1;31m[ diff  KO ]\033[1;31m"
	diff .base .new
else
	echo "\033[1;32m[ diff OK ]\033[1;31m"
fi
rm -rf .base .new $NAME2 $NAME
