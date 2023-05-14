#include "monty.h"
/**
 * get_opcode_function - Match chars with functions
 * @opcode: A string of opcoode
 * Return: A pointer to a function
 */
void (*get_opcode_function(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t cases[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	while (cases[i].opcode)
	{
		if (_strcmp(cases[i].opcode, opcode) == 0)
			return (cases[i].f);
		i++;
	}
	return (NULL);
}


/**
 * free_list - freee the list
 * @head: pointer to a stack_t
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * is_digit - Verify all characters in a string are digits.
 * @number: Number of string type
 * Return: 1 - Is digit | 0 - Isn't digit
 */
int is_digit(char *number)
{
	int i;

	if (!number)
		return (0);
	if ((number[0] < '0' || number[0] > '9') && number[0] != '-')
		return (0);
	for (i = 1; number[i]; i++)
		if ((number[i] < '0' || number[i] > '9'))
			return (0);
	return (1);
}
/**
 * _strcmp - Comparate two strings
 * @s1: First string
 * @s2: Second string
 * Return: Result of the comparatin
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}










