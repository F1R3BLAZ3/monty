#ifndef MONTY_H
#define MONTY_H

/* Macros */

#define _GNU_SOURCE
#define DELIMITERS "\t\r\n "

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
        unsigned int line_number;
        char **tokens;
        int n_tokens;
        stack_t *head;
        int stack_length;
        instruction_t *instruct;
} arg_t;

/* Global Variables */

extern arg_t *arguments;

/* Function Declarations */

void file_read(char *filename);
void line_tokenize();
void init_args();
void get_instruct(void);
void run_instruct(void);
void free_args(void);
void malloc_fail(void);
void close_file(void);
void invalid_instruct(void);
void free_tokens(void);
int is_number(char *str);
void free_head(void);
void free_stack(stack_t *head);

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
