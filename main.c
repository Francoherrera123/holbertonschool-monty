#include "monty.h"
/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: Lenght of Arguments
 * @argv: Array of Arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char line_content[1024];
	int line_number = 0;
	char *opcode;
	void (*opcode_function)(stack_t **stack, unsigned int line_number);
	stack_t *stack_head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_list(stack_head);
		exit(EXIT_FAILURE);
	}
	while (fgets(line_content, 1024, file) != NULL)
	{
		line_number++;
		opcode = strtok(line_content, " \t\n$");
		if (!opcode)
			continue;
		opcode_function = get_opcode_function(opcode);
		if (!opcode_function)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_list(stack_head);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		opcode_function(&stack_head, line_number);
	}
	free_list(stack_head);
	fclose(file);
	return (0);
}

