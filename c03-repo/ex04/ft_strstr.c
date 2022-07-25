/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:57:13 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/13 10:46:56 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

struct	s_vars
{
	int	i;
	int	j;
	int	k;
};

char	*ft_strstr(char *str, char *to_find)
{
	struct s_vars	var;

	var = (struct s_vars){0, 0, 0};
	if (*to_find == '\0')
		return (str);
	while (str[var.i])
	{
		if (str[var.i] == to_find[var.j])
		{
			var.k = var.i;
			while (to_find[var.j])
			{
				if (to_find[var.j] == str[var.k])
					var.k++;
				else
					break ;
				var.j++;
			}
			if (0 == to_find[var.j])
				return (&str[var.i]);
			var.j = 0;
		}
		var.i++;
	}
	return (0);
}
