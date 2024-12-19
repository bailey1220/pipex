/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:01:59 by bailey            #+#    #+#             */
/*   Updated: 2024/12/18 00:54:59 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

/*void	exit_error(const char *message, int exit_code)
{
	if (message)
		perror(message);
	exit(exit_code);
}
*/
/*void	exit_error(char *str)
{
	perror(str);
	exit(1);
}

void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	exec(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
		exit_error("Error splitting command");
	path = get_path(split_cmd[0], env);
	if (path)
	{
		if (execve(path, split_cmd, env) == -1)
		{
			ft_free_arr(split_cmd);
			free(path);
			exit_error("Error executing command");
		}
	}
	else
	{
		ft_free_arr(split_cmd);
		exit_error("Command not found");
	}
	ft_free_arr(split_cmd);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*exec;
	char	*split_path;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i])
	{
		path = ft_split(env[i] + 5, ':');
		if (!path)
			exit_error("Error splitting PATH variable");
		i = -1;
		while (path[++i])
		{
			split_path = ft_strjoin(path[i], "/");
			if (!split_path)
				exit_error("Error joining path");
			exec = ft_strjoin(split_path, cmd);
			free(split_path);
			if (access(exec, F_OK | X_OK) == 0)
			{
				ft_free_arr(path);
				return (exec);
			}
			free(exec);
		}
		ft_free_arr(path);
	}
	return (NULL);
}
*/
//trial version

char	*get_path(char *cmd, char **env)
{
    int		i;
    char	**path;
    char	*exec;
    char	*split_path;

    if (cmd[0] == '/' || ft_strncmp(cmd, "./", 2) == 0) // Direct path
    {
        if (access(cmd, F_OK | X_OK) == 0)
            return (ft_strdup(cmd));
        return (NULL);
    }

    i = 0;
    while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
        i++;
    if (env[i])
    {
        path = ft_split(env[i] + 5, ':');
        if (!path)
            exit_error("Error splitting PATH variable");
        i = -1;
        while (path[++i])
        {
            split_path = ft_strjoin(path[i], "/");
            if (!split_path)
                exit_error("Error joining path");
            exec = ft_strjoin(split_path, cmd);
            free(split_path);
            if (access(exec, F_OK | X_OK) == 0)
            {
                ft_free_arr(path);
                return (exec);
            }
            free(exec);
        }
        ft_free_arr(path);
    }
    return (NULL);
}

void	exec(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	if (!env)
		exit_error("Environment is missing");

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd || !split_cmd[0])
	{
		ft_free_arr(split_cmd);
		exit_error("Invalid command");
	}

	path = get_path(split_cmd[0], env);
	if (path)
	{
		if (execve(path, split_cmd, env) == -1)
		{
			ft_free_arr(split_cmd);
			free(path);
			exit_error("Error executing command");
		}
	}
	else
	{
		ft_free_arr(split_cmd);
		exit_error("Command not found");
	}
	ft_free_arr(split_cmd);
}

void	exit_error(char *str)
{
	perror(str);
	exit(1);
}

void	ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}