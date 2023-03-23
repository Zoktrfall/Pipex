#include "get_next_line.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)ch)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == ch)
		return ((char *)str + i);
	return (NULL);
}

char	*new_ptr(char *str)
{
	char	*new_ptr;
	int		i;

	i = characters_ptr(str);
	new_ptr = malloc(sizeof(char) * i + 1);
	if (new_ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			new_ptr[i++] = '\n';
			break ;
		}
		new_ptr[i] = str[i];
		i++;
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}

char	*new_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = characters_str(str);
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_str = malloc(sizeof(char) *(ft_strlen(str) - i + 1));
	if (new_str == NULL)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*replace_str(int fd, char *ptr, char *str)
{
	int	read_only;

	ptr = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (ptr == NULL)
		return (NULL);
	while (1)
	{
		read_only = read(fd, ptr, BUFFER_SIZE);
		if (read_only == 0 && str != NULL)
			break ;
		if (read_only == -1 || (read_only == 0 && str == NULL))
		{
			free(ptr);
			return (NULL);
		}
		ptr[read_only] = '\0';
		str = ft_strjoin_exlusive(str, ptr);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(ptr);
	return (str);
}

char	*get_next_line(int fd, int check)
{
	static char	*str;
	char		*ptr;

	ptr = NULL;
	if (check == 1)
	{
		if (str != NULL)
			free(str);
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = replace_str(fd, ptr, str);
	if (str == NULL)
		return (NULL);
	ptr = new_ptr(str);
	str = new_str(str);
	return (ptr);
}
