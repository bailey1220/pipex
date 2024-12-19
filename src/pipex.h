/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:20:37 by bailey            #+#    #+#             */
/*   Updated: 2024/12/18 00:27:06 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void	exec(char *cmd, char **env);
void	child(int *fd, char **argv, char **env);
void	parent(int *fd, char **argv, char **env);
void	ft_free_arr(char **arr);
char	*get_path(char *cmd, char **env);
void	exit_error(char *str);
//void	exit_error(const char *message, int exit_code);


#endif