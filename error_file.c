#include "pipex.h"

int	error_args(void)
{
	write(1, "Error Too Few Arguments\n", 24);
	return (0);
}

int	error_file(int index, char **argv, int number, int output)
{
	char	*error;

	if (number == 404)
		error = "command not found: ";
	else
		error = strerror(number);
	ft_putstr_fd("zsh: ", output);
	ft_putstr_fd(error, output);
	if (number != 404)
		ft_putstr_fd(": ", output);
	ft_putstr_fd(argv[index], output);
	write(output, "\n", 1);
	return (1);
}

int	error_pipex(void)
{
	write(1, "zsh: parse error near `|'\n", 26);
	return (0);
}
