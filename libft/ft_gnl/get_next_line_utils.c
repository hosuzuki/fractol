/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 11:38:38 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char)
			* (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!dst)
	{
		free ((void *)s2);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	free ((void *)s2);
	return (dst);
}

char	*ft_strndup_gnl(const char *s, size_t len)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

t_node	*ft_lstnew_gnl(int fd, void	*content)
{
	t_node	*buf_lst;

	buf_lst = (t_node *)malloc(sizeof(t_node));
	if (!buf_lst)
		return (NULL);
	buf_lst->fd = fd;
	buf_lst->str = ft_strndup_gnl(content, 0);
	if (!buf_lst->str)
	{
		free(buf_lst);
		return (NULL);
	}
	buf_lst->next = NULL;
	return (buf_lst);
}
