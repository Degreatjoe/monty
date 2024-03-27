#include "monty.h"
/**
 * execute_opcode - a function that executes the various opcode.
 * @opcode: the opcode to execute.
 * @stack: the stack of commands in the opcode.
 * @line_number: the number of line.
 * @arg: the argument
*/

void execute_opcode(char *opcode, stack_t **stack,
					unsigned int line_number, char *arg)
{
	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "mul") == 0)
	{
		mul(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(stack, line_number);
	}
	else if (strcmp(opcode, "div") == 0)
	{
		divint(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
