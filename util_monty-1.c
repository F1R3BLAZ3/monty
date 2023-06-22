#include "monty.h"

/**
 * free_args - Free the memory allocated for the arguments structure
 *
 * Description: This function frees the memory allocated for the `arguments`
 * structure and its members. It first checks if the `arguments` pointer is
 * NULL. If it is, the function returns without performing any operations.
 *
 * The function then checks if the `arguments->instruct` pointer is not NULL.
 * If it is not NULL, the memory allocated for the `arguments->instruct`
 * structure is freed using the `free` function, and the pointer is set to
 * NULL.
 *
 * Next, the function calls the `free_head` function to free the memory
 * allocated for the stack (`head`) linked list.
 *
 * The function then checks if the `arguments->line` pointer is not NULL.
 * If it is not NULL, the memory allocated for the `arguments->line` string
 * is freed using the `free` function, and the pointer is set to NULL.
 *
 * Finally, the memory allocated for the `arguments` structure itself is
 * freed using the `free` function.
 *
 * Return: This function does not return a value.
 */
void free_args()
{
	if (arguments == NULL)
		return;

	if (arguments->instruct)
	{
		free(arguments->instruct);
		arguments->instruct = NULL;
	}

	free_head();

	if (arguments->line)
	{
		free(arguments->line);
		arguments->line = NULL;
	}

	free(arguments);
}

/**
 * malloc_fail - Handle malloc failure
 *
 * Description: This function is called when a `malloc` operation fails to
 * allocate the requested memory. It prints an error message to the standard
 * error output, indicating that `malloc` failed. Then, it calls the
 * `free_args` function to free the allocated memory for the `arguments`
 * structure and its associated members.
 * Finally, it exits the program with a failure status code using the `exit`
 * function.
 *
 * Return: This function does not return a value.
 */
void malloc_fail()
{
	fprintf(stderr, "Error: malloc failed\n");
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * close_file - Close the file associated with arguments
 *
 * Description: This function checks if the file pointer `arguments->file` is
 * not NULL, indicating that a file has been opened. If the file pointer is not
 * NULL, the function closes the file using the `fclose` function.
 * After closing the file, it sets the `arguments->file` pointer to NULL to
 * indicate that the file is closed. If the file pointer is already NULL,
 * the function returns without performing any action.
 *
 * Return: This function does not return a value.
 */
void close_file(void)
{
	if (arguments->file == NULL)
		return;
	fclose(arguments->file);
	arguments->file = NULL;
}

/**
 * invalid_instruct - Handle invalid instruction error
 *
 * Description: This function is called when an unknown instruction is
 * encountered during the execution of the program. It prints an error message
 * to the standard error, indicating the line number and the unknown
 * instruction. Then, it closes the file, frees the tokens,
 * frees the arguments, and exits the program with a failure status code.
 *
 * Return: This function does not return a value.
 */
void invalid_instruct(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", arguments->line_number, arguments->tokens[0]);
	close_file();
	free_tokens();
	free_args();
	exit(EXIT_FAILURE);
}

void free_tokens(void)
{
	int i = 0;

	if (arguments->tokens == NULL)
		return;

	while (arguments->tokens[i])
	{
		free(arguments->tokens[i]);
		i++;
	}
	free(arguments->tokens);
	arguments->tokens = NULL;
}
