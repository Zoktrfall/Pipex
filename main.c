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
	ft_putstr_fd("zsh: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(argv[index], 2);
	write(1, "\n", 1);
	return (1);
}

size_t		dup_file(int argc, char **argv)
{
	int	file_write;
	int	file_read;
	int	flag_heredoc;

	if (!ft_strcmp(argv[1], "here_doc", 0))
		file_write = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 00755);
	else
		file_write = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 00755);
	if (ft_strcmp(argv[1], "here_doc", 0))
	{
		if (access((argv[1]), F_OK))
		{
			error_file(1, argv, 2, 0);
			return (2);
		}
		if (access((argv[1]), R_OK))
		{
			error_file(1, argv, 13, 0);
			return (2);
		}
	}
	dup2(file_read, 0);
	dup2(file_write, 1);
	return (1);
}

char	**search_der(char **path, char *argv)
{
	size_t	i;
	char **str;
	char *ptr;

	i = 0;
	str = ft_split(argv, ' ');
	if (!access(str[0], X_OK))
		return (str);
	while(path[i])
	{
		str[0] = ft_strjoin(path[i], str[0]); 
		if (!access(str[0], X_OK))
			return (str);
		i++;
	}
	return NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	char		**path;
	size_t		flag_heredoc;
	size_t		start;
	char 		**str;
	

	flag_heredoc = 0;
	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc", 0) && argc < 6))
		return (error_args());
	start = dup_file(argc, argv);
	if (file_valid(argc, argv, &flag_heredoc))
		return (error_file(argc - 1, argv, 13, 2));
	path = creat_path(envp);
	str = search_der(path, argv[2]);
	execve(str[0], str, envp);
	return (0);
}
