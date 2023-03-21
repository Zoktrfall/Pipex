#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char		**path;
	size_t		start;
	char		**process;
	char		*name_command;

	if (argc < 5 || (!ft_strcmp(argv[1], "here_doc", 0) && argc < 6))
		return (error_args());
	start = dup_file(argc, argv, 0, 0);
	if (file_valid(argc, argv))
		return (error_file(argc - 1, argv, 13, 2));
	while (start < argc - 1)
	{
		path = creat_path(envp);
		process = ft_split(argv[start], ' ');
		name_command = search_der(path, argv[start], envp, process[0]);
		if (name_command == NULL)
			error_file(start, argv, 404, 2);
		if (start == argc - 2)
			exit(execve(name_command, process, envp));
		child_process(name_command, process, envp);
		start++;
	}
	return (0);
}
