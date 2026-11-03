/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:30:26 by nippolit          #+#    #+#             */
/*   Updated: 2024/06/14 02:35:37 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	mouv(char *stock, int i);
char	*stocking(char *stock, int *i);

char	*get_next_line(int fd)
{
	static char	stock[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			read_amount;

	line = initline();
	if (verif(line, fd) == 1)
		return (NULL);
	while (1)
	{
		line = ft_strjoin_mod(line, stocking(stock[fd], &i));
		if (i > 0 && stock[fd][i - 1] == '\n')
			return (mouv(stock[fd], i), line);
		read_amount = read(fd, stock[fd], BUFFER_SIZE);
		if (read_amount == 0 && ft_strlen(line))
		{
			stock[fd][0] = '\0';
			return (line);
		}
		if (read_amount < 1)
			break ;
		stock[fd][read_amount] = '\0';
	}
	free (line);
	return (NULL);
}

void	mouv(char *stock, int i)
{
	ft_memmove(stock, &stock[i], ft_strlen(&stock[i]) + 1);
}

char	*stocking(char *stock, int *i)
{
	char	*temp;

	temp = malloc((ft_strlen(stock) + 1) * sizeof(char));
	*i = 0;
	while (stock[*i] && stock[*i - 1] != '\n')
	{
		temp[*i] = stock[*i];
		(*i)++;
	}
	temp[*i] = '\0';
	return (temp);
}

int	main(void)
{
	printf("%s", get_next_line(0));
	/*int	fd[3];
	
	fd[0] = open("file1", O_RDONLY);
	fd[1] = open("file2", O_RDONLY);
	fd[2] = open("file3", O_RDONLY);
	
	//char	*test = NULL;

	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[2]));
	printf("%s", get_next_line(fd[0]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[1]));
	printf("%s", get_next_line(fd[2]));
	printf("%s", get_next_line(fd[2]));

	while ((test = get_next_line(fd[i])) != NULL)
	{
		printf("%s", test);
		free(test);
	}*/

	/*close (fd[0]);
	close (fd[1]);
	close (fd[2]);*/
	
	return (0);
}
