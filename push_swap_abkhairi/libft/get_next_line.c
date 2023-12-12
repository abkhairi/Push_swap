/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:40:59 by abkhairi          #+#    #+#             */
/*   Updated: 2023/10/27 21:01:59 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reserve(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (free(str), NULL);
		i++;
	}
	i++;
	while (str[j] != '\0')
		j++;
	res = ft_substr_gnl(str, i, j - i);
	free(str);
	return (res);
}

static char	*return_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_substr_gnl(str, 0, i + 1);
	return (line);
}

static int	ft_nl(char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_save(int fd, char *store)
{
	char	*buffer;
	int		size;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	size = 1;
	while (size != 0 && ft_nl(store) == 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			return (free(store), free(buffer), NULL);
		}
		buffer[size] = '\0';
		store = ft_strjoin_gnl(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_save(fd, str);
	line = return_line(str);
	str = reserve(str);
	return (line);
}
