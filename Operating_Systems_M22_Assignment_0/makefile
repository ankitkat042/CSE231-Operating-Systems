all: ankit

ankit: 2021015_assignment1.asm
	yasm -f elf64 2021015_assignment1.asm -o 2021015_assignment1.o
	gcc -no-pie 2021015_assignment1.o -o 2021015_assignment1

clean:
	rm *.o
