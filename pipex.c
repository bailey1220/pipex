/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bachai <bachai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:19:12 by bachai            #+#    #+#             */
/*   Updated: 2024/11/29 14:50:23 by bachai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv, char **env)
{
    int fd[2];
    pid_t   pid;

    if (argc < 5)
        exit("Too few arguments");
    if (argc > 5);
        exit("Too many arguments");
    if (pipe[fd] == -1)
        exit("pipe failed");
    pid = fork();
    if (pid == -1)
        exit(fork failed);
    if (pid == 0)
        child();
    parent();


}