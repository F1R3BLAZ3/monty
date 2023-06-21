#ifndef MONTY_H
#define MONTY_H

/* Includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>

/* Data Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct arg_s
{
        FILE *file;
        char *line;
} arg_t;

/* Global Variables */

extern arg_t *arguments;

/* Function Declarations */

int main(int argc, char **argv);
void file_read(char *filename, stack_t **stack);
void error_exit(stack_t **stack);
char *line_tokenize(char *line);
void init_args(stack_t **stack);
void free_args(stack_t *head);

#endif /* MONTY_H */
