//----- Writing a Shell in C-----//
By Juan Manuel Trevino
Linkedin: https://www.linkedin.com/in/juanmanueltrevino/
Email me at jmt2235@columbia.edu

Purpose - The purpose of this project is to begin transitioning from post
CS3157 (Advanced Programming at Columbia University) to exploring concepts
and projects that I find interesting (outside of academia)! 

In writing a C-Shell, I will be recapping concepts covered in the 3157 
and gain the confidence to tackle a larger project such as writing a 
compiler, an operating system, or a VM!

//----- How to use this Shell -----//
TODO

//----- Timeline -----//
01/07/21 - I finally set up the dev environment I will be working in. To
best replicate both my environment at work and in 3157, I set up a
raspberiry pi running raspian and am SSH'ing into the pi. 
01/09/21 - Today I will be exploring how shells work and plan how to 
approach the project.

//----- Notes -----//
What is a shell? command interpreter that allows user to access OS 
services, execute/Invoke programs, etc

For example, my current bash shell displays the following
jtrevino@raspberrypi:~/dev/C-Shell $

When the shell receives a command (such as 'ls -alf') it is processed
in the following method:
1. It takes the input and saves it in an array of characters
2. Null terminates the string
3. Replaces spaces with null terminator
4. Verify whether the command user inputted is correct (i.e. in the
example above, the shell will first check "ls\0" and then "-alf\0")
5. Locate the command in the PATH environment variable. 
   For example, ls is actually /bin/ls and the ls file gets ran.



//----- Important Concepts -----// 
What are environment variables (Such as PATH in this case)
Dynamically named value that can affect the way running processes
will behave on a computer. 
PATH is a list of directory paths. When the user types a command without 
providing the full path, this list is checked to see whether it contains 
a path that leads to the command.


//----- Resources -----//
https://medium.com/@765/how-the-shell-works-internally-when-entering-a-command-42f08458870


