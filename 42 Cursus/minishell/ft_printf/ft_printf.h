/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:25:27 by mbani             #+#    #+#             */
/*   Updated: 2019/11/16 11:03:42 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_help
{
	int		i;
	char	*ptr;
	char	*flags;
	char	*tmp;
	char	*tmp1;
}				t_help;
typedef	struct	s_flag
{
	int		width;
	int		precision;
	short	minus;
	short	zero;
}				t_flag;
int				ft_printf(const char *a, ...);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_atoi(const char *str);
int				print_i(va_list *ap, const char **a);
int				print_str(va_list *ap, const char **a);
int				print_c(va_list *ap, const char **a);
int				print_u(va_list *ap, const char **a);
int				print_p(va_list *ap, const char **a);
int				print_x(va_list *ap, const char **a, char x);
char			*ft_itoa(unsigned int n);
char			*ft_itoa_u(unsigned int n);
int				ft_noflags(va_list *ap, const char **a, char **flags);
char			*ft_itoa(unsigned int n);
char			*ft_strlowcase(char *str);
char			*ft_strdup(const char *s1);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr(int nb);
char			*convert_hex(unsigned long i);
int				ft_strlen(const char *s);
char			*ft_sstrcpy(char *dest, char *src);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_flagd(int precision, int width, short minus, char *s);
int				fprint_i(va_list *ap, t_flag **f, const char **a);
int				ft_flag_i(int width, int precision, int minus, char *s);
int				fprint_u(va_list *ap, const char **a, t_flag **f);
int				ft_pre_d(int precision, char *s);
int				ft_width_d(int minus, int width, short zero, char *s);
int				fprint_c(va_list *ap, t_flag **f, const char **a);
int				fprint_p(va_list *ap, t_flag **f, const char **a);
int				ft_width(int minus, int width, int tmp, char *s);
int				fprint_x(va_list *ap, const char **a, char x, t_flag **f);
int				fprint_percent(t_flag **f, const char **a);
int				type_check(const char **a, t_flag **f, va_list *ap);
int				ft_flagschecker(va_list *ap, char **flags, const char **a);
void			flag_saver(char **ptr, char **flags, char **tmp,
const char ***a);
int				check(va_list *ap, const char **a);
char			*convert_hex(unsigned long i);
int				ft_noflags(va_list *ap, const char **a, char **flags);
void			struct_in(t_flag **f);
void			width_arg(va_list *ap, t_flag **f);
void			precision_check(char **flags, va_list *ap, t_flag **f);
void			width_check(char **flags, t_flag **f, va_list *ap);
int				print_spaces(int n);
int				ft_puts(char *str, int n);
int				fprint_s(va_list *ap, t_flag **f);
int				ft_widthc(int minus, int width, int tmp, char s);
int				print_zeroes(int n);
int				flagd_helper(char *s, int width, int precision, int tmp);
int				ft_flagschecker(va_list *ap, char **flags, const char **a);
int				fprint_s(va_list *ap, t_flag **f);
int				ft_printx(t_flag **f, char *str);
char			*ft_strrev(char *str);
#endif
