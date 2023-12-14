#include "monty.h"

int main()
{
        stack_t *stack = NULL;
        get_opcode("push")(&stack, 1);
        get_opcode("push")(&stack, 2);
        get_opcode("push")(&stack, 3);
        get_opcode("pall")(&stack, 3);
/*
        op_push(&stack, 3);
        op_push(&stack, 2);
        op_push(&stack, 1);
        op_pall(&stack, 0);
*/
        return 0;
}
