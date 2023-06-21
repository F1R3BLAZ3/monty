#include "monty.h"

arg_t *arguments = NULL;

int main(int argc, char **argv)
{
        stack_t *stack;
        (void) argv;

	stack = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
        init_args(&stack);
        file_read(argv[1]);

        close_file();
        free_args();
        return (0);
}
