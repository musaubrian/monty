#include "monty.h"

/**
 * tokenize - divides the lines passed in the opcode file
 * @buffer: arrays of string passed to the interpreter
 * Return: tokens
 */
char **tokenize(char *buffer)
{
	unsigned int commands;
	char *token;
	char **tokens;

	tokens = malloc(sizeof(char *) * 3);
	if (tokens == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " '\n'");
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}
	commands = 0;
	while (token != NULL && commands < 2)
	{
		tokens[commands] = token;
		token = strtok(NULL, " '\n'");
		commands++;
	}
	tokens[commands] = NULL;
	return (tokens);
}
