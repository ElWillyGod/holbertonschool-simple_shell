# Simple Shell
![](https://designerapp.officeapps.live.com/designerapp/document.ashx?path=/6b45b04a-32fa-47cf-b451-3863ad739ea3/DallEGeneratedImages/dalle-22b23809-2ce8-417e-8eee-2fe82c22aa030251688462381565597500.jpg&dcHint=BrazilSouth&fileToken=12297fdb-1630-4135-b07f-8545d44b76fd)
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
|built-ins.c| Shelloc Holmes own commands |

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
