# simple shell Project 
## Video Demo
[Youtube link](https://youtu.be/E8GxArsmFSU)
## Description
A shell is a program that interacts with the kernel to provide an interface to execute commands in a Unix environment. 
In this project, I implemented a custom-built shell program using c language.  a Read/Parse/Execute/Output flow was implemented using systems calls and processes, like execve(), fork(), wait(), etc.. to achieve the behavior of a shell program.
## Features
the program has two modes:\
A) interactive mode: where the program reads and executes an input command, and waits for a new command until the user explicitly exits the program.\
B) non-interactive mode: the program executes all commands piped to it through the command line and then immediately exits.

Available commands:
1) Builtins:
   1) env: output all current environment variables.
   2) exit: exit the shell program.
   3) cd: change the current directory to a new one.
2) External executables:\
 All saved external executable commands can be run by inputting their path name. example: /bin/ls, /bin/pwd, etc...
## Files
[myshell.c](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/myshell.c): main function of the program.\
[main.h](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/main.h): header file.\
[shellfunctions.c](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/shellfunctions.c): implemented functions used in the main function\
[helpers.c](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/helpers.c): custom-implemented version of the standard c library used in the implementation of the program.\
[testfile](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/testfile): test file for the non-interactive mode of the program.\
[hsh](https://github.com/Mohammed-Refat-0/Projects/blob/master/simple_shell/hsh): compiled .exe shell program.
## Dependencies
Unix environment\
c compiler (gcc)\
git
## How to run
1) clone this repository in your local environment and cd into it
   ```bash
      git clone https://github.com/Mohammed-Refat-0/Projects/edit/master/simple_shell
      cd simple_shell
3) compile the program
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu11 *.c -o executablename. example: gcc -Wall -Werror -Wextra -pedantic -std=gnu11 *.c -o hsh
3) run\
A) interactive mode:\
   1- run the executable: ./executablename\
   2- type commands:command-name\
      example:
      ```bash
      ./hsh
      pwd
B) non-interactive mode:
- "command name" "input parameters" | ./executablename.\
    example:
  ```bash
  cat testfile | ./hsh

### Authors
[Mohammed Refat](https://github.com/Mohammed-Refat-0)
