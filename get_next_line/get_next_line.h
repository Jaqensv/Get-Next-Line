/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:28:18 by mde-lang          #+#    #+#             */
/*   Updated: 2023/02/14 00:07:24 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr_tracker(char *string, int searchedChar);
char	*ft_strdup_range(char *s, int tracker);
char	*ft_strjoin_lite(char *s1, char *s2);
char	*ft_strdup_back(char *s, int tracker);
char	*free_for_all(char *s);
int		ft_memchr(void *memoryBlock, int searchedChar, size_t size);
char	*read_algo(char *stash, int fd);
char	*algo_join(char *s1, char *s2, char *s3, int s3len);

#endif