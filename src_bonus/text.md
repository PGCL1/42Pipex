You will get extra points if you:

1) Handle multiple pipes.

This:
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2


2) Support « and » when the first parameter is "here_doc".

This:
$> ./pipex here_doc LIMITER cmd cmd1 file
