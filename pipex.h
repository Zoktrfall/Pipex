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
char	*ft_strdup(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t count);

//Validation
void	here_doc(int argc, char **argv);
size_t	dup_file(int argc, char **argv, int file_write, int file_read);

//Pipex utils
char	**creat_path(char **envp);
void	child_process(char *name_command, char **process, char **envp);
char	*search_der(char **path, char **process, char *ptr, size_t i);

//Error
int		error_file(int index, char **argv, int number, int output);
int		error_args(void);

//Free
void	free_dm(char ***str);
void	free_all(char **path, char **process, char *name_comand);

#endif
