# Custom Linux Shell

![image](https://github.com/community/community/assets/79627254/68cf5414-bd4e-4435-a3d7-e384e2e86e63)  

![image](https://github.com/community/community/assets/79627254/637c453f-1782-48e0-88be-3e5e631abfcf)
Command explanation

Internal
cd
	Options
		-L : force symbolic links to be followed: resolve symbolic links in DIR after 
  		       processing instances of ..
		–help: display the help manual and exits
	
Error handled
	-if directory not present it shows “No such file/directory”
	-if the flag is absent or wrong, it shows no such option or file is present

	Assumption: home directory is the directory in which ./main is present
echo 
	Options
		-n : omit the trailing newline character
		-E : diable the interpretation of backslash escapes (default)
	
Error handled
	-if no argument is passed then shows error that argument required

Assumption: double quotes of the string is directly handled

pwd
	Options
		-L : print the value of $PWD if it names the current working directory
		-P : print the physical directory, without any symbolic links
		–help: displays help and exit (implemented before professor’s email)

	Error handled
		-if option is not present then outputs option not found










External Commands

ls
	Options
		-a : show hidden files, which means shows filename starting with ‘.’
		-m : comma separated names of files and folders
		-1 : shows the name of folders and files as a vertical list

	Error handled
		-arguments are not enough or wrong arguments

cat
	Options
		-n : number all output lines
		-E : display $ at the end of each line

	Error handled: using fopen error library and errno.h header file
		-file doesnot exist
		-user doesn’t have access to the file

date 
	Options
		-u : print the UTC time
		–help: display help manual and exit(also implemented before sir’s mail)

rm
	Options
		-i : output promt as a warning before removing a file
		–help : display the help abd exits
Errors:
-file does not exits
-given path is a directory
-user doesnnot have access to files

mkdir 
Options
-v : print a message for each created directory
–help : display help and exits :(
Errors
- the named directory already exists
- readonly folder cannot have subfolders
- a component of path prefix cannot be a directory

Sources used

Cd : https://man7.org/linux/man-pages/man1/cd.1p.html
Echo : https://man7.org/linux/man-pages/man1/echo.1.html
Pwd : https://man7.org/linux/man-pages/man1/pwd.1.html
Ls: https://man7.org/linux/man-pages/man1/ls.1.html
Cat: https://man7.org/linux/man-pages/man1/cat.1.html
Date: https://man7.org/linux/man-pages/man1/date.1.html
rm:https://man7.org/linux/man-pages/man1/rm.1.html
Mkdir: https://man7.org/linux/man-pages/man1/mkdir.1.html
fork() and execvp :http://www.cs.ecu.edu/karl/4630/sum01/example1.html 
Couldnt able to implement system() and pthread() due to arguement disputes

Some code snippet used from : https://www.youtube.com/watch?v=VzCawLzITh0


Code idea inspiration: https://github.com/anshulforyou/linux_shell
			https://github.com/Priyansh19077/Linux-Terminal-Clone
