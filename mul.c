#include "monty.h"
/**
 * mul - The opcode mul multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: the stack.
 * @line_number: the number of line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
