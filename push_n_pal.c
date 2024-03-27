#include "monty.h"
/**
 * push - The opcode push pushes an element to the stack.
 * @stack: the stack.
 * @line_number: the line number.
 * @arg: the argument passed.
 */
/* Implement the 'push' opcode */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	int n;
	stack_t *new_node;

	/* Check if argument exists */
	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Convert string to int using atoi */
	n = atoi(arg);

	/* Allocate node */
	new_node = malloc(sizeof(stack_t));

	/* Check if malloc failed */
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Put in the data */
	new_node->n = n;

	/* Make next of new node as head and previous as NULL */
	new_node->next = (*stack);
	new_node->prev = NULL;

	/* Change prev of head node to new node */
	if ((*stack) != NULL)
		(*stack)->prev = new_node;

	/* Move the head to point to the new node */
	(*stack) = new_node;
}
/**
 * pall - The opcode pall prints all the values on the stack.
 * @stack: the stack.
 * @line_number: the number of lines.
 */
/* Implement the 'pall' opcode */
void pall(stack_t **stack)
{
	stack_t *temp;

	/* Start from the top of the stack */
	temp = *stack;

	/* Traverse down the stack and print values */
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
