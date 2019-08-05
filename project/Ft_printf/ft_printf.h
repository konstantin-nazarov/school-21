/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:45:45 by dhorker           #+#    #+#             */
/*   Updated: 2019/05/13 14:42:02 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# define MAX_DIGITS_LF 2000
# define BASE_LF 10000000000000000000UL
# define MAX_DIGIT_NUMBER_LF 19
# define S_BITS_LF (64 - 1)
# define E_BITS_LF (64 - 1 - 11)
# define E_LIMIT_LF (1024 - 1 + E_BITS_LF)
# define E_MASK_LF 0x7FF
# define M_MASK1_LF 0xFFFFFFFFFFFFF
# define M_MASK2_LF 0x10000000000000
# define MAX_DIGITS_LLF 35000
# define BASE_LLF 10000000000000000000UL
# define MAX_DIGIT_NUMBER_LLF 19
# define S_BITS_LLF (80 - 1)
# define E_BITS_LLF (80 - 1 - 15)
# define E_LIMIT_LLF (16384 - 1 + E_BITS_LLF - 1)
# define E_MASK_LLF 0x7FFF
# define M_MASK1_LLF 0xFFFFFFFFFFFFFFFF
# define M_MASK2_LLF 0x8000000000000000
# define NUM 19
# define MINUS_TOKEN spec.u.f.f1
# define PLUS_TOKEN spec.u.f.f2
# define SPACE_TOKEN spec.u.f.f3
# define ZERO_TOKEN spec.u.f.f5

typedef struct			s_insert
{
	char				*pointer;
	char				symb;
	char				*sign;
}						t_insert;

typedef struct			s_specifier
{
	union				u_flag
	{
		unsigned char	flag;
		struct
		{
			unsigned	f1 : 1;
			unsigned	f2 : 1;
			unsigned	f3 : 1;
			unsigned	f4 : 1;
			unsigned	f5 : 1;
			unsigned	dot_for_prec : 1;
			unsigned	inf_flag : 1;
			unsigned	nan_flag : 1;
		}				f;
	}					u;
	int					width;
	int					prec;
	char				mod[3];
}						t_spec;

typedef union			u_double_long
{
	double				dl;
	unsigned long int	ulin;
}						t_double_long;

typedef union			u_longdouble_long
{
	long double			dl;
	__uint128_t			ulin;
}						t_longdouble_long;

int						ft_printf(const char *format, ...);
int						do_spec(char **s, va_list *ap, t_spec spec);
void					check_flags(t_spec *spec, char c);
int						create_spec(t_spec *spec, char *str);
int						di_spec(va_list *ap, t_spec spec);
int						li_spec(va_list *ap, t_spec spec);
int						s_spec(va_list *ap, t_spec spec);
int						c_spec(va_list *ap, t_spec spec, char c);
int						u_spec(va_list *ap, t_spec spec);
int						lu_spec(va_list *ap, t_spec spec);
int						o_spec(va_list *ap, t_spec spec);
int						lo_spec(va_list *ap, t_spec spec);
int						x_spec(va_list *ap, t_spec spec);
int						x_big_spec(va_list *ap, t_spec spec);
int						f_spec(va_list *ap, t_spec spec);
int						p_spec(va_list *ap, t_spec spec);
int						f_spec(va_list *ap, t_spec spec);
int						llo_spec(va_list *ap, t_spec spec);
int						lo_spec(va_list *ap, t_spec spec);
int						hho_spec(va_list *ap, t_spec spec);
int						ho_spec(va_list *ap, t_spec spec);
int						type_o_support(va_list *ap, t_spec spec);
int						digit_number(long long result);
int						digit_number_u(unsigned long long result);
unsigned int			digit_number_ui(unsigned int nbr);
void					putnumber(long long n);
void					putnumber_u(unsigned long long n);
void					putstring(char *str, int size);
void					ft_putnbr_ulong(unsigned long int n);
void					shift(t_spec spec, int *len, long long int num, char c);
void					shift_u(t_spec spec, int *len, unsigned long long num,
						char c);
void					sign(t_spec spec, long long num);
void					sign_point(t_spec spec, long long num, char c);
char					*ft_itoa_base_letter(unsigned int value, int base,
						char letter);
char					*ft_lutoa_16(long long unsigned int value, char letter);
char					*ft_lutoa_8(long long unsigned int value);
char					*ft_sutoa_8(short unsigned int value);
char					*ft_sutoa_16(short unsigned int value, char letter);
unsigned long int		ft_atolu(const char *str);
char					*utoa_support(void);
void					negative_diu(t_spec spec, long long num, int len);
void					null_diu(t_spec spec, long long num, int len);
void					none_diu(t_spec spec, long long num, int len);
void					negative_u(t_spec spec, unsigned long long num,
						int len);
void					null_u(t_spec spec, unsigned long long num, int len);
void					none_u(t_spec spec, unsigned long long num, int len);
void					negative_pxo(t_spec spec, long long num, int len,
						char *str);
void					null_pxo(t_spec spec, long long num, int len,
						char *str);
void					none_pxo(t_spec spec, long long num, int len,
						char *str);
void					negative_big_x(t_spec spec, long long num, int len,
						char *str);
void					null_big_x(t_spec spec, long long num, int len,
						char *str);
void					none_big_x(t_spec spec, long long num, int len,
						char *str);
void					init_func_array(int (*func[NUM])(va_list *, t_spec));
void					init_spec_array(char spec[NUM]);

void					init_f_spec(t_insert *insert, t_spec spec,
						unsigned int *precision);
void					check_for_inf_or_nan(char *virtual_output,
						t_spec *spec);
unsigned int			check_for_plus_or_space(t_spec spec,
						unsigned int below_zero_flag, t_insert *insert,
						char **virtual_output);
void					check_for_minus_or_zero(t_insert *insert,
						char **virtual_output, t_spec spec,
						unsigned int length);
void					ft_put_virtual_char(char c, char **output);
void					ft_put_virtual_nbr(int n, char **output);
int						float_point_lf(va_list *ap, unsigned int pres,
						unsigned int *sign, char **virtual_output);
int						print_big_num_lf (char **output,
						unsigned int n[MAX_DIGITS_LF], unsigned int point,
						unsigned int length);
void					fill_array_with_x_lf(unsigned long int x,
						unsigned int res[MAX_DIGITS_LF]);
void					mult_x_y_to_the_power_lf(unsigned long int x,
						unsigned int y, unsigned int power,
						unsigned int res[MAX_DIGITS_LF]);
unsigned int			count_digits_lf(unsigned int res[MAX_DIGITS_LF]);
void					add_zeroes_to_tail_lf(unsigned int res[MAX_DIGITS_LF],
						unsigned int num, unsigned int length);
void					round_from_tail_lf(unsigned int res[MAX_DIGITS_LF],
						unsigned int num, unsigned int length);
void					set_presition_lf(unsigned int res[MAX_DIGITS_LF],
						unsigned int pres, unsigned int point,
						unsigned int *length);
int						start_processing_number_lf(char **output,
						unsigned int e, unsigned long int m, unsigned int pres);
int						is_it_special_value_lf(char **output, unsigned int e,
						unsigned long int m, unsigned int pres);
int						float_point_llf(va_list *ap, unsigned int pres,
						unsigned int *sign, char **virtual_output);
int						print_big_num_llf (char **output,
						unsigned int n[MAX_DIGITS_LLF], unsigned int point,
						unsigned int length);
void					fill_array_with_x_llf(unsigned long int x,
						unsigned int res[MAX_DIGITS_LLF]);
void					mult_x_y_to_the_power_llf(unsigned long int x,
						unsigned int y, unsigned int power,
						unsigned int res[MAX_DIGITS_LLF]);
unsigned int			count_digits_llf(unsigned int res[MAX_DIGITS_LLF]);
void					add_zeroes_to_tail_llf(unsigned int res[MAX_DIGITS_LLF],
						unsigned int num, unsigned int length);
void					round_from_tail_llf(unsigned int res[MAX_DIGITS_LLF],
						unsigned int num, unsigned int length);
void					set_presition_llf(unsigned int res[MAX_DIGITS_LLF],
						unsigned int pres, unsigned int point,
						unsigned int *length);
int						start_processing_number_llf(char **output,
						unsigned int e, unsigned long int m, unsigned int pres);
int						is_it_special_value_llf(char **output, unsigned int e,
						unsigned long int m, unsigned int pres);
void					ft_putstr_fast(char const *s);
void					make_copy_lf(unsigned int res[MAX_DIGITS_LF],
						unsigned int res_copy[MAX_DIGITS_LF]);
void					move_rigth_all_digits_lf(unsigned int
						res[MAX_DIGITS_LF], unsigned int num,
						unsigned int length);
void					release_overflow_lf(unsigned int res[MAX_DIGITS_LF],
						unsigned int i);
void					help_norme_lf(unsigned int res[MAX_DIGITS_LF],
						unsigned int pres, unsigned int point,
						unsigned int *length);
void					help_norme_2_lf(unsigned int res[MAX_DIGITS_LF],
						unsigned int res_copy[MAX_DIGITS_LF], unsigned int i);
void					make_copy_llf(unsigned int res[MAX_DIGITS_LLF],
						unsigned int res_copy[MAX_DIGITS_LLF]);
void					move_rigth_all_digits_llf(unsigned int
						res[MAX_DIGITS_LLF], unsigned int num,
						unsigned int length);
void					release_overflow_llf(unsigned int res[MAX_DIGITS_LLF],
						unsigned int i);
void					help_norme_llf(unsigned int res[MAX_DIGITS_LLF],
						unsigned int pres, unsigned int point,
						unsigned int *length);
void					help_norme_2_llf(unsigned int res[MAX_DIGITS_LLF],
						unsigned int res_copy[MAX_DIGITS_LLF], unsigned int i);

#endif
