;Ankit Kumar
;2021015


section .data
	cout1: db "Enter string: ",0
	stringHolder: db "%s",0
	cout2: db "Enter Integer: ",0
	intHolder: db "%d",0
	nextline: db 10,0
	cout3: db "Your entered string is: ",0
	cout4: db "Your entered integer is: ",0


section .bss
	string resb 32
	integer resb 4


section .text
	extern printf
	extern scanf
	global main



main :
	push rbp
	mov rbp , rsp

	lea rdi , [cout1]
	call printf

	lea rdi , [stringHolder]
	lea rsi , [string]
	call scanf
	lea rdi , [cout2]
	call printf


	lea rdi , [intHolder]
	mov rsi , integer
	call scanf
	lea rdi , [cout3]
	call printf

	lea rdi , [stringHolder]
	lea rsi , [string]
	call printf

	
	lea rdi , [nextline]
	call printf

	lea rdi , [cout4]
	call printf
	
	lea rdi , [intHolder]
	mov rsi , [integer]
	call printf

	lea rdi , [nextline]
	call printf

	leave
	ret

