#include "monty.h"

/**
 * swap - Swap the top two elements of the stack
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
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
 * sub - Subtract the top element from the second top element of the stack
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Description: This function subtracts the top element of the stack from
 * the second top element. If the stack contains less than two elements,
 * it prints an error message and exits with a failure status code. The
 * result is stored in the second top element, and the top element is removed,
 * making the stack one element shorter.
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

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Double pointer to the stack (not used in this implementation)
 * @line_number: Line number of the opcode being executed
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (arguments->head->n < 0 || arguments->head->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (char)(arguments->head->n));
}
