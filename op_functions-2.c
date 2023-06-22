#include "monty.h"

/**
 * swap - Swap the top two elements of the stack
 *
 * Description: This function swaps the positions of the top two elements
 * of the stack. If the stack contains less than two elements, it prints
 * an error message and exits with a failure status code.
 *
 * Return: This function does not return a value.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = arguments->head;
	stack_t *second = arguments->head->next;
	(void)stack;

	if (arguments->head == NULL || arguments->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next = second->next;
	if (second->next != NULL)
		second->next->prev = top;

	second->prev = NULL;
	second->next = top;
	top->prev = second;

	arguments->head = second;
}
