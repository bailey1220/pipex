/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:19:12 by bachai            #+#    #+#             */
/*   Updated: 2024/12/17 00:29:50 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
    int fd[2];
    pid_t   pid;

    if (argc < 5)
        exit_error("Too few arguments");
    if (argc > 5)
         exit_error("Too many arguments");
    if (pipe(fd) == -1)
         exit_error("pipe failed");
    pid = fork();
    if (pid == -1)
         exit_error("fork failed");
    if (pid == 0)
        child(fd, argv, env);
    parent(fd, argv, env);

}
// child process write to the pipe using the write end
void	child(int *fd, char **argv, char **env)
{
    int infile;
    
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
         exit_error("Error: file not found");
    close(fd[0]); 
    //the read end of the pipe created by the parent process
    dup2(infile, 0);
    // Redirects the standard input (stdin, fd[0]) to the file opened earlier (infile).
    // Read input from infile instead of keyboard
    dup2(fd[1], 1);
    // Redirects the standard output (stdout fd[1]) to write end of the pipe (fd[1])
    // Write to the pipe instead of terminal
    exec(argv[2], env);
    //Execute the first command
}
// The parent reads from the pipe using the read end
void	parent(int *fd, char **argv, char **env)
{
    int outfile;
    
    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (outfile == -1)
         exit_error("Error: file not found");
    close (fd[1]);
    // close the write end of the pipe created by the parent process
    // free up resources and prevent inteferences
    dup2(outfile, 1);
    // Redirects the standard output (stdout, fd[1]) to the file opened earlier (outfile)
    // output produced by the executed command will be written to the outfile instead of being displayed on the terminal.
    dup2(fd[0], 0);
    // Redirects the standard input (stdin, file descriptor 0) to the read end of the pipe (fd[0]).
    // command executed will read its input from the pipe instead of the keyboard or terminal.
    exec(argv[3], env);
    // Execute the second command
}