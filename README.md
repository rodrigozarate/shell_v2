# 0x02. C - Shell v2
## Learning Objectives

    How does a shell work
    What are a pid and a ppid
    How to manipulate the environment of the current process
    What is the difference between a function and a system call
    How to create processes
    What are the three prototypes of main
    How does the shell use the PATH to find the programs
    How to execute another program with the execve system call
    How to suspend the execution of a process until one of its children terminates
    What is EOF / “end-of-file”?
    How to redirect the content of a file into another file
    What is a pipeline
    How to setup a pipe
    How to setup a pipe between two processes

###  Project to be done in teams of 2 people (your team: Ronald Aguirre, Rodrigo Zárate Algecira)

### Compilation

    You have to provide a Makefile in order to compile your program
    Your Makefile must define the all rule: The all rule should compile and link the source code to generate the executable hsh
    Make sure your program compiles on Ubuntu 14.04 LTS, with gcc 4.8.4
    You must compile using the flags -Wall -Werror -Wextra and -pedantic
    Your executable must be named: hsh
### TESTING
#### Interactive mode
#### Non interactive mode
## BUILTINS
### exit
Terminate the program
`exit`
### XD
`XD`
Put a smile on your face.
--------------------------
-X---------X---DDDDDD-----
---X-----X-----D------D---
-----X-X-------D-------D--
------X--------D-------D--
-----X-X-------D-------D--
---X-----X-----D------D---
-X---------X---DDDDDDD----
--------------------------
### env
`env`
Prints environtment variables
### cd
`cd`
Change current proccess directory
options
    -   Previous directory
    .   Same directory
    ..  Parent directory
    ~   Home directory
