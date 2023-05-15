## Monty Bytecode Interpreter
This is a Monty bytecode interpreter developed in C. Monty is a simple, high-level programming language that is intended to be used as a scripting language.

# Requirements
## General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You allowed to use a maximum of one global variable
No more than 5 functions per file
You are allowed to use the C standard library
The prototypes of all your functions should be included in your header file called monty.h
Don’t forget to push your header file
All your header files should be include guarded
You are expected to do the tasks in the order shown in the project

## Compilation & Output
Your code will be compiled this way:
```$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty```
Any output must be printed on stdout
Any error message must be printed on stderr

## Supported operations
The interpreter supports the following operations:

- push	Pushes an element to the stack
- pall	Prints all elements in the stack
- pint	Prints the value at the top of the stack
- pop	Removes the top element from the stack
- swap	Swaps the top two elements in the stack
- add	Adds the top two elements in the stack
- nop	Does nothing

# Functions

- get_opcode_function: Matches opcodes with their respective functions.
- _push: Pushes an element to the stack.
- _pall: Prints all elements in the stack.
- _pint: Prints the value at the top of the stack.
- _pop: Removes the top element from the stack.
- _swap: Swaps the top two elements in the stack.
- _add: Adds the top two elements in the stack.
- _nop: Does nothing.
- free_list: Frees the stack.


# authors

Francoherrera123
NahuelSilva28
