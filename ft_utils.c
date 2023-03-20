#include "pipex.h"

int	ft_strcmp(char *str1, char *str2, int flag)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] - str2[i] != 0)
			return (1);
		i++;
	}
	if (flag == 1 && str1[i + 1] == '\0' && str2[i] == '\0')
		return (0);
	if (str1[i] == '\0' && str2[i] == '\0')
		return (0);
	return (1);
}

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	while ((str1[i] != '\0' || str2[i] != '\0') && b < count)
	{
		if ((str1[i] - str2[i] != 0))
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		b++;
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
	return ;
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 2));
	while (str1[i] != '\0')
	{
		ptr[j] = str1[i];
		j++;
		i++;
	}
	ptr[j++] = '/';
	i = 0;
	while (str2[i] != '\0')
	{
		ptr[j] = str2[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	**creat_path(char **envp)
{
	char		**path;
	size_t		i;
	char		*tmp;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
		{
			tmp = ft_strdup(envp[i]);
			tmp[3] = '.';
			tmp[4] = ':';
			path = ft_split(tmp + 3, ':');
		}
		i++;
	}
	for(int j = 0; path[j]; j++)
		printf("%s\n", path[j]);
	return (path);
}
