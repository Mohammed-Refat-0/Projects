# simple shell Project 
## introduction
A shell is a program that interacts with the kernel to provide an interface to execute commands in a Unix environment. 
In this project, I implemented a custom-built shell program using c language.  a Read/Parse/Execute/Output flow was implemented using systems calls and processes, like execve(), fork(), wait(), etc.. to achieve the behavior of a shell program.
### Features
the program has two modes:
A) interactive mode: where the program reads and executes an input command, and waits for a new command until the user explicitly exits the program.\
B) non-interactive mode: the program executes all commands piped to it through the command line and then immediately exits.\
available commands:\
1) Built-ins:\
   1) env: output all current environment variables.\
   2) exit: exit the shell program.\
   3) cd: change the current directory to a new one.\
3) External executables: all saved external executables commands can be run by inputting their path name. example: /bin/ls, /bin/pwd, etc...
### Files:
[myshell.c](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/myshell.c): main function of the program.\
[main.h](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/main.h): header file.\
[shellfunctions.c](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/shellfunctions.c): implemented functions used in the main function\
[helpers.c](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/helpers.c): custom-implemented version of the standard c library used in the implementation of the program.\
[testfile](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/testfile): test file for the non-interactive mode of the program.\
[hsh](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/hsh): compiled .exe shell program.
### Dependencies
Unix environment.\
c compiler (gcc).\
git.
### How to run
clone this repository in your local environment.\
compile the program: gcc -Wall -Werror -Wextra -pedantic -std=gnu11 *.c -o executablename, example:  gcc -Wall -Werror -Wextra -pedantic -std=gnu11 *.c -o hsh\
To run:\
A) interactive mode:\
1) run the executable: ./executablename, example: ./hsh\
2) type commands: command name, example: /bin/ls -a\
B) non-interactive mode:\
1) echo "command" | ./executablename, example: echo "/bin/ls" | ./hsh\
2) cat filename | ./executablename, example: cat testfile | ./hsh\
### Authors
[Mohammed Refat](https://github.com/Mohammed-Refat-0)
