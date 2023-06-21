#include "monty.h"

int main(int argc, char *argv)
{
        stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&stack);
	}
        file_read(argv[1], &stack);

        return (0);
}
