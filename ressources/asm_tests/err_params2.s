
.name "err_params"
.comment "comment"

label:
	        zjmp           26895
	        zjmp           r1
			ldi            %189, r0, r10
			ldi            %189, r17, r10
			ldi            %189, r-1, r10
			lfork          %32768
			lfork          %-32769
			lld            %2147483648, r13
			lld            %-2147483649, r:label
			lld            %-2147483649, r%:label
			and            32768, r6, r5
			and            -32769, r6, r5

            
			zjmp           %23870
			or             2940, 9367, r4
			lfork          %23212
			ldi            2980, r10, r8
			lld            %27912, r3
			sub            r2, r12, r12
			ldi            r6, r11, r10
			lld            %19782, r10
			lldi           %13442, r4, r12
			sti            r5, 22501, %8382
			st             r6, r10
			lfork          %3008
			lldi           27061, r10, r12
			xor            r2, %15679, r9
			live           %28800
			zjmp           %11332
			ld             %27537, r14
			st             r12, 11619
			or             r15, %16885, r1
			ldi            3293, %16675, r1
			sub            r2, r6, r13
			live           %12457