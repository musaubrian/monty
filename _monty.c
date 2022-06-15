#include "monty.h"

/**
 * main - start point for interprator
 * @argc: number of arguments passed to interprator
 * @argv: arguments passed to interprator
 *
 * Return: 0 on success else exit_failure
 */

int main(int argc, char *argv[])
{
	char *file_name;

	file_name = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_file(file_name);
	exit(EXIT_SUCCESS);
}
