#include "main.h"
/**
 * checklist - validate created path
 * @head: pointer to head of linked list
 * Return: void
 */
void checklist(list_t *head)
{
	if (!head)
	{
		free_list(head);
		perror("create_path_list");
		_putchar('\n');
		exit(1);
	}
}

/**
 * checklinecpy - validate the coped line
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * Return: void
 */
void checklinecpy(char *linecpy, list_t *head, char *lineptr)
{
	if (!linecpy)
	{
		if (head)
		{
			free_list(head);
		}
		if (lineptr)
		{
			freelineptr(lineptr);
		}
		perror("mystrdup");
		_putchar('\n');
		exit(1);
	}
}

/**
 * checkargv - validate the arry of strings argv
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkargv(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count)
{
	if (!argv)
	{
		freeargv(argv, count);
		freelinecpy(linecpy);
		free_list(head);
		freelineptr(lineptr);
		perror("malloc");
		_putchar('\n');
		exit(1);
	}
}

/**
 * checkargvelement - validate eleemnts
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkargvelement(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count)
{
	freelinecpy(linecpy);
	free_list(head);
	freelineptr(lineptr);
	freeargv(argv, count);
	perror("mystrdup");
	_putchar('\n');
	exit(1);
}

/**
 * _exit - frees and exit
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void exitshell(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count)
{
	if (linecpy)
	{
		freelinecpy(linecpy);
	}
	if (head)
	{
		free_list(head);
	}
	if (lineptr)
	{
		freelineptr(lineptr);
	}
	if (argv)
	{
		freeargv(argv, count);
	}
	exit(0);
}

/**
 * checkwait - validate wait
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkwait(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count)
{
	freelinecpy(linecpy);
	free_list(head);
	freelineptr(lineptr);
	freeargv(argv, count);
	perror("wait");
	_putchar('\n');
	_exit(1);
}

/**
 * checkchild - validate child process
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkchild(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count)
{
	freelinecpy(linecpy);
	free_list(head);
	freelineptr(lineptr);
	freeargv(argv, count);
	perror("fork");
	_putchar('\n');
	_exit(1);
}

/**
 * checkexecve - validate execve process
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkexecve(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count)
{
	freelinecpy(linecpy);
	free_list(head);
	freelineptr(lineptr);
	freeargv(argv, count);
	perror(NULL);
	_putchar('\n');
	_exit(1);
}

/**
 * execute - execute the process
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * @status: status of wait
 * Return: void
 */
void execute(char **argv, char *linecpy, list_t *head,
		char *lineptr, int count, int status)
{
	pid_t child;

	if (mystrcmp(argv[0], "exit") == 0)
	{
		exitshell(argv, linecpy, head, lineptr, count);
	}
	else if (mystrcmp(argv[0], "env") == 0)
	{
		myenv(environ);
	}
	else
	{
		if (argv[0] != NULL)
		{
			child = fork();
			if (child == -1)
			{
				checkchild(argv, linecpy, head, lineptr, count);
			}
			if (child == 0)
			{
				if (execve(argv[0], argv, environ) == -1)
				{
					checkexecve(argv, linecpy, head, lineptr, count);
				}
			}
			else
			{
				if (wait(&status) == -1)
				{
					checkwait(argv, linecpy, head, lineptr, count);
				}
			}
		}
	}
}

/**
 * commandhandling - parse the command
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @ptrcount: no of elements
 * @delim: delim to parse command by
 * @token: ptr
 * @size: size
 * Return: void
 */
void commandhandling(char **argv, char *lineptr, char *linecpy,
		list_t *head, int *ptrcount, const char  *delim, char *token, int size)
{
	int i = 0;
	int count = *ptrcount;

	if (linecpy)
	{
		free(linecpy);
		linecpy = NULL;
	}
	if (argv)
	{
		freeargv(argv, count);
		argv = NULL;
	}
	count = 0;
	linecpy = mystrdup(lineptr);
	checklinecpy(linecpy, head, lineptr);
	_cutline(linecpy);
	token = strtok(linecpy, delim);
	argv = malloc(sizeof(char *) * (size));
	checkargv(argv, linecpy, head, lineptr, *ptrcount);
	while (token != NULL)
	{
		argv[i] = mystrdup(token);
		if (argv[i] == NULL)
		{
			checkargvelement(argv, linecpy, head, lineptr, *ptrcount);
		}
		token = strtok(NULL, delim);
		(*ptrcount)++;
		i++;
	}
	argv[*ptrcount] = NULL;
}

/**
 * exec_cd - execute the builtin function cd,
 * which changea the current directory
 * @arg: string of the path to cd into
 * @state: last saved directory
 * Return: void
 */
void exec_cd(struct shell_state *state, char *arg) {
	char curdir[1024];
	char path[1024];

	strcpy(state->lastdir, curdir);
	if (getcwd(curdir, sizeof curdir)) {
		*curdir = '\0';
	}

	if (arg == NULL) {
		arg = getenv("HOME");
	}

	if (!strcmp(arg, "-")) {
		if (state->lastdir[0] == '\0') {
			fprintf(stderr, "no previous directory\\n");
			return;
		}
		arg = state->lastdir;
	} else {
		if (*arg == '~') {
			if (arg[1] == '/' || arg[1] == '\0') {
				snprintf(path, sizeof path, "%s%s", getenv("HOME"), arg + 1);
				arg = path;
			} else {
				fprintf(stderr, "syntax not supported: %s\\n", arg);
				return;
			}
		}
	}

	if (chdir(arg)) {
		fprintf(stderr, "chdir: %s: %s\\n", strerror(errno), path);
		return;
	}
	strcpy(state->lastdir, curdir);
	setenv("PWD", arg, 1);
}
