#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	if (arguments->n_tokens <= 1 || !(is_number(arguments->tokens[1])))
	{
		free_args();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_fail();
	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = (int)atoi(arguments->tokens[1]);

	if (arguments->head != NULL)
	{
		(*stack)->next = arguments->head;
		arguments->head->prev = *stack;
	}
	arguments->head = *stack;
	arguments->stack_length += 1;
}

int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (arguments->head == NULL)
		return;

	(void)line_number;
	(void)stack;

	tmp = arguments->head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arguments->head->n);
}
