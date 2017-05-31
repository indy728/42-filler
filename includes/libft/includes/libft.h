/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:26:25 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/31 01:31:37 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int c, size_t count);
void				ft_bzero(void *s, size_t n);
void				ft_freezero(void *mem, size_t size);
void				*ft_memcpy(void *dest, void const *src, size_t count);
void				*ft_memccpy(void *dest, void const *src,
							int c, size_t count);
void				*ft_memmove(void *dest, void const *src, size_t count);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memdup(void const *str);

size_t				ft_strlen(char const *str);
size_t				ft_endspaces(char *str);
size_t				ft_wordlen(char *str, char c);
size_t				ft_count_words(char *str, char c);
size_t				ft_strlchr(char *str, char c);

char				*ft_strdup(char const *str);
char				*ft_strmove(char *dest, char **src);
char				*ft_strcpy(char *dest, char const *src);
char				*ft_strncpy(char *dest, char const *src, size_t n);
char				*ft_strcat(char *s1, char const *s2);
char				*ft_strncat(char *s1, char const *s2, size_t n);
size_t				ft_strlcat(char *s1, char const *s2, size_t size);
char				*ft_strchr(char const *str, int c);
char				*ft_strrchr(char const *str, int c);
char				*ft_strstr(char const *big, char const *little);
char				*ft_strnstr(char const *big, char const
							*little, size_t len);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *str, unsigned int start,
							size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *str);
char				**ft_strsplit(char const *str, char c);

int					ft_atoi(char const *str);
char				*ft_itoa(int n);
char				*ft_lltoa_base(long long n, int base);
char				*ft_maxtoa_base(intmax_t n, int base);
char				*ft_umaxtoa_base(uintmax_t n, int base);
int					ft_count_base(intmax_t n, int base);
int					ft_countu_base(uintmax_t n, int base);
char				ft_base_char(int n);

int					ft_isprime(int n);
int					ft_power_of(int base, int power);
int					ft_max(int num1, int num2);
int					ft_min(int num1, int num2);
int					ft_abs(int x);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
char				*ft_toupperstr(char *str);
char				*ft_tolowerstr(char *str);
char				*ft_capitalize_each(char *str);
int					ft_tolower(int c);
int					ft_iswhitespace(char c);

void				ft_putchar(char c);
void				ft_putstr(char const *str);
int					ft_putlchar(char c);
int					ft_putlstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int n);
int					ft_putlnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putlnbr_fd(int n, int fd, int i);
void				ft_exit_malloc_error();

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstcat(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstsort(t_list **lst, int (*cmp)(void *, void *));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				**ft_lstpop(t_list **alst, t_list **begin_list);

#endif
