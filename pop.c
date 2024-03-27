#include "monty.h"
/**
 * pop - The opcode pop removes the top element of the stack.
 * @stack: the stack.
 * @line_number: the line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Save the top element of the stack */
	temp = *stack;

	/* Move the top of the stack to the next element */
	*stack = (*stack)->next;

	/* Free the old top element of the stack */
	free(temp);
}
