#ifndef MONTY_H
#define MONTY_H

#define MAX_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_stack(stack_t *stack);
int is_digit(char *s);
int is_empty_line(char *s);
void (*get_opcode(char *s))(stack_t **, unsigned int);
void op_push(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
