#include "monty.h"

void file_read(char *filename, stack_t **stack)
{
	size_t n = 0;
	int line_number = 1, read;
	arguments->file = fopen(filename, "r");

	if (arguments->file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}

	while ((read = getline(&arguments->line, &n, arguments->file)) != -1)
	{
		printf("%s", arguments->line);
		if (arguments->line == NULL || arguments->line [0] == '#')
		{
			line_number++;
			continue;
		}

	}
}

char *line_tokenize(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	return (op_code);
}

void init_args(stack_t **stack)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}
	arguments->file = NULL;
	arguments->line = NULL;
}
