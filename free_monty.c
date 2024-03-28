#include "monty.h"
/**
 * free_monty - free the stack
 * @head: points to list
 */
void free_monty(stack_t **head)
{
	stack_t *freed;

	while ((*head) != NULL)
	{
		freed = (*head);

		(*head) = (*head)->next;

		free(freed);
	}
}
