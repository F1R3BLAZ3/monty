#include "monty.h"

/**
 * push - Pushes an integer onto the stack
 *
 * Description: This function adds a new node to the stack with the value
 * specified in the second token. It first checks if the number of tokens
 * is greater than 1 and if the second token is a valid number.
 * If not, it frees the memory allocated for the arguments structure, prints
 * an error message to stderr, and exits with failure.
 *
 * The function allocates memory for a new stack node and assigns the value
 * of the second token to the node's 'n' member.
 *
 * If the stack is not empty, the new node is linked to the head of the stack.
 * 'head' and 'stack_length' members of the arguments structure are updated.
 *
 *   @stack: Pointer to a pointer to the head of the stack
 *   @line_number: The line number where the push operation is performed
 *
 * Return: This function does not return a value.
 */

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

/**
 * is_number - Checks if a string is a valid number
 *
 * Description: This function checks if the given string represents a valid
 * integer number. It iterates over each character of the string and verifies
 * if it is a digit or a negative sign in the case of the first character.
 *
 *  @str: Pointer to the string to be checked
 *
 * Return:
 *   - 1 if the string is a valid number
 *   - 0 if the string is not a valid number
 */

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

/**
 * pall - Prints all the values on the stack, starting from the head
 *
 * Description: This function traverses the stack linked list starting from
 * the head and prints the value of each node. If the head is NULL (stack is
 * empty), the function returns without performing any operations.
 *
 * @stack: Pointer to a pointer to the head of the stack
 * @line_number: The line number where the pall operation is performed
 *
 * Return: This function does not return a value.
 */

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

/**
 * pint - Prints the value at the top of the stack (head)
 *
 * Description: This function prints the value at the top of the stack (head).
 * If the stack is empty (head is NULL), it prints an error message to stderr,
 * frees memory allocated for the arguments structure, and exits with failure.
 *
 * @stack: Pointer to a pointer to the head of the stack
 * @line_number: The line number where the pint operation is performed
 *
 * Return: This function does not return a value.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	if (arguments->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arguments->head->n);
}
