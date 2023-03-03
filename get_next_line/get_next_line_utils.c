/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:35:12 by mde-lang          #+#    #+#             */
/*   Updated: 2023/02/21 18:08:35 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup_back(char *s, int tracker)
{
	int		i;
	int		j;
	char	*c;

	if (!s)
		return (NULL);
	if (!s[tracker])
		return (free_for_all(s));
	i = tracker + 1;
	j = 0;
	if (!ft_memchr(s, '\n', ft_strlen(s)))
		return (free_for_all(s));
	c = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!c)
		return (free_for_all(s));
	while (s[i])
		c[j++] = s[i++];
	c[j] = 0;
	free(s);
	return (c);
}

char	*ft_strdup_range(char *s, int tracker)
{
	int		i;
	char	*c;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_memchr(s, '\n', ft_strlen(s)))
		tracker++;
	c = malloc(sizeof(char) * (tracker + 1));
	if (!c)
		return (NULL);
	c[tracker] = 0;
	while (i < tracker)
	{
		c[i] = s[i];
		i++;
	}
	return (c);
}

int	ft_strchr_tracker(char *string, int searchedChar)
{
	int	i;
	int	len;

	i = 0;
	if (!string)
		return (0);
	len = ft_strlen(string);
	while (i < len)
	{
		if (string[i] == (char)searchedChar)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin_lite(char *s1, char *s2)
{
	int		s3len;
	char	*s3;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if (!s2)
		return (s1);
	s3len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (s3len + 1));
	if (!s3)
		return (free_for_all(s1));
	s3[s3len] = 0;
	s3 = algo_join(s1, s2, s3, s3len);
	free(s1);
	return (s3);
}
