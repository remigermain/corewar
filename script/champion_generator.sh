#!/bin/bash

	# need one parameter -> the combinaison type of args
	rand_value()
	{
		RG=$(( ( RANDOM % 16 )  + 1 ));
		D2_ID=$(( ( RANDOM % 65535 )  + 1 ));
		D4=$(( ( RANDOM % 4294967295 )  + 1 ));
		arg_2=$(( ( RANDOM % 2 )  + 1 ));
		arg_3=$(( ( RANDOM % 3 )  + 1 ));


		if [ $1 -eq 1 ]; then # D4
			value="%$D4";
			s='4';
		elif [ $1 -eq 2 ]; then # D2
			value="%$D2_ID";
			s='2';
		elif [ $1 -eq 4 ]; then # RG
			value="r$RG";
			s='1';
		elif [ $1 -eq 5 ]; then # ID || RG
			if [ $arg_2 -eq 1 ]; then
				value="$D2_ID";
				s='2';
			elif [ $arg_2 -eq 2 ]; then
				value="r$RG"
				s='1';
			fi
		elif [ $1 -eq 3 ]; then # ID || D4
			if [ $arg_2 -eq 1 ]; then
				value="$D2_ID";
				s='2';
			elif [ $arg_2 -eq 2 ]; then
				value="%$D4"
				s='4';
			fi
		elif [ $1 -eq 6 ]; then # D2 || RG
			if [ $arg_2 -eq 1 ]; then
				value="%$D2_ID";
				s='2';
			elif [ $arg_2 -eq 2 ]; then
				value="r$RG"
				s='1';
			fi
		elif [ $1 -eq 11 ]; then # RG || ID || D2
			if [ $arg_3 -eq 1 ]; then
				value="%$D2_ID";
				s='2';
			elif [ $arg_3 -eq 2 ]; then
				value="$D2_ID"
				s='2';
			elif [ $arg_3 -eq 3 ]; then
				value="r$RG"
				s='1';
			fi
		elif [ $1 -eq 9 ]; then # ID || D4 || RG
			if [ $arg_3 -eq 1 ]; then
				value="$D2_ID";
				s='2';
			elif [ $arg_3 -eq 2 ]; then
				value="%$D4"
				s='4';
			elif [ $arg_3 -eq 3 ]; then
				value="r$RG"
				s='1';
			fi
		fi
	}

	# need one parameter -> the op code
	get_value()
	{
		if [ $1 -eq 1 ]; then
			rand_value 1 0;
			v1="$value";
			size='5';
		elif [ $1 -eq 9 -o $1 -eq 12 -o $1 -eq 15 ]; then
			rand_value 2;
			v1="$value";
			size='3';
		elif [ $1 -eq 4 -o $1 -eq 5 ]; then
			rand_value 4;
			v1="$value";
			size="$s";
			rand_value 4;
			v2="$value";
			((size+=$s));
			rand_value 4;
			v3="$value";
			((size+=$s + 2));
		elif [ $1 -eq 16 ]; then
			rand_value 4;
			v1="$value";
			size='3';
			indice='4';
		elif [ $1 -eq 2 -o $1 -eq 13 ]; then
			rand_value 3;
			v1="$value";
			size="$s";
			rand_value 4;
			v2="$value";
			((size+=$s + 2));
		elif [ $1 -eq 3 ]; then
			rand_value 4;
			v1="$value";
			size="$s";
			rand_value 5;
			v2="$value";
			((size+=$s + 2));
		elif [ $1 -eq 10 -o $1 -eq 14 ]; then
			rand_value 11;
			v1="$value";
			size="$s";
			rand_value 6;
			v2="$value";
			((size+=$s));
			rand_value 4;
			v3="$value";
			((size+=$s + 2));
		elif [ $1 -eq 6 -o $1 -eq 7 -o $1 -eq 8 ]; then
			rand_value 9;
			v1="$value";
			size="$s";
			rand_value 9;
			v2="$value";
			((size+=$s));
			rand_value 4;
			v3="$value";
			((size+=$s + 2));
		elif [ $1 -eq 11 ]; then
			rand_value 4;
			v1="$value";
			size="$s";
			rand_value 11;
			v2="$value";
			((size+=$s));
			rand_value 6;
			v3="$value";
			((size+=$s + 2));
		fi
	}

	# write into random_champion file one instruction
	write_file()
	{
		get_value $1;
		if [ $1 -eq 1 ]; then
			echo "live $v1" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 9 ]; then
			echo "zjmp $v1" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 12 ]; then
			echo "fork $v1" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 15 ]; then
			echo "lfork $v1" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 4 ]; then
			echo "add $v1, $v2, $v3" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 5 ]; then
			echo "sub $v1, $v2, $v3" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 2 ]; then
			echo "ld $v1, $v2" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 13 ]; then
			echo "lld $v1, $v2" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 16 ]; then
			echo "aff $v1" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 3 ]; then
			echo "st $v1, $v2" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 6 ]; then
			echo "and $v1, $v2, $v3" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 7 ]; then
			echo "or $v1, $v2, $v3" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 8 ]; then
			echo "xor $v1, $v2, $v3" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 10 ]; then
			echo "ldi $v1, $v2, $v3" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 14 ]; then
			echo "lldi $v1, $v2, $v3" >> ressources/sources/Randomize_Commodore.s;
		elif [ $1 -eq 11 ]; then
			echo "sti $v1, $v2, $v3" >> ressources/sources/Randomize_Commodore.s;
		fi
	}

	random_champion()
	{
		random_size=$(( ( RANDOM % 450 )  + 200 ));
		i='4';
		if [ -f "./ressources/sources/Randomize_Commodore.s" ]; then
			rm ressources/sources/Randomize_Commodore.s;
		fi
		if [ $3 -eq 2 ]; then
			echo ".name \"$1\"" >> ressources/sources/Randomize_Commodore.s;
			echo ".comment \"$2\"" >> ressources/sources/Randomize_Commodore.s;
		else
			echo ".name \"Randomize Commodore\"" >> ressources/sources/Randomize_Commodore.s;
			echo ".comment \"I'm the result of hasard, what could you do against that ?\"" >> ressources/sources/Randomize_Commodore.s;
		fi
		while [ $i -lt $random_size ]; do
			((i++));
			op=$(( ( RANDOM % 15 )  + 1 ));
			write_file $op;
			((limit+=size));
			if [ $limit -gt $random_size ]; then
				break;
			fi
		done
	}

	if [ ! -f "asm" ]; then
		make;
	fi
	random_champion "$1" "$2" $#;
	./asm ressources/sources/Randomize_Commodore.s -o ressources/compile/Randomize_Commodore.cor;
