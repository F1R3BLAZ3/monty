#include "monty.h"

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

void malloc_fail()
{
        fprintf(stderr, "Error: malloc failed\n");
        free_args();
        exit(EXIT_FAILURE);
}

void close_file(void)
{
        if (arguments->file == NULL)
                return;
        fclose(arguments->file);
        arguments->file = NULL;
}

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
