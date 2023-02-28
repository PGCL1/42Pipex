# 42 Pipex

**In progress, knowledge compiling**

A pipe is a communication channel between two processes enabling read and writing. The pipe function takes in an array of two [[fd]]. 

The structure of a pipe is as follows:

***fd[0] >> pipe >> fd[1]***
fd[0] is the reading point.
fd[1] is the writing point.

Once an fd has been opened by a process, it needs to be manually closed and this has to be done for both processes in order to read or write from the pipe.
	i.e.   - close fd[0] -> to write in fd[1] -> then we need to close fd[1]
			- close fd[1] -> to read from fd[0] -> then we need to close fd[0]

As part of writing code for pipe, error hanlding is a must. As such all commands should be checked for possible errors.

Child processes and parent processes don't execute one after the other rather they are executed in parallel. ***The Child process is always id = 0 and the parent is id = 1***. When dealing with the child processes,  we need to set up a condition in order to wait for the completed execution of our child processes: *wait(NULL).

From what I understood pipes enable you to optimize the processing power of your machine by splitting up tasks into different processes that run parallely to achieve a goal. For example, parsing a huge array with one process might be time consuming however parsing the same array with multiple processes that all run parallely will achieve the result faster.

Basically through pipes, we are able to [[redirect a standard output]] from a process to another.

With the fork function, we are able to duplicate the main process and create a child process from it. Should we decide to create another fork from the child process, we will create two new processes. However if we are in the parent process, meaning we are in id != 0, we will only create one more process, bringing our total to 3 processes.

A pid_t is the number associated to a specifiied process. When forking a process, we will duplicate it and have as a result two processes. pid_t of 0 is the child and the other is the parent.