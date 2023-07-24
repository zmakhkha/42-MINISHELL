# Minishell Project

This is a minishell project developed as part of 42 common core cursus. The minishell aims to replicate the basic functionalities of a shell program, allowing users to execute commands, handle input/output redirection, implement built-in commands, and more.

## Features

- Command execution: Execute commands entered by the user.
- Input/output redirection: Support input and output redirection using `<` and `>` operators.
- Pipes: Allow command chaining using pipes `|`.
- Built-in commands: Implement built-in commands such as `cd`, `echo`, `env`, `export`, `unset`, and `exit`.
- Environment variables: Support managing and expanding environment variables.
- Signal handling: Handle signals like `Ctrl-C` and `Ctrl-\` gracefully.
- Error handling: Provide informative error messages and handle errors effectively.

## Getting Started

To get started with the minishell project, follow these steps:

1. Clone the repository:
   ```
   git clone git@github.com:zmakhkha/MINISHELL.git && cd MINISHELL
   ```

2. Build the project:
   ```
   make
   ```

3. Run the minishell:
   ```
   ./minishell
   ```

## Usage

Once you have the minishell running, you can start using it to execute commands. Here are some examples:

- Execute a command:
  ```
  $ ls -la
  ```

- Redirect input from a file:
  ```
  $ cat < input.txt
  ```

- Redirect output to a file:
  ```
  $ echo "Hello, world!" > output.txt
  ```

- Chain commands using pipes:
  ```
  $ lsof / | awk '{ if($7 > 1048576) print $7/1048576 "MB" " " $9 " " $1 }' | sort -n -u | tail
  ```

  - Chain commands using operators:
  ```
  $ mkdir test && cd test || echo  "failed" && touch file01 && ls -la
  ```

- Use built-in commands:
  ```
  $ cd /path/to/directory
  $ echo $HOME
  $ export VAR=value
  ```

## Command Syntax

The minishell supports the following command syntax:

- Basic command execution: `command [arguments]`
- Input redirection: `command < input_file`
- Output redirection: `command > output_file`
- Pipe command chaining: `command1 | command2`
- Environment variable expansion: `echo $HOME`
- && and || operators: `command1 | command2 && command3 | command4 || command5 | command6`
- parentheses priority: `command1 | (command2 && command3) | command4 || (command5 | command6)`

## How Does it works ?
In the minishell project, the process of interpreting and executing user commands involves several important components that work together seamlessly. These components include the tokenizer, parser, lexer, abstract syntax tree (AST), and command execution. Let's explore each of these components and their role in the minishell project:

1. Tokenizer:
   The tokenizer is responsible for breaking down the user input into smaller meaningful units called tokens. Tokens are the building blocks of the command, and they represent individual elements such as commands, arguments, redirection symbols, pipes, etc. The tokenizer takes the raw user input and converts it into a sequence of tokens, which are then passed to the parser.

2. Lexer:
   The lexer, also known as the lexical analyzer or scanner, is a crucial part of the tokenizer. It identifies the different token types and extracts them from the input string. It performs tasks such as whitespace removal, identifying keywords, detecting operators, and handling special characters. The lexer produces a stream of tokens that are then fed into the parser.

3. Parser:
   The parser takes the stream of tokens produced by the tokenizer and analyzes their structure to create a more organized representation of the command. It parses the tokens according to the rules of the shell's grammar and generates an abstract syntax tree (AST). The AST is a hierarchical representation of the command's structure, making it easier to interpret and execute.

4. Abstract Syntax Tree (AST):
   The abstract syntax tree is a tree-like data structure that represents the syntax of the user's command. Each node in the tree corresponds to a different element of the command, such as commands, arguments, redirections, and pipes. The AST helps maintain the command's structural integrity, allowing for better handling of complex commands with multiple components.

5. Command Execution:
   Once the AST is generated, the minishell can traverse the tree and execute the command accordingly. The execution process involves implementing the logic for built-in commands, handling input/output redirections, setting up pipes for command chaining, and managing environment variables. The command execution phase uses the information from the AST to perform the required actions and produce the desired output.

Overall, the process flow in the minishell project starts with the user input, which is tokenized and lexed to generate a stream of tokens. The parser then constructs an abstract syntax tree from the token stream, allowing for better command representation. Finally, the command execution phase utilizes the AST to execute the command, applying the necessary functionalities such as input/output redirections and pipes to produce the expected results.

By dividing the command interpretation process into these distinct components, the minishell project achieves modularity, flexibility, and maintainability, making it easier to extend and enhance the functionality of the shell.
## Contributors
- Ayman el filali
- Zakaria Makhkhas
