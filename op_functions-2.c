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

/**
 * sub - Subtract the top element of the stack from the second top element
 *
 * Description: This function subtracts the top element of the stack from
 * the second top element. If the stack contains less than two elements, it
 * prints an error message indicating that the stack is too short, followed
 * by a new line, and exits with a failure status code.
 * The result of the subtraction is stored in the second top element of the
 * stack, and the top element is removed, making the stack one element shorter.
 * At the end, the top element of the stack contains the result.
 *
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number being executed in the Monty file
 *
 * Return: This function does not return a value.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	(void)stack;

	if (arguments->head == NULL || arguments->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = arguments->head->next->n - arguments->head->n;

	pop(&arguments->head, line_number);
	arguments->head->n = result;
}
