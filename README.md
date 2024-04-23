# Simple Shell
![](https://ideogram.ai/api/images/direct/uU9J_UzMTVaz-1XM2g5QUw.png)
## Description
Shelloc Homes is a unique basic command interpreter that allows you to explore the limits of command execution, this tool is written in the powerful C language
The program works based on bash commands acquired from the command line interface (CLI).The command typed by the user is executed as a terminal UNIX shell
### File Description
| File | Description |
| ------ | ------ |
| main.c | Main program where the loop is made to execute commands |
| main.h | Headed file where all functions and structures are found |
| str_tools.c | Some functions of the String library |
| linkedlist.c  | Functions in charge of creating and managing linked lists |
| int_tools.c | Tools that do not belong to the string library |
| get_func.c | Functions created from the stdlib library |
|execute_command.c| Functions responsible for validation, search and execution of commands|
| error_handler.c| error manager and message generation |
|built-ins.c| Sherlock Holmes own commands |

## Install

Clone the repository
```sh
git clone https://github.com/ElWillyGod/holbertonschool-simple_shell.git
```
Enter the folder
```sh
cd holbertonschool-simple_shell
```
Compile the program with the following command
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
now you run it and you are ready to work
```sh
./hsh
```
By following these steps you are ready to work hand in hand with Shelloc Homles

authors: [ElWillyGod](https://github.com/ElWillyGod) and [MatiPrrum](https://github.com/ILoveChairs)
