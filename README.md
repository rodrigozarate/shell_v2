# 0x02. C - Shell v2
## Learning Objectives

    Who designed and implemented the original Unix operating system
    Who wrote the first version of the UNIX shell
    Who invented the B programming language (the direct predecessor to the C programming language)
    Who is Ken Thompson
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
## Requirements
General

    Allowed editors: vi, vim, emacs
    All your files will be compiled on Ubuntu 14.04 LTS
    Your C programs and functions will be compiled with gcc 4.8.4
    All your files should end with a new line
    A README.md file, at the root of the folder of the project, is mandatory
    A AUTHORS.md file, at the root of the folder of the project, is mandatory
    Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    No more than 5 functions per file
    All your header files should be include guarded
    There shouldn’t be any error nor memory leak upon execution of your shell

### Allowed Functions and System Calls

    access
    chdir
    close
    execve
    fork
    stat (__xstat)
    lstat (__lxstat)
    fstat (__fxstat)
    kill
    open
    read
    signal
    wait
    waitpid
    wait3
    wait4
    write
    _exit
    dup
    dup2
    pipe
    unlink
    time
    gethostname
    geteuid
    sigaction
    sigemptyset
    select
    getpid
    __errno_location (errno macros)
    closedir
    exit
    free
    getcwd
    getline
    malloc
    opendir
    perror
    readdir
    strtok
    localtime
    getpwuid
    isatty
    printf
    fflush
    fprintf
    vfprintf
    sprintf

### Compilation

    You have to provide a Makefile in order to compile your program
    Your Makefile must define the all rule: The all rule should compile and link the source code to generate the executable hsh
    Make sure your program compiles on Ubuntu 14.04 LTS, with gcc 4.8.4
    You must compile using the flags -Wall -Werror -Wextra and -pedantic
    Your executable must be named: hsh
### TESTING
#### Interactive mode
#### Non interactive mode
