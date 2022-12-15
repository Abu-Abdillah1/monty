#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int push_val;

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


/**
 * struct global_variables - stores data of global variables
 * @file: opcode
 * @push_val: value of push operation
 * @buffer: pointer to the value
 */
typedef struct global_variables
{
	FILE *file;
	int push_val;
	char *buffer;
} global_variable;

global_variable global_var;

void read_file(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
instruct_func get_op_func(char *s);

void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);


void _sub(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

void free_list(stack_t *head);
void dobfree(stack_t **stack);
void dobfree2(stack_t **stack);
int _isalpha(int c);

#endif /* MONTY_H */
