#!/bin/bash


if [[ $# -le 0 ]]
then
echo -e "need folder !"
	exit;
fi

ls -1 $1 | cat > .script_1
awk -v prefix="$1" '{print prefix $0}' .script_1 > .script_2

input=".script_2"
while IFS= read -r line
do
echo -e "\n[Player = $line ]\n"
	./corewar -p $line
done < "$input"
rm -rf .script_1 .script_2
