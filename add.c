#include "monty.h"
/**
 * add - The opcode adds subtracts the top element of the stack,
 * from the second top element of the stack.
 * @stack: the stack.
 * @line_number: the number of line.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
