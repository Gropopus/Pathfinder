/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:28:50 by thsembel          #+#    #+#             */
/*   Updated: 2022/01/06 12:56:16 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 6000
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
int				ft_end_gnl(char **str);
int				ft_strlen_null(char *str);
int				ft_check_c(char *str, int c);
int				ft_free_and_exit(char **str, char **new_line);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_str_is_digit(char *str);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcat(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char const *s1, char *s2, int nb);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *string, size_t len);
char			**ft_split(const char *str, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_print_tab(char **tab);
void			ft_free_tab(char **str);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t max);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memchr(const void *s, int c, size_t size);
void			*ft_memset(void *str, int c, size_t count);
void			*ft_memmove(void *dst, const void *src, size_t size);
size_t			ft_tab_len(char **tab);
size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/*
** Bonus part
*/

int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *nnew);
void			ft_lstadd_back(t_list **alst, t_list *nnew);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);

#endif
