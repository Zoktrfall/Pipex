#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"

//Utils
int		ft_strcmp(char *str1, char *str2, int flag);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char *str1, char *str2);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *str1, const char *str2, size_t count);

//Validation
int		file_valid(int argc, char **argv, size_t *flag_heredoc);

#endif
