#include "monty.h"
/**
 * _pall - prints all elements of list
 * @stack: pointer to a stack_t
 * @line_number: number of line
 */
void _pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	size_t counter = 0;
	stack_t *h = *stack;

	while (h)
	{
		printf("%d\n", h->n);
		counter++;
		h = h->next;
	}
}
/**
 * _push - adds node iin thge beginning
 * @stack: pointer to a stack_t
 * @line_number: number of line
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *new_list_number;

	new_list_number = strtok(NULL, " \n\t$");
	if (!new_list_number || !is_digit(new_list_number))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_list(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(new_list_number);
	new->next = *stack;
	new->prev = NULL;
	if ((*stack) != NULL)
		(*stack)->prev = new;

	(*stack) = new;
}
/**
 * _pint - print the number on top
 * @stack: pointer to a stack_t
 * @line_number: number of line
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* _swap - swaps the top two elements of the stack
* @stack: pointer to a stack_t
* @line_number: number of line
*/
void _swap(stack_t **stack, unsigned int line_number)
{
int tmp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
* _add - adds the top two elements of the stack
* @stack: pointer to a stack_t
* @line_number: number of line
*/
void _add(stack_t **stack, unsigned int line_number)
{
int sum;

if (!(*stack) || !(*stack)->next)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	fclose(file);
	exit(EXIT_FAILURE);
}

sum = (*stack)->n + (*stack)->next->n;
_pop(stack, line_number);
(*stack)->n = sum;
}
