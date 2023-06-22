#include "monty.h"

arg_t *arguments = NULL;

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: Array of strings representing the command-line arguments
 *
 * Description: This is the main function that serves as the entry point of the
 * program. It takes command-line arguments and performs the necessary
 * operations based on the arguments. The function initializes the stack,
 * reads the contents of a file specified by the command-line argument,
 * and then closes the file and frees the allocated memory.
 * If the number of command-line arguments is not 2, it prints an error message
 * to the standard error and exits the program with a failure status code.
 *
 * Return: Always returns 0.
 */
int main(int argc, char **argv)
{
	(void)argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init_args();
	file_read(argv[1]);

	close_file();
	free_args();
	return (0);
}
