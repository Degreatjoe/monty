#include "monty.h"
#include <stdio.h>
/**
 * main - implements the monty program
 * @argc: the argument count.
 * @argv: the argument vector.
 * Return: 0 on success.
*/
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *arg, *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		line = trim(line);
		parse_line(line, &opcode, &arg);
		/* Execute the opcode */
		execute_opcode(opcode, &stack, line_number, arg);
	}

	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
