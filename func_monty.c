#include "monty.h"

void file_read(char *filename, stack_t **stack)
{
	size_t n = 0;
	int read;
	arguments->file = fopen(filename, "r");

	if (arguments->file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}

	while ((read = getline(&arguments->line, &n, arguments->file)) != -1)
	{
		arguments->line = line_tokenize(arguments->file);
		printf("%s", arguments->line);
		if (arguments->line == NULL || arguments->line[0] == '#')
		{
			arguments->line_number += 1;
			continue;
		}
	}
}

void *line_tokenize(void)
{
	int i = 0;
	char *op_code = NULL, *line_cpy = NULL;

	line_cpy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	strcpy(line_cpy, arguments->line);
	arguments->n_tokens = 0;
	op_code = strtok(line_cpy, DELIMITERS);
	if (op_code == NULL)
		return (NULL);

	while (op_code)
	{
		arguments->n_tokens += 1;
		op_code = strtok(NULL, DELIMITERS);
	}

	arguments->tokens = malloc(sizeof(char *) * (arguments->n_tokens + 1));
	strcpy(line_cpy, arguments->line);
	op_code = strtok(line_cpy, DELIMITERS);
	while (op_code)
	{
		arguments->tokens[i] = malloc(sizeof(char) *
					      (strlen(op_code) + 1));
		if (arguments->tokens[i] == NULL)
		{
			printf("Error: malloc failed\n");
			error_exit(stack);
		}
		strcpy(arguments->tokens[i], op_code);
		op_code = strtok(NULL, DELIMITERS);
		i++;
	}
	arguments->tokens[i] = NULL;
	free(line_cpy);
}

void init_args(stack_t **stack)
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}
	arguments->instruct = malloc(sizeof(instruction_t));
	if (arguments->instruct == NULL)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}
	arguments->file = NULL;
	arguments->line = NULL;
	arguments->n_tokens = 0;
	arguments->line_number = 0;
}
