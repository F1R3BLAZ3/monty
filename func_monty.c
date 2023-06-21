#include "monty.h"

void file_read(char *filename)
{
	size_t n = 0;
	arguments->file = fopen(filename, "r");

	if (arguments->file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&arguments->line, &n, arguments->file) != -1)
	{
		arguments->line_number += 1;
		line_tokenize();
		get_instruct();
		run_instruct();
		free_tokens();
	}
}

void line_tokenize()
{
	int i = 0;
	char *op_code = NULL, *line_cpy = NULL;

	line_cpy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	strcpy(line_cpy, arguments->line);
	arguments->n_tokens = 0;
	op_code = strtok(line_cpy, DELIMITERS);
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
			malloc_fail();
		strcpy(arguments->tokens[i], op_code);
		op_code = strtok(NULL, DELIMITERS);
		i++;
	}
	arguments->tokens[i] = NULL;
	free(line_cpy);
}

void init_args()
{
	arguments = malloc(sizeof(arg_t));
	if (arguments == NULL)
		malloc_fail();

	arguments->instruct = malloc(sizeof(instruction_t));
	if (arguments->instruct == NULL)
		malloc_fail();

	arguments->file = NULL;
	arguments->line = NULL;
	arguments->n_tokens = 0;
	arguments->line_number = 0;
}

void get_instruct(void)
{
	int i = 0;

	instruction_t instruct[] = {
		{"push", &push},{"pall", &pall},
		{NULL, NULL}
	};

	if (arguments->n_tokens == 0) /* no instructions */
		return;
	
	for (; instruct[i].opcode != NULL; i++)
	{
		if (strcmp(instruct[i].opcode, arguments->tokens[0]) == 0)
		{
			arguments->instruct->opcode = instruct[i].opcode;
			arguments->instruct->f = instruct[i].f;
			return;
		}
	}
	invalid_instruct();
}

void run_instruct(void)
{
	stack_t *stack = NULL;

	if (arguments->n_tokens == 0)
		return;
	
	arguments->instruct->f(&stack, arguments->line_number);
}
