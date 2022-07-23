/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:34:24 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/22 13:53:02 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# define EVEN_MSG "I have an even number of arguments\n"
# define ODD_MSG "I have an odd number of arguments\n"
# define TRUE 1
# define FALSE 0
# define EVEN(x) x % 2 == 0
# define SUCCESS 0
#include <unistd.h>

typedef int t_bool;

#endif
