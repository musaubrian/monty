#include "monty.h"
/**
 * op_functions - functions structure and comparisons with the opcode
 * @tks: the arrays of strings passed and tokenized
 * @ln: number of lines in the opcode file
 * Return: null if not valid or the right function
 */
void (*op_functions(char **tks, unsigned int ln))(stack_t **, unsigned int)
{
	instruction_t funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop_func},
		{"sub", _sub},
		{NULL, NULL}
	};
	unsigned int src = 0;
	char comp = 0;

	while (funcs[src].opcode != NULL)
	{
		if ((strcmp(funcs[src].opcode, tks[0]) == 0))
		{
			comp = (strcmp(funcs[src].opcode, "push") == 0);
			if (comp && (tks[1] == NULL || (!(check_args(tks[1])))))
			{
				free(tks);
				return (NULL);
			}
			else if ((strcmp(funcs[src].opcode, "push") == 0))
				global_var = atoi(tks[1]);
			free(tks);
			return (funcs[src].f);
		}
		src++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, tks[0]);
	free(tks);
	exit(EXIT_FAILURE);
}
