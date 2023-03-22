#include "pipex.h"

void	free_dm(char ***str)
{
	size_t	i;

	i = 0;
	if (*str == NULL)
		return ;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}

void	free_all(char **path, char **process, char *name_comand)
{
	free_dm(&path);
	free_dm(&process);
	free(name_comand);
}
