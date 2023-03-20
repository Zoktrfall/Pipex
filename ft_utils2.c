#include "pipex.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = ft_strlen(str);
	j = 0;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr != NULL)
	{
		while (str[j] != '\0')
		{
			ptr[j] = str[j];
			j++;
		}
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}
