#include "monty.h"

void error_exit(stack_t **stack)
{
	if (*stack)
		free_args(*stack);
	exit(EXIT_FAILURE);
}

void free_args(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
