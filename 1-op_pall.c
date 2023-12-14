#include "monty.h"
/** 
 * pall - Prints all values on the stack 
 * @stack: Pointer to the head of the stack 
 * @line_number: Line number in the Monty bytecode file 
 */ 
void op_pall(stack_t **stack, unsigned int line_number)
{ 
        stack_t *current = *stack; 
 
        (void)line_number; 
 
        while (current != NULL) 
        { 
                printf("%d\n", current->n); 
                current = current->next; 
        } 
} 
