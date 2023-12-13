
## Monty Interpreter
The Monty Interpreter is a simple program designed to interpret and execute Monty bytecode files. Monty is a programming language that uses a stack data structure to process instructions. This interpreter takes a Monty bytecode file as an argument and executes the operations specified in the file.

## Usage
To use the Monty Interpreter, provide a Monty bytecode file as a command-line argument. The interpreter will read the file, parse its contents, and execute the corresponding stack operations.

     ./monty file.m**

## Monty Bytecode
Monty bytecode files contain a series of instructions, each represented by a single line in the file. These instructions manipulate a stack data structure using various operations such as push, pop, add, sub, and more.

## Example
Here's an example of a simple Monty bytecode file:

1. push 1
2. push 2
3. push 3
4. pall

This file, when provided to the Monty Interpreter, would push three values onto the stack (1, 2, and 3) and then print all the values in the stack (pall).
