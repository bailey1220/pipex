/*#include "pipex.h"

void    exit(char *str)
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

// `exec` function to find the command path and execute it
void exec(char *cmd, char **env)
{
    char **split_cmd;
    char *path;

    // Split the command into arguments
    split_cmd = ft_split(cmd, ' ');
    if (!split_cmd)
        exit ("Error: Command split failed\n");
    // Get the full path of the command
    path = get_path(split_cmd[0], env);
    if (path) 
    {
        // Execute the command with its arguments
        if (execve(path, split_cmd, env) == -1)
        {
            exit("Error: execve failed for command");
            ft_putendl_fd(split_cmd[0], 2);
            ft_free_arr(split_cmd);
            free(path);
        }
    } 
    else 
    {
        // If command is not found
        exit("Error: command not found: ");
        ft_putendl_fd(split_cmd[0], 2);
        ft_free_arr(split_cmd);
    }
    ft_free_arr(split_cmd);  // Free the command arguments array after use
}

// `get_path` function to locate the executable path from the PATH variable
char *get_path(char *cmd, char **env)
{
    int i = 0;
    char **path;
    char *exec;
    char *split_path;

    // Locate the "PATH=" variable using ft_strncmp
    while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
        i++;
    // If "PATH=" is found, split it by ':'
    if (env[i]) 
    {
        path = ft_split(env[i] + 5, ':');  // Skip "PATH=" part
        i = -1;
        while (path[++i]) 
        {
            // Modify the path by appending "/" to each element
            split_path = ft_strjoin(path[i], "/");
            exec = ft_strjoin(split_path, cmd);  // Join path and command
             free(split_path);  // Free the temporary split_path string

            // Check if the executable is found and accessible
            if (access(exec, F_OK | X_OK) == 0) 
            {
                ft_free_arr(path);  // Free the path array after use
                return exec;  // Return the valid executable path
            }
            free(exec);  // Free the exec string if not found
        }
        ft_free_arr(path);  // Free path array if the command was not found
    }
    return NULL;  // Return NULL if the command is not found in any path
}
*/