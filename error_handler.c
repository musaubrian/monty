#include "monty.h"

/**
 * handle_errors - handle errors from the program
 * @line_num: number of lines in opcode file
 * @type_err: number passed representing error type
 *
 * Return: void
 */

void handle_errors(unsigned int line_num, int type_err)
{
	if (type_err == 1)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
	else if (type_err == 2)
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
	else if (type_err == 3)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
	else if (type_err == 4)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
	else if (type_err == 5)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
	else if (type_err == 6)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
	exit(EXIT_FAILURE);
}
