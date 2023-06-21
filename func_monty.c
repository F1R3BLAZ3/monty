#include "monty.h"

void file_read(char *filename, stack_t **stack)
{
	char *buf = NULL, *line;
	size_t n = 0;
	int line_number = 1, read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}

	while ((read = getline(&buf, &n, file)) != -1)
	{
		line = line_tokenize(buf);
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
