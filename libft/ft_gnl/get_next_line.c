/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/16 11:32:28 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free_lst(t_node **holder, t_node *buf_lst)
{
	t_node	*tmp;

	if (!holder || !(*holder))
		return ;
	if (*holder == buf_lst)
		*holder = buf_lst->next;
	else
	{
		tmp = *holder;
		while (tmp && tmp->next != buf_lst)
			tmp = tmp->next;
		tmp->next = buf_lst->next;
	}
	free (buf_lst->str);
	free (buf_lst);
	return ;
}

static char	*ft_create_ret(t_node *buf_lst)
{
	char	*ret;
	char	*isnewl;
	char	*tmp;

	isnewl = ft_strchr_gnl(buf_lst->str, '\n');
	if (!isnewl)
	{
		if (*(buf_lst->str) == '\0')
			return (NULL);
		ret = ft_strndup_gnl(buf_lst->str, ft_strlen_gnl(buf_lst->str));
	}
	else
	{
		ret = ft_strndup_gnl(buf_lst->str, isnewl - buf_lst->str + 1);
		tmp = ft_strndup_gnl(isnewl + 1, ft_strlen_gnl(isnewl + 1));
		if (!tmp)
		{
			free (ret);
			return (NULL);
		}
		free (buf_lst->str);
		buf_lst->str = tmp;
	}
	return (ret);
}

static int	ft_read(int fd, t_node *buf_lst)
{
	ssize_t	rc;
	char	*buf;

	while (1)
	{
		buf = NULL;
		if (ft_strchr_gnl(buf_lst->str, '\n'))
			return (GOOD);
		buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1 || rc == 0)
		{
			free(buf);
			if (rc == -1)
				return (ERROR);
			return (END);
		}
		buf[rc] = '\0';
		buf = ft_strjoin_gnl(buf_lst->str, buf);
		if (!buf)
			return (ERROR);
		free (buf_lst->str);
		buf_lst->str = buf;
	}
}

static t_node	*ft_create_lst(int fd, t_node **holder)
{
	t_node	*buf_lst;

	if (!(*holder))
	{
		buf_lst = ft_lstnew_gnl(fd, "");
		*holder = buf_lst;
		return (buf_lst);
	}
	buf_lst = *holder;
	while (buf_lst)
	{
		if (buf_lst->fd == fd)
			return (buf_lst);
		buf_lst = buf_lst->next;
	}
	buf_lst = ft_lstnew_gnl(fd, "");
	if (!buf_lst)
		return (buf_lst);
	buf_lst->next = *holder;
	*holder = buf_lst;
	return (buf_lst);
}

char	*get_next_line(int fd)
{
	static t_node	*holder;
	t_node			*buf_lst;
	char			*ret;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!holder)
		holder = NULL;
	buf_lst = ft_create_lst(fd, &holder);
	if (!buf_lst)
		return (NULL);
	status = ft_read(fd, buf_lst);
	if (status == ERROR)
	{
		ft_free_lst(&holder, buf_lst);
		return (NULL);
	}
	ret = ft_create_ret(buf_lst);
	if (status == END || ret == NULL)
		ft_free_lst(&holder, buf_lst);
	return (ret);
}
