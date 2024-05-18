## Assignment 0
> Ankit Kumar IIIT Delhi, 2021015

## 1. Setting-up Artix OS VM and Compiling theOS kernel
- Installed VM Virtual Box
- Downloaded Artix OS ISO from https://artixlinux.org/download.php
- Created a new VM with the downloaded ISO
- Enabled EFI mode
- Installed the OS
- Installed the necessary packages

You can find the installation Video here: [Artix OS Installation](https://youtu.be/b9Uv9fNSIzw)  
Commands: https://pastebin.com/EQ80R6Gf 

# 2 An Assembly Program 
- Wrote a simple assembly program called `2021015_assignment0.asm` which takes two number and string as input and print it to the user console.
- make sure nasm is installed otherwise install it using `sudo apt install nasm`
- Run the following commands to compile and run the program
```bash
> nasm -f elf64 2021015_assignment0.asm -o 2021015_assignment0.o
> gcc -no-pie 2021015_assignment0.o -o 2021015_assignment0
> ./2021015_assignment0
```

![image](https://github.com/community/community/assets/79627254/650b8aec-b929-4503-b3be-b8b0906724c5)