/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:43:34 by cgangaro          #+#    #+#             */
/*   Updated: 2021/04/27 10:52:16 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef	struct	s_utils
{
	char	*str;
	char	*index;
	char	*result;
	int		i;
	int		cpt;
	char	c;
	int		index_annexe;
}				t_utils;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(char *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(void *s, int c, size_t n);
int				ft_memcmp(void *s1, void *s2, size_t n);
size_t			ft_strlen(char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
long long int	ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap
				(t_list *lst, void *(*f)(void *), void (*del)(void *));
char			*ft_strncpy(char *s1, char c);
char			*ft_afterncpy(char *s1, char c);
char			*ft_zero(char *s, int n);
char			*ft_strjoin_v2(char *s1, char *s2);
int				get_next_line(int fd, char **line);
size_t			ft_strlen_get1(char *s);
char			*ft_substr_get1(char *s1, char c);
char			*ft_zero_get1(char *s, int n);
char			*ft_strjoin_get1(char *s1, char *s2);
char			*ft_strchr_get1(const char *s, int c);
char			*ft_strncpy_get1(char *s1, char c);
/*size_t			ft_strlen_get(const char *s);
char			*ft_strjoin_get(char const *s1, char const *s2);
char			*ft_strchr_get(const char *str, int c);
char			*ft_strdup_get(const char *s1);
char			*ft_substr_get(char const *s, unsigned int start, size_t len);*/
char			*ft_add_char(char *str, int x, char c);
char			*ft_suppr_char(char *str, int x);
int				ft_search(char *str, char c, int dir);
char			*ft_itoa_base(long long n, char *base);
char			*ft_strjoin_static(char *s1, char *s2);
int				ft_printf(const char *str, ...);
t_utils			*ft_printf_annexe(va_list ap, t_utils *utils);
t_utils			*ft_printf_annexe_2(va_list ap, t_utils *utils);
t_utils			*ft_index(t_utils *utils, va_list ap);
t_utils			*ft_index_2(t_utils *utils, int i, int y, va_list ap);
t_utils			*ft_index_2_annexe(t_utils *utils);
t_utils			*ft_index_2_annexe_2(t_utils *utils);
t_utils			*ft_index_2_annexe_3(t_utils *utils);
t_utils			*ft_cas_spe_index(t_utils *utils);
t_utils			*verif_index(t_utils *utils);
t_utils			*ft_cas_spe_index_etoile(t_utils *utils);
t_utils			*index_etoile(va_list ap, t_utils *utils);
t_utils			*ft_arg(va_list ap, t_utils *utils);
t_utils			*ft_arg_annexe(va_list ap, t_utils *utils);
t_utils			*ft_arg_annexe(va_list ap, t_utils *utils);
t_utils			*ft_arg_annexe_p(t_utils *utils);
t_utils			*ft_cas_spe_point(t_utils *utils);
t_utils			*ft_cas_spe_point_2(t_utils *utils);
t_utils			*ft_cas_spe_point_3(t_utils *utils);
t_utils			*ft_cas_spe_point_x(t_utils *utils);
t_utils			*ft_printf_2(va_list ap, t_utils *utils);
t_utils			*ft_printf_3(t_utils *utils);
t_utils			*ft_point_int(t_utils *utils);
t_utils			*ft_cas_spe_point_nbr_neg(t_utils *utils, int nb_zero);
t_utils			*ft_cas_spe_point_nbr_neg_2(t_utils *utils, int nb_zero);
t_utils			*ft_point_string(t_utils *utils);
t_utils			*ft_moins(t_utils *utils);
t_utils			*ft_zero_printf(t_utils *utils);
t_utils			*ft_zero_printf_2(t_utils *utils);
t_utils			*ft_zero_printf_3(t_utils *utils);
t_utils			*ft_nbr(t_utils *utils);
t_utils			*ft_p(t_utils *utils);
int				ft_fin(t_utils *utils);
int				ft_cpt_char(char *str, char c, int max);
int				ft_first_char(char *str, char c, int start);
int				ft_nbr_or_not(char *str, int x);
t_utils			*ft_putstr_aff(t_utils *utils);
t_utils			*ft_putstr_aff_c_moins(t_utils *utils);
t_utils			*ft_putstr_aff_c_zero(t_utils *utils);
int				ft_nbr_after_index(t_utils *utils, char c);
char			*ft_putstr_null();
char			*ft_itoa_base_p(unsigned long n, char *base);
char			*ft_replace_first(char a, char *b, char *str);
int				cpt_index(t_utils *utils);
int				cpt_index_2(t_utils *utils, int i, int cpt);
char			*ft_string_filled(char c, int size);
char			*ft_strjoin_one(char *s1, char c);
void			ft_putchar_aff(char c);
int				ft_nbr_index(char *index);
char			**ft_suppr_char_tab(char **tab, int sens);
void			ft_putstr_1(char *s);
void			ft_putchar_1(char s);

#endif
