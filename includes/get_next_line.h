/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:47:07 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/24 12:47:08 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd, int check);
char	*replace_str(int fd, char *ptr, char *str);
char	*new_str(char *str);
char	*new_ptr(char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin_exlusive(char *str, char *ptr);
char	*adds(char *ptr);
size_t	ft_strlen(const char *str);
int		characters_str(char *str);
int		characters_ptr(char *str);

#endif
