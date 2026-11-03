/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:30:18 by nippolit          #+#    #+#             */
/*   Updated: 2024/10/11 00:11:13 by jimmy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dest);
	}
	else
	{
		while (n)
		{
			--n;
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
		return (dest);
	}
}

char	*ft_strjoin_mod(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (str1 && str1[++i])
		result[i] = str1[i];
	while (str2 && str2[++j])
		result[i + j] = str2[j];
	result[i + j] = '\0';
	free (str1);
	free (str2);
	return (result);
}

char	*initline(void)
{
	char	*line;

	line = malloc(1);
	if (line)
		line[0] = '\0';
	return (line);
}

int	verif(char *line, int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (line != NULL)
			free(line);
		return (1);
	}
	if (!line)
		return (1);
	return (0);
}
