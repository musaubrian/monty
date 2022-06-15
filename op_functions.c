#include "monty.h"

/**
 * _add - adds to the top two elements of the stack
 * @stack: double pointer to a double linked list as stack
 * @line_number: number of lines inside the opcode file
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_errors(line_number, 5);
	}
	aux_stack = *stack;
	if (aux_stack->next == NULL)
		handle_errors(line_number, 5);
	aux_stack->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(aux_stack);
	(*stack)->prev = NULL;
}

/**
 * _nop_func - does nothing
 * @stack: double pointer to the beggining of the stack (DLL)
 * @line_number: number of lines in the opcode file
 * Return: void
 */
void _nop_func(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * _pall - prints all the values of the stack starting from the top
 * @stack: double pointer to a double linked list as stack
 * @line_number: number of lines inside the opcode file
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *aux_stack;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	aux_stack = *stack;
	while (aux_stack != NULL)
	{
		fprintf(stdout, "%d\n", aux_stack->n);
		aux_stack = aux_stack->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: double pointer to the beggining of the stack
 * @line_number: the numbers of lines in the opcode file
 *
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		handle_errors(line_number, 4);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pop - removes top element from stack
 * @stack: double pointer to the beggining of the stack
 * @line_number: number of lines in the opcode file
 *
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack;

	if (*stack == NULL)
		handle_errors(line_number, 1);

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		aux_stack = (*stack)->next;
		(*stack) = aux_stack;
		aux_stack = aux_stack->prev;
		(*stack)->prev = NULL;
		free(aux_stack);
	}
}
