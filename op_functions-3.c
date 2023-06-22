#include "monty.h"

/**
 * add - Add the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Description: This function adds the top two elements of the stack and
 * replaces them with the sum. It takes in a double pointer to the stack and
 * the line number of the instruction. If the stack has fewer than two
 * elements, an error message is printed to the standard error, and the
 * program exits with a failure status code. Otherwise, the top two elements
 * of the stack are retrieved, their sum is calculated, and the result is
 * stored in the second element of the stack. The first element is then
 * removed from the stack. The stack length is updated accordingly.
 *
 * Return: This function does not return a value.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	(void)stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	top = arguments->head;
	second = top->next;

	second->n = top->n + second->n;
	delete_stack_node();

	arguments->stack_length -= 1;
}

/**
 * nop - Do nothing
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Description: This function does nothing and serves as a placeholder for an
 * instruction that has no effect on the stack. It is used to satisfy the
 * requirements of the Monty bytecode language. The function takes in the
 * double pointer to the stack and the line number of the instruction, but
 * does not perform any operations on the stack. The function is declared with
 * the `(void)` parameter syntax to suppress compiler warnings about unused
 * parameters.
 *
 * Return: This function does not return a value.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * div - Divide the second element of the stack by the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Description: This function divides the value of the top element of the stack
 * by the value of the second element. The result is stored in the second
 * element of the stack, and the top element is removed. If the stack does not
 * have at least two elements, or if the top element is 0, an error message is
 * printed to the standard error, and the program is exited with a failure
 * status code.
 *
 * Return: This function does not return a value.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top = arguments->head;
	stack_t *second = top->next;

	(void)stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: cant't div, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	second->n = second->n / top->n;
	delete_stack_node();

	arguments->stack_length -= 1;
}

/**
 * mul - Multiply the second element of the stack with the top element
 * @stack: Double pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Description: This function multiplies the value of the top element of the
 * stack with the value of the second element. The result is stored in the
 * second element of the stack, and the top element is removed.
 * If the stack does not have at least two elements, an error message is
 * printed to the standard error, and the program is exited with a failure
 * status code.
 *
 * Return: This function does not return a value.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = arguments->head;
	stack_t *second = top->next;

	(void)stack;
	if (arguments->stack_length < 2)
	{
		fprintf(stderr, "L%d: cant't mul, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	second->n = second->n * top->n;
	delete_stack_node();

	arguments->stack_length -= 1;
}
