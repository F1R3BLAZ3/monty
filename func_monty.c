#include "monty.h"

/**
 * file_read - Read and process lines from a file
 * @filename: The name of the file to be read
 *
 * Description: This function opens the specified file in read mode using the
 * given filename. If the file fails to open, an error message is printed to
 * the standard error and the program exits with a failure status code.
 * The function reads each line from the file using the getline function and
 * processes the line. It increments the line number and tokenizes the line
 * using the line_tokenize function. It then extracts the instruction from the
 * tokens using the get_instruct function and executes the instruction using
 * the run_instruct function. After processing each line, the function frees
 * the memory allocated for the tokens using the free_tokens function.
 *
 * Return: This function does not return a value.
 */
void file_read(char *filename)
{
	size_t n = 0;

	arguments->file = fopen(filename, "r");

	if (arguments->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
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

/**
 * line_tokenize - Tokenize a line of code
 *
 * Description: This function tokenizes the current line of code stored in
 * the `arguments->line` variable. It allocates memory for the
 * `arguments->tokens` array to store the tokens and assigns the number of
 * tokens to `arguments->n_tokens`.
 * The function uses the `strtok` function to tokenize the line of code based
 * on the delimiters specified by the `DELIMITERS` constant. It iterates over
 * the tokens, allocates memory for each token, and copies the token into the
 * `arguments->tokens` array. The function ensures that the `arguments->tokens`
 * array is properly terminated with a NULL value. Finally, the function frees
 * the memory allocated for the temporary `line_cpy` variable.
 *
 * Return: This function does not return a value.
 */
void line_tokenize(void)
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

/**
 * init_args - Initialize the arguments structure
 *
 * Description: This function initializes the `arguments` structure by
 * allocating memory for the `arg_t` and `instruction_t` structs. It assigns
 * the allocated memory to the `arguments` and `arguments->instruct` pointers,
 * respectively. The function also initializes other members of the `arguments`
 * structure, such as `file`, `line`, `n_tokens`, and `line_number`,
 * setting them to their initial values. If any memory allocation fails,
 * the function calls `malloc_fail` to handle the error.
 *
 * Return: This function does not return a value.
 */
void init_args(void)
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

/**
 * get_instruct - Get the appropriate instruction function based on the opcode
 *
 * Description: This function matches the opcode in the first token of the
 * `arguments->tokens` array with the corresponding opcode in the `instruct`
 * array of `instruction_t` structs. If a match is found, the corresponding
 * opcode and function pointers are assigned to the `arguments->instruct`
 * structure. If no match is found, the function calls `invalid_instruct`
 * to handle the error. If there are no tokens in the `arguments` structure,
 * indicating no instructions, the function returns without assigning any
 * opcode or function.
 *
 * Return: This function does not return a value.
 */

void get_instruct(void)
{
	int i = 0;

	instruction_t instruct[] = {
	    {"push", &push}, {"pall", &pall}, {"pint", &pint}, {"pop", &pop},
	    {"mul", &mul}, {"div", &_div}, {"swap", &swap}, {"add", &add},
            {"nop", &nop}, {"sub", &sub}, {"mod", &mod},
	    {NULL, NULL}};

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
