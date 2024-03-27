#include "monty.h"
/**
 * parse_line - this function parse each line from *line
 * to opcode and arg.
 * @line: the line of commands in the file.
 * @opcode: the opcode.
 * @arg: the arg.
*/
void parse_line(char *line, char **opcode, char **arg)
{
	/* Get the opcode */
	*opcode = strtok(line, " \t\n");

	/* Get the argument */
	*arg = strtok(NULL, " \t\n");
}
