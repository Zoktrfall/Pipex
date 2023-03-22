#include "pipex.h"

int	ft_pipex(int argc, char **argv, size_t start, char **envp)
{
	char		**process;
	char		*name_command;
	char		**path;

	while (++start < argc - 1)
	{
		path = creat_path(envp);
		process = ft_split(argv[start], ' ');
		if (process == NULL)
		{
			free_dm(&path);
			exit(1);
		}
		name_command = search_der(path, argv[start], envp, process[0]);
		if (name_command == NULL)
			error_file(start, argv, 404, 2);
		if (start == argc - 2)
			break ;
		child_process(name_command, process, envp);
		free_all(path, process, name_command);
		system("leaks a.out");
	}
	if (!access(argv[argc - 1], F_OK) && access(argv[argc - 1], W_OK))
		return (error_file(argc - 1, argv, 13, 2));
	exit(execve(name_command, process, envp));
}

int	main(int argc, char *argv[], char *envp[])
{
	size_t		start;

	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc", 0) && argc < 6))
		return (error_args());
	start = dup_file(argc, argv, 0, 0);
	if (!ft_strcmp(argv[1], "here_doc", 0))
		here_doc(argc, argv);
	ft_pipex(argc, argv, start, envp);
	return (0);
}
