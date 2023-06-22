#include "monty.h"

void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);
	arguments->head = NULL;
}

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack(head->next);
	}

	free(head);
}

void free_all_args(void)
{
	close_file();
	free_tokens();
	free_args();
}
