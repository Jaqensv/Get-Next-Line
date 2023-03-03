/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:00:15 by mde-lang          #+#    #+#             */
/*   Updated: 2023/02/14 00:06:29 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*algo_join(char *s1, char *s2, char *s3, int s3len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < s3len)
	{
		if (s1 != NULL)
			while (s1[i] && s1)
				s3[j++] = s1[i++];
		i = 0;
		while (s2[i])
			s3[j++] = s2[i++];
	}
	return (s3);
}

char	*algo_read(char *stash, int fd)
{
	int				u;
	char			buffer[BUFFER_SIZE + 1];

	u = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	while (u == BUFFER_SIZE)
	{
		u = read(fd, buffer, BUFFER_SIZE);
		buffer[u] = '\0';
		stash = ft_strjoin_lite(stash, buffer);
		if (!stash)
			return (NULL);
		if (ft_memchr(buffer, '\n', u) == 1)
			break ;
	}
	return (stash);
}

char	*free_for_all(char *s)
{
	if (s)
	{
		free(s);
		s = 0;
		return (s);
	}
	return (NULL);
}

int	ft_memchr(void *memoryBlock, int searchedChar, size_t size)
{
	char	*mem;
	char	chr;
	size_t	i;

	i = 0;
	mem = (char *)memoryBlock;
	chr = (char)searchedChar;
	while (i < size)
	{
		if (mem[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	int				tracker;

	tracker = 0;
	line = 0;
	stash = algo_read(stash, fd);
	tracker = ft_strchr_tracker(stash, '\n');
	line = ft_strdup_range(stash, tracker);
	stash = ft_strdup_back(stash, tracker);
	if (!line || line[0] == 0)
	{
		free(stash);
		stash = 0;
		return (free_for_all(line));
	}
	return (line);
}

// int	main()
// {
// 	int	i = 0;
// 	int fd = open("1char.txt", O_RDONLY);
// 	while (i++ < 9)
// 		printf("%d. %s\n",i ,get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
