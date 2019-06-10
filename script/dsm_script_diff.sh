#!/bin/bash
make
cp $1 .
NAME=`basename $1`
NAME2=`echo $NAME | sed "s/.cor/.s/g"`
echo "\n[  DSM  $NAME ]\n"
./dsm $NAME -labels -hexa
rm -rf $NAME
./../subject_ressources/original_asm $NAME2
hexdump $NAME > .new
hexdump $1 > .base
DIFF=`diff .base .new | wc -l`
if [[ DIFF -ge 1 ]]
then
	echo "[ diff  KO ]"
	diff .base .new
else
	echo "[ diff OK ]"
fi
rm -rf .base .new $NAME2 $NAME
