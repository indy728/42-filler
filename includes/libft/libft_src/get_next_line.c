/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:49:08 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/31 17:16:35 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fd_lstadd(int fd, char *str, t_fd_list **begin_list)
{
	t_fd_list	*new;

	if ((new = (t_fd_list *)malloc(sizeof(t_fd_list))))
	{
		new->fd = fd;
		new->str = str;
		new->next = *begin_list;
		*begin_list = new;
	}
}

static void		fd_lstdel(int fd, t_fd_list **begin_list)
{
	t_fd_list	*scout;
	t_fd_list	*trail;

	scout = *begin_list;
	while (scout->fd != fd)
	{
		trail = scout;
		scout = scout->next;
	}
	if (scout == *begin_list)
		*begin_list = scout->next;
	else
		trail->next = scout->next;
	ft_freezero(scout->str, ft_strlen(scout->str));
	free(scout);
}

static char		*check_list(int fd, t_fd_list **begin_list)
{
	t_fd_list	*scout;
	char		*line;

	if (*begin_list)
	{
		scout = *begin_list;
		while (scout->fd != fd && scout->next)
			scout = scout->next;
		if (scout->fd != fd)
			return (ft_strdup(""));
		line = ft_strdup(scout->str);
		fd_lstdel(fd, begin_list);
		return (line);
	}
	return (ft_strdup(""));
}

static int		search(int fd, t_fd_list **begin_list, char **str)
{
	int			b;
	char		buff[BUFF_SIZE + 1];

	*str = check_list(fd, begin_list);
	while (!(ft_strchr(*str, LINE)) && (b = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[b] = '\0';
		*str = ft_strmove(ft_strjoin(*str, buff), str);
	}
	if (b == 0 && !ft_strlen(*str))
		return (0);
	if (b == -1)
		return (-1);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_fd_list	*begin_list = NULL;
	int					i;
	char				*str;

	if (!line || fd < 0 || fd > MAX_FD || BUFF_SIZE > MAX_BUF ||
			(i = search(fd, &begin_list, &str)) == -1)
		return (-1);
	if (ft_strchr(str, LINE))
	{
		*line = ft_strsub(str, 0, ft_strlchr(str, LINE));
		str = ft_strmove(ft_strdup(str + ft_strlchr(str, LINE) + 1), &str);
		fd_lstadd(fd, str, &begin_list);
	}
	else
	{
		*line = ft_strdup(str);
		ft_strdel(&str);
	}
	if (i == 0)
		return (0);
	return (1);
}
