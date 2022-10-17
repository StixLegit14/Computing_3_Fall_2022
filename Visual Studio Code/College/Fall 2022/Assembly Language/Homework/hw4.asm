	.data
inBuf:		.space	80		# input line
outBuf: 	.space 	80		# char types for the input line

prompt:		.asciiz	"Enter a new input line. \n"
newline:	.asciiz "\n"


	.text
nextline:				# while (1){
	jal	getline			# getline();

      	lb	$t7, inBuf		# if (inBuf[0] == #) break;
	beq	$t7, '#', stop
      
        li	$t0, 0			# i = 0;
rept:
					# do {
	lb	$t7, inBuf($t0)		# key = inBuf[i];
	jal	search			# chType = search(key);
	# addi	$a3, $a3, 0x30	
        sb	$a3, outBuf($t0) 	# outBuf[i] = char(chType)

        addi	$t0, $t0, 1		# i++;
	bne	$t7, '#', rept		# while (inBuf[i] != #);
	
	li	$t1, 0 			# j = 0
	
	jal	printOutBuf		# print outBuf
	
	#print
	li	$v0, 4
	la	$a0, newline
	syscall	
	
	# jal	clearInBuf		# clear inBuf
	jal	clearOutBuf		# clear outBuf

	b 	nextline		# }
stop:
	li	$v0, 10
	syscall
	
	
getline:
	# print
	li	$v0, 4
	la	$a0, prompt
	syscall
	
	#scan
	li	$v0, 8
	la	$a0, inBuf 
	li	$a1, 80
	syscall
	
	#return
	jr	$ra
	
search:

	li	$t8, 0			#j = 0
	
reptSearch:
	sll 	$t9, $t8, 2		# k = j << 2
	
	lb	$t6, tabChar($t9)	# arrtabChar = tabChar[k]
	
	beq	$t7, $t6, leave 	# if(arrinBuf == arrtabChar) { goto leave
	
	addi 	$t8, $t8, 1 		# i++
	
	# loop
	b 	reptSearch
	
leave:
	lw	$a3, tabChar +4($t9)	# add to tabChar
	
	#return
	jr	$ra

printOutBuf:

	li 	$t2, 0			# j = 0
	
reptprintOutBuf:
	lb	$t3, outBuf($t2)	# arrHolder = outBuf[j]

	beq	$t2, 80, exit 		# if (j == 80) {  goto exit
	beq	$t3, 0, exit		# if (arrHolder == 0) goto exit
	
	addi	$t2, $t2, 1		# j++
	
	# print
	li	$v0, 1
	move	$a0, $t3
	syscall
	
	# loop
	b	reptprintOutBuf

clearInBuf:
	addi	$t5, $zero, 0		# i = 0
	addi	$t2, $zero, 0		# j = 0
reptInBufclear:
	beq	$t5, 5, exit		# if (i == #) { goto exit
	
	addi	$t3, $zero, 0
	sb	$t3, inBuf($t2)		# inBuf[j] = arrHolder
	
		
	addi	$t5, $t5, 1		# i++
	addi	$t2, $t2, 1		# j++
	

clearOutBuf:
	addi	$t5, $zero, 0		# i = 0
	addi	$t2, $zero, 0		# j = 0
reptOutBufclear:
	beq	$t5, 5, exit		# if (i == 5) { goto exit
	
	addi	$t3, $zero, 0
	sb	$t3, outBuf($t2)	# outBuf[j] = arrHolder
	
		
	addi	$t5, $t5, 1		# i++
	addi	$t2, $t2, 1		# j++
	b	reptOutBufclear
	
exit:

	jr	$ra
	
	.data
tabChar: 	
	.word	0x09, 6		# tab
	.word 	0x0a, 6		# LF
	.word 	' ', 6
 	.word 	'#', 5
	.word 	'$',4
	.word 	'(', 4 
	.word 	')', 4 
	.word 	'*', 3 
	.word 	'+', 3 
	.word 	',', 4 
	.word 	'-', 3 
	.word 	'.', 4 
	.word 	'/', 3 
	.word 	'0', 1
	.word 	'1', 1 
	.word 	'2', 1 
	.word 	'3', 1 
	.word 	'4', 1 
	.word 	'5', 1 
	.word 	'6', 1 
	.word 	'7', 1 
	.word 	'8', 1 
	.word 	'9', 1
	.word 	':', 4 
	.word 	'A', 2
	.word 	'B', 2 
	.word 	'C', 2 
	.word 	'D', 2 
	.word 	'E', 2 
	.word 	'F', 2 
	.word 	'G', 2 
	.word 	'H', 2 
	.word 	'I', 2 
	.word 	'J', 2 
	.word 	'K', 2
	.word 	'L', 2 
	.word 	'M', 2 
	.word 	'N', 2 
	.word 	'O', 2 
	.word 	'P', 2 
	.word 	'Q', 2 
	.word 	'R', 2 
	.word 	'S', 2 
	.word 	'T', 2 
	.word 	'U', 2
	.word 	'V', 2 
	.word 	'W', 2 
	.word 	'X', 2 
	.word 	'Y', 2
	.word 	'Z', 2
	.word 	'a', 2 
	.word 	'b', 2 
	.word 	'c', 2 
	.word 	'd', 2 
	.word 	'e', 2 
	.word 	'f', 2 
	.word 	'g', 2 
	.word 	'h', 2 
	.word 	'i', 2 
	.word 	'j', 2 
	.word 	'k', 2
	.word 	'l', 2 
	.word 	'm', 2 
	.word 	'n', 2 
	.word 	'o', 2 
	.word 	'p', 2 
	.word 	'q', 2 
	.word 	'r', 2 
	.word 	's', 2 
	.word 	't', 2 
	.word 	'u', 2
	.word 	'v', 2 
	.word 	'w', 2 
	.word 	'x', 2 
	.word 	'y', 2
	.word 	'z', 2
	.word	0x5c, -1		# if you '\' as the end-of-table symbol
