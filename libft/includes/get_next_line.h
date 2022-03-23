/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:53 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 11:27:18 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 100
# define GOOD 1
# define ERROR -1
# define END 0

typedef struct sllist
{
	int				fd;
	char			*str;
	struct sllist	*next;
}	t_node;

size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(const char *s1, const char *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strndup_gnl(const char *content, size_t len);
t_node	*ft_lstnew_gnl(int fd, void *content);
char	*get_next_line(int fd);

#endif
