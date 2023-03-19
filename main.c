#include "pipex.h"

int	error_args(void)
{
	write(1, "Error Too Few Arguments\n", 24);
	return (0);
}

int error_file(int argc, char **argv)
{
	char	*error;

	error = strerror(13);
	ft_putstr_fd("zsh: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(argv[argc - 1], 2);
	write(1, "\n", 1);
	return (1);
}

char	**creat_path(char **envp)
{
	char		**path;
	size_t		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
			path = ft_split(envp[i] + 5, ':');	
		i++;
	}
	return (path);
}

int	main(int argc, char *argv[], char *envp[])
{
	char		**path;
	size_t		flag_heredoc;

	flag_heredoc = 0;
	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc", 0) && argc < 6))
		return (error_args());
	if (file_valid(argc, argv, &flag_heredoc))
		return (error_file(argc, argv));
	
	return (0);
}
