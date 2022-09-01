
# Simple Shell
Simple Shell is a simple implementation of the UNIX command interpreter project for ALX school students, where we build and understand how the simple shell command works. The project is to replicate the basic functionality of a LINUX Shell
<img with = "150" src ="https://github.com/Giddyspurz/simple_shell/blob/main/imag/LOGO.png" />


## Learning Objectives

- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## Requirements

- All your files will be compiled on Ubuntu 14.04 LTS.
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic.
- All your files should end with a new line.
- Your code should use the Betty style.
- No more than 5 functions per file.
- All your header files should be include guarded.
- Use system calls only when you need to.

## Contained files
| FILE | DESCRIPTION FILE |
| --- | --- |
| header.h | contains the prototypes of the functions |
| PATH.c | contain functions search command in the PATH	|
| simple_shell.c | contain Main functions |
| str_tok.c | contain function split buffer and aux |
| _atoi.c | convert string in a number |
| _cd.c | Function change directory |
| _execve.c| execute commnads with fork |
| buffer.c | works in buffer |
| node.c | creates and deletes node |
| set_buffer.c | set buffer with NULL |
| setenv.c | overwrite environment |
| str_cmp.c | function compare string |
| str_cpy.c | function copy stryng |
| str_len.c | function count leng string |
| str_tok.c | function break strings in tokens |
| unsetenv.c | function remove variable environment | 
| free.c | free dinamic memory (malloc) |
| errors.c | Management errors |
| README.md | README file |

# Clone Code

simple_shell is clone in your terminal using the next code

git clone: https://github.com/Giddyspurz/simple_shell

## How to Copile the code

gcc -Wall -Wextra -Werror -pedantic *.c -o hsh

## Run the code

./hsh

## Examples to Use
### Basics
SHell reads the entry, it proceeds through many sequence of operations and divide it in words and operators.

```ShellSession
ls -la
```

```ShellSession
vagrant@vagrant-ubuntu-trusty-64:$ ./hsh
> ls -la
total 128
drwxrwxr-x 4 vagrant vagrant 4096 ago 20 09:59 .
drwxrwxr-x 4 vagrant vagrant 4096 ago 19 20:14 ..
-rw-rw-r-- 1 vagrant vagrant  425 ago 19 17:42 _atoi.c
-rw-rw-r-- 1 vagrant vagrant  158 ago 19 17:42 AUTHORS
-rw-rw-r-- 1 vagrant vagrant 3675 ago 20 09:59 buffer.c
-rw-rw-r-- 1 vagrant vagrant 2718 ago 19 22:01 _cd.c
-rw-rw-r-- 1 vagrant vagrant  498 ago 19 17:42 errors.c
-rw-rw-r-- 1 vagrant vagrant 2409 ago 20 09:59 _execve.c
-rw-rw-r-- 1 vagrant vagrant  342 ago 19 17:42 free.c
-rw-rw-r-- 1 vagrant vagrant  675 ago 19 22:02 function.c
drwxrwxr-x 8 vagrant vagrant 4096 ago 20 10:04 .git
-rw-rw-r-- 1 vagrant vagrant 3994 ago 19 22:01 header.h
drwxrwxr-x 2 vagrant vagrant 4096 ago 19 17:42 imag
-rw-rw-r-- 1 vagrant vagrant 3222 ago 19 17:42 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant 2895 ago 19 22:01 node.c
-rw-rw-r-- 1 vagrant vagrant 3375 ago 19 22:01 PATH.c
-rw-rw-r-- 1 vagrant vagrant  588 ago 19 22:02 _print_binary.c
-rw-rw-r-- 1 vagrant vagrant 1168 ago 19 22:03 _printf.c
-rw-rw-r-- 1 vagrant vagrant  607 ago 19 22:03 print_number.c
-rw-rw-r-- 1 vagrant vagrant  575 ago 19 22:03 _print_o.c
-rw-rw-r-- 1 vagrant vagrant  572 ago 19 22:03 _print_u.c
-rw-rw-r-- 1 vagrant vagrant 1236 ago 19 22:03 _print_x.c
-rw-rw-r-- 1 vagrant vagrant 1259 ago 19 22:03 _print_X.c
-rw-rw-r-- 1 vagrant vagrant 3593 ago 20 10:04 README.md
-rw-rw-r-- 1 vagrant vagrant  326 ago 19 17:42 set_buffer.c
-rw-rw-r-- 1 vagrant vagrant 1757 ago 19 22:01 setenv.c
-rw-rw-r-- 1 vagrant vagrant 2552 ago 19 22:01 simple_shell.c
-rw-rw-r-- 1 vagrant vagrant  455 ago 19 17:42 str_cmp.c
-rw-rw-r-- 1 vagrant vagrant  499 ago 19 17:42 str_cpy.c
-rw-rw-r-- 1 vagrant vagrant  225 ago 19 17:42 str_len.c
-rw-rw-r-- 1 vagrant vagrant 2923 ago 19 17:42 str_tok.c
-rw-rw-r-- 1 vagrant vagrant 1890 ago 19 17:42 unsetenv.c
$ pwd
/home/vagrant/simple_shell
$ /bin/pwd
/home/vagrant/simple_shell
```

## Authors
Gad Chege<br>
Jesse Momanyi<br>
