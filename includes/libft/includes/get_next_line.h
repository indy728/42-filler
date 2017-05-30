/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:08:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/08 17:32:15 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 3
# define MAX_FD 1025
# define MAX_BUF 10000000
# define LINE '\n'

typedef struct			s_fd_list
{
	int					fd;
	char				*str;
	struct s_fd_list	*next;
}						t_fd_list;

int						get_next_line(const int fd, char **line);

#endif
