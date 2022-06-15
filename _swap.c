#include "monty.h"

/**
 * _swap - swaps the top two elements in the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: number of lines of the opcode file
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(line_number, 3);
	aux_stack = (*stack)->next;
	(*stack)->prev = aux_stack;
	(*stack)->next = aux_stack->next;
	aux_stack->prev = NULL;
	aux_stack->next = *stack;
	*stack = aux_stack;
}
