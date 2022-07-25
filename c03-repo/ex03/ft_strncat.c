/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:35:59 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/13 10:38:06 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_index;
	unsigned int	src_index;

	dest_index = 0;
	src_index = 0;
	while (dest[dest_index])
	{
		dest_index++;
	}
	if (nb == 0)
		return (dest);
	while (src[src_index] && src_index < nb)
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (dest);
}
