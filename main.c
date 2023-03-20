#include "pipex.h"

int	error_args(void)
{
	write(1, "Error Too Few Arguments\n", 24);
	return (0);
}

int error_file(int index, char **argv, int number, int output)
{
	char	*error;

	error = strerror(number);
	ft_putstr_fd("zsh: ", output);
	ft_putstr_fd(error, output);
	ft_putstr_fd(": ", output);
	ft_putstr_fd(argv[index], output);
	write(1, "\n", 1);
	return (1);
}

void	child_process(char *ptr, char **str, char **envp)
{
	int fd[2];
	pid_t pid;
	pipe(fd);
	pid = fork();
	if(pid != 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(ptr, str, envp);
	}

}

char	*search_der(char **path, char *argv, char **envp, char ***process)
{
	char *ptr;
	size_t i;

	i = 0;
	*process = ft_split(argv, ' ');
	if(!access(*process[0], X_OK))
	{
		ptr = *process[0];
		return (ptr);
	}
	while(path[i])
	{
		ptr = ft_strjoin(path[i], *process[0]);
		if(!access(ptr, X_OK))
			return (ptr);
		i++;
		free(ptr);
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	char		**path;
	size_t		start;
	char 		**process;
	char		*name_command;
	

	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc", 0) && argc < 6))
		return (error_args());
	start = dup_file(argc, argv, 0, 0);
	if (file_valid(argc, argv))
		return (error_file(argc - 1, argv, 13, 2));
	path = creat_path(envp);
	if(ft_strcmp(argv[1], "here_doc", 0))
	{
		while(start < argc - 2)
		{
			name_command = search_der(path, argv[start], envp, &process);
			if(name_command != NULL)
				execve(name_command, process, envp);
			start++;
		}
	}
	return (0);
}
