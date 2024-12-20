# 0x19. C - Stacks, Queues - LIFO, FIFO

# Monty Interpreter

Monty is a simple interpreter for Monty ByteCodes, a language designed to manipulate stacks and queues. This project implements the Monty interpreter in C, allowing it to read Monty bytecode files and execute the specified commands.

---

## The Monty Language

Monty 0.98 is a scripting language that is compiled into Monty byte codes. These byte codes rely on a unique stack with specific instructions for manipulation. The interpreter handles these byte codes, performing operations based on the specified opcodes.

### Monty Byte Code Files

Monty byte code files typically have the `.m` extension, though this is not mandatory. These files contain one instruction per line, and lines may include spaces before or after the opcode and its arguments. Blank lines and comments are ignored by the interpreter.

**Example:**
```plaintext
push 1
push 2
push 3
pall
```

### Objectives

Understand LIFO (Last In, First Out) and FIFO (First In, First Out) principles.
Learn the structure and use cases of stacks and queues.
Gain familiarity with the implementation of data structures.
Practice using global variables responsibly.
Develop proficiency in managing and structuring C programs.
