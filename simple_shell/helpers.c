#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * free_list -  function that frees list_t list.
 * @head: a pointerto the head of list
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *ptr;

	if (!head)
	{
		return;
	}
	while (head != NULL)
	{
		ptr = head->next;
		free(head->str);
		free(head);
		head = ptr;
	}

}

/**
 *create_path_list - create a linked list of path evirnoment
 *Return: head pointer of created linked list, otherwise null
 */
list_t *create_path_list(void)
{
	char *pathptr;
	char *pathptrcpy;
	char *token;
	list_t *head = NULL;

	pathptr = mygetenv("PATH");
	if (pathptr == NULL)
	{
		return (NULL);
	}
	pathptrcpy = mystrdup(pathptr);
	if (!pathptrcpy)
	{
		return (NULL);
	}
	token = strtok(pathptrcpy, ":");
	while (token)
	{
		list_t *newnode = malloc(sizeof(list_t));

		if (!newnode)
		{
			free(pathptrcpy);
			free_list(head);
			return (NULL);
		}
		newnode->len = mystrlen(token);
		newnode->str = mystrdup(token);
		if (!newnode->str)
		{
			free(pathptrcpy);
			free_list(head);
			return (NULL);
		}
		newnode->next = head;
		head = newnode;
		token = strtok(NULL, ":");
	}
	free(pathptrcpy);
	return (head);
}

/**
 *myexit - exit the shell
 *@n: value to exit with
 * Return: void
 */
void myexit(int n)
{
	exit(n);
}

/**
 *myenv - prints the cureent working envirnoment
 *@environ: pointer to head pointer of current envirnoment varaiable
 *Return: 0
 */
int myenv(char **environ)
{
	int i = 0;
	int j = 0;

	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0')
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
	return (0);
}

/**
 * freelinecpy -  function that frees char pointer.
 * @linecp: a pointer to free
 * Return: 0
 */
int freelinecpy(char *linecp)
{
	if (linecp)
	{
		free(linecp);
	}
	return (0);
}

/**
 * freelineptr -  function that frees char pointer.
 * @lineptr: a pointer to free
 * Return: 0
 */
int freelineptr(char *lineptr)
{
	if (lineptr)
	{
		free(lineptr);
	}
	return (0);
}

/**
 * freeargv -  function that frees array of strings argv.
 * @argv: a pointer to array
 * @size: size of array to free
 * Return: 0
 */
int freeargv(char **argv, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (argv[i] != NULL)
		{
			free(argv[i]);
		}
	}
	if (argv != NULL)
	{
		free(argv);
		argv = NULL;
	}
	return (0);
}

/**
 * mystrlen - return length of string
 * @s: string to evalute
 * Return: length of string
 */
int mystrlen(const char *s)
{
	int length = 0;

	if (!s)
	{
		return (0);
	}
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * mystrcmp - compare two strings
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 * Return: 0, 1 0r -1
 */
int mystrcmp(const char *s1, const char *s2)
{
	int length = 0;

	if (!s1 || !s2)
	{
		return (-1);
	}
	while (s1[length] != '\0' && s2[length] != '\0')
	{
		if (s1[length] != s2[length])
		{
			return (s1[length] - s2[length]);
		}
		length++;
	}

	if (s1[length] != '\0' && s2[length] == '\0')
	{
		return (1);
	}
	else if (s1[length] == '\0' && s2[length] != '\0')
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

/**
 * mystrdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to copy to the new allocated space
 * Return: char pointer
 */
char *mystrdup(const char *str)
{
	int j;
	int i = 0;
	char *ptr;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	ptr = (char *) malloc((i + 1) * sizeof(char));
	if (!ptr)
	{
		return (NULL);
	}
	for (j = 0; j < i ; j++)
	{
		ptr[j] = str[j];
	}
	ptr[i] = '\0';
	return (ptr);
}

/**
 * _cutline - cut newline char form char ptr
 * @ptr: ptr to cut from
 * Return: void
 */
void _cutline(char *ptr)
{
	int i = 0;

	if (!ptr)
	{
		return;
	}
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '\n')
		{
			ptr[i] = '\0';
		}
		i++;
	}
}

/**
 * mygetenv - return ptr to str ,if str is found in environ
 * @str: ptr to search for in environ
 * Return: char * if found, null otherwise
 */
char *mygetenv(const char *str)
{
	int j = 0;
	int i = 0;
	const char *ptr = str;
	int check = 0;
	int len = mystrlen(str);

	if (!str)
	{
		return (NULL);
	}
	while (environ[i] != NULL)
	{
		j = 0;
		check = 0;
		while (ptr[j] != '\0' && environ[i][j] != '=' && ptr[j] == environ[i][j])
		{
			j++;
			check++;
		}
		if (ptr[j] == '\0' && environ[i][j] == '=' && check == len)
		{
			return (&environ[i][j + 1]);
		}
		i++;
	}
	return (NULL);
}

/**
 * printprompt - printprompt
 * Return: void
 */
void printprompt(void)
{
	char *prompt = "#";
	int i = 0;

	while ((prompt[i]) != '\0')
	{
		_putchar(prompt[i]);
		i++;
	}
}
