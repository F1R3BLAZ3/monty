#include "monty.h"

/**
 * free_head - Free the memory allocated for the stack (head) linked list
 *
 * Description: This function frees the memory allocated for the stack linked
 * list starting from the `head` node. It recursively traverses the linked
 * list and frees each node until it reaches the end.
 *
 * If the `head` pointer is NULL, the function returns without performing any
 * operations.
 *
 * Parameters:
 *   - head: Pointer to the head node of the stack linked list
 *
 * Return: This function does not return a value.
 */

void free_head(void)
{
	if (arguments->head)
		free_stack(arguments->head);
	arguments->head = NULL;
}

/**
 * free_stack - Free the memory allocated for a stack linked list
 *
 * Description: This function frees the memory allocated for a stack linked
 * list starting from the given `head` node. It recursively traverses the
 * linked list and frees each node until it reaches the end.
 *
 * If the `head` pointer is NULL, the function returns without performing any
 * operations.
 *
 * @head: Pointer to the head node of the stack linked list
 *
 * Return: This function does not return a value.
 */

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

/**
 * free_all_args - Free the memory allocated for the arguments structure
 *
 * Description: This function frees the memory allocated for the `arguments`
 * structure and its members. It performs the following operations:
 *
 * 1. Calls the `close_file` function to close the file associated with the
 *    `arguments` structure.
 * 2. Calls the `free_tokens` function to free the memory allocated for the
 *    token array in the `arguments` structure.
 * 3. Calls the `free_args` function to free the memory allocated for the
 *    `arguments` structure itself.
 *
 * Return: This function does not return a value.
 */

void free_all_args(void)
{
	close_file();
	free_tokens();
	free_args();
}

/**
 * run_instruct - Executes the specified instruction function
 *
 * Description: This function executes the instruction function associated
 * with the current instruction stored in the `arguments` structure. It first
 * checks if the number of tokens is 0. If it is, indicating no instruction,
 * the function returns without performing any operations.
 *
 * The function then creates an empty stack pointer `stack` and passes it,
 * along with the line number, to the instruction function stored in the
 * `arguments->instruct` member. The instruction function is called through
 * the function pointer `arguments->instruct->f`.
 *
 * The execution of the instruction function may modify the stack, update the
 * `arguments` structure, or perform other operations as specified by the
 * instruction.
 *
 * Return: This function does not return a value.
 */

void run_instruct(void)
{
	stack_t *stack = NULL;

	if (arguments->n_tokens == 0)
		return;

	arguments->instruct->f(&stack, arguments->line_number);
}

/**
 * delete_stack_node - Delete the top node of the stack
 *
 * Description: This function deletes the top node of the stack by updating
 * the head pointer and freeing the memory allocated for the node. It does not
 * modify the stack length.
 *
 * Return: This function does not return a value.
 */
void delete_stack_node(void)
{
	stack_t *temp;

	temp = arguments->head;
	arguments->head = temp->next;
	free(temp);
}
