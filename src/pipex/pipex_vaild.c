/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_vaild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:47:23 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/24 12:47:24 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(int argc, char **argv)
{
	char		*buffer;
	int			fd;
	int			i;
	int			fd_read;

	fd = open("._here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0755);
	while (1)
	{
		i = 2;
		while (++i < argc - 2)
			write(0, "pipe ", 5);
		write(0, "heredoc> ", 9);
		buffer = get_next_line(0, 0);
		if (!ft_strcmp(buffer, argv[2], 1))
			break ;
		ft_putstr_fd(buffer, fd);
		free(buffer);
	}
	free(buffer);
	get_next_line(0, 1);
	fd_read = open("._here_doc", O_RDONLY);
	dup2(fd_read, 0);
	unlink("._here_doc");
}

void	creat_tmp_read_file(int file_read, int file_write)
{
	file_read = open("./open_read_tmp", O_CREAT | O_RDONLY);
	dup2(file_read, 0);
	dup2(file_write, 1);
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
			creat_tmp_read_file(file_read, file_write);
			return (2);
		}
		if (access((argv[1]), R_OK))
		{
			error_file(1, argv, 13, 0);
			creat_tmp_read_file(file_read, file_write);
			return (2);
		}
		file_read = open(argv[1], O_RDONLY);
		dup2(file_read, 0);
	}
	dup2(file_write, 1);
	if (!ft_strcmp(argv[1], "here_doc", 0))
		return (2);
	return (1);
}
