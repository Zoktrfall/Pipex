#include "pipex.h"

int	file_valid(int argc, char **argv)
{
	char		*buffer;
	int			fd;
	int			fd_read;

	if (!ft_strcmp(argv[1], "here_doc", 0))
	{
		fd = open("._here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0755);
		while (1)
		{
			write(0, "pipe heredoc> ", 14);
			buffer = get_next_line(0, 0);
			if (!ft_strcmp(buffer, argv[2], 1))
				break ;
			ft_putstr_fd(buffer, fd);
			free(buffer);
		}
		get_next_line(0, 1);
	}
	if (!access(argv[argc - 1], F_OK) && access(argv[argc - 1], W_OK))
		return (1);
	fd_read = open("._here_doc", O_RDONLY);
	dup2(fd_read, 0);
	unlink("._here_doc");
	return (0);
}

size_t	dup_file(int argc, char **argv, int file_write, int file_read)
{
	if (!ft_strcmp(argv[1], "here_doc", 0))
		file_write = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 00755);
	else
		file_write = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 00755);
	if (ft_strcmp(argv[1], "here_doc", 0))
	{
		if (access((argv[1]), F_OK))
		{
			error_file(1, argv, 2, 0);
			return (3);
		}
		if (access((argv[1]), R_OK))
		{
			error_file(1, argv, 13, 0);
			return (3);
		}
		file_read = open(argv[1], O_RDONLY);
		dup2(file_read, 0);
	}
	dup2(file_write, 1);
	if (!ft_strcmp(argv[1], "here_doc", 0))
		return (3);
	return (2);
}
