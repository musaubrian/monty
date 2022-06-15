#include "monty.h"

/**
 * read_file - reads the file passed as argument
 * @file_name: pointer to file passed as argument
 * Return: void
 */

void read_file(char *file_name)
{
	stack_t *stack = NULL;
	int line_number = 0;
	char **tokens, *buffer = NULL;
	size_t size = 0;

	FILE *file_data;
	void (*s)(stack_t **stack, unsigned int line_number);

	file_data = fopen(file_name, "r");
	if (file_data == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (-1 != getline(&buffer, &size, file_data))
	{
		line_number++;
		tokens = tokenize(buffer);
		if (tokens == NULL)
			continue;
		else
			s = op_functions(tokens, line_number);
		if (s != NULL)
		{
			s(&stack, line_number);
		}
		else
		{
			handle_errors(line_number, 2);
			fclose(file_data);
			free(buffer);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file_data);
	free(buffer);
	free_stack(&stack);
}

/**
 * _sub - subtracts the top element of the stack from the second top
 * @stack: double pointer to stack
 * @line_number: number of lines insode the opcode file
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_errors(line_number, 6);
	}
	aux_stack = *stack;
	if (aux_stack->next == NULL)
		handle_errors(line_number, 6);
	aux_stack->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(aux_stack);
	(*stack)->prev = NULL;
}
