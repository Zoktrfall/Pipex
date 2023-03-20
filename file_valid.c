#include "pipex.h"

int	file_valid(int argc, char **argv, size_t *flag_heredoc)
{
	char		*buffer;
	int			fd;

	if (!ft_strcmp(argv[1], "here_doc", 0))
		*flag_heredoc = 1;
	if (*flag_heredoc == 1)
	{
		fd = open("._here_doc", O_WRONLY | O_CREAT, 0755);
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
	return (0);
}
