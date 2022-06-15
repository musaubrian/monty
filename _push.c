#include "monty.h"

/**
 * _push - pushes element to top of stack
 * @stack: double pointer to stack
 * @line_number: number of lines in opcode file
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *push_element;
	(void) line_number;

	push_element = malloc(sizeof(stack_t));
	if (push_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	push_element->n = global_var;
	if (*stack == NULL)
		push_element->next = NULL;
	else
		push_element->next = *stack;
	push_element->prev = NULL;
	*stack = push_element;
	if (push_element->next != NULL)
		push_element->next->prev = push_element;
}
