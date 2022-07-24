/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:08:01 by nmilan            #+#    #+#             */
/*   Updated: 2022/07/24 22:03:46 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_var
{
	int	head;
	int	bloc;
	int	size;
	int	control_first_empty;
	int	i;
	int	is_first;
}	t_var;

void	ft_print_error(void);
int		ft_valid_args(char *str);
int		ft_strlen(char *str);
void	ft_print_bloc(int size, int fd, char *buffer);
void	ft_print_hundred(int fd, char *buffer);
void	ft_print_decade(char c, int fd, char *buffer);
void	ft_print_tens(int c, int fd, char *buffer);
void	ft_print_units(char c, int fd, char *buffer);
void	ft_print(char c, int head, char *buffer, char *dict);
void	bloc_select(char *str, char *buffer, char *dict);
int		ft_check(int size, char *buffer, char *dict);
void	search_in_bloc_ten(char caract, char *buffer, t_var *var, char *dict);
void	ft_search_in_bloc(char caract, char *buffer, t_var *var, char *dict);
void	ft_search_end_bloc(t_var var, char *buffer, char *dict);
void	ft_init_var(t_var *var, char *str);
int		ft_print_zero(char *dict, char *num);
//char	*ft_allocate(char *num);
//char	*ft_atoa(char *str);
int		ft_check_dict(char *buffer, char *dict);

#endif
