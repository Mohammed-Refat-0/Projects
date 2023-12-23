#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;


struct shell_state {
	char lastdir[1024];
};

extern char **environ;
int _putchar(char c);
list_t *create_path_list(void);
void free_list(list_t *head);
int search_list(list_t **head, const char *str);
int freelinecpy(char *linecp);
int freelineptr(char *lineptr);
int freeargv(char **argv, int size);
int myenv(char **environ);
void myexit(int n);
void cntrlc_handler(int sig);
int mystrlen(const char *s);
int mystrcmp(const char *s1, const char *s2);
char *mystrdup(const char *str);
void _cutline(char *ptr);
void printprompt(void);
char *mygetenv(const char *str);
void checklist(list_t *head);
void checklinecpy(char *linecpy, list_t *head, char *lineptr);
void checkargv(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count);
void checkargvelement(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count);
void exitshell(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count);
void checkchild(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count);
void checkwait(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count);
void checkexecve(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count);
void execute(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count, int status);
void commandhandling(char **argv, char *lineptr, char *linecpy,
		list_t *head, int *ptrcount, const char  *delim, char *token, int size);
void exec_cd(struct shell_state *state, char *arg);
#endif
