#include "pipex.h"

void	child_process(char *name_command, char **process, char **envp)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid != 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		exit(execve(name_command, process, envp));
	}
}

char	*search_der(char **path, char *argv, char **envp, char *process)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!access(process, X_OK))
	{
		ptr = process;
		return (ptr);
	}
	while (path[i])
	{
		ptr = ft_strjoin(path[i], process);
		if (!access(ptr, X_OK))
			return (ptr);
		i++;
		free(ptr);
	}
	return (NULL);
}

char	**creat_path(char **envp)
{
	char		**path;
	size_t		i;
	char		*tmp;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
		{
			tmp = ft_strdup(envp[i]);
			if (tmp == NULL)
				return (NULL);
			tmp[3] = '.';
			tmp[4] = ':';
			path = ft_split(tmp + 3, ':');
		}
		i++;
	}
	free(tmp);
	return (path);
}
