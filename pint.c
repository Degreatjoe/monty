#include "monty.h"
/**
 * pint - The opcode pint prints the value at the top of the stack.
 * @stack: the stack.
 * @line_number: the number of lines.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the value at the top of the stack */
	printf("%d\n", (*stack)->n);
}
