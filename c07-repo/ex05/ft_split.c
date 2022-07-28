/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habelhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:13:58 by habelhad          #+#    #+#             */
/*   Updated: 2022/07/28 07:27:25 by habelhad         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_is_strchr(char *charset, char c)
{
	int	i;
	int	is_charset;

	i = 0;
	is_charset = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			is_charset = 1;
		i++;
	}
	return (is_charset);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (!ft_is_strchr(charset, str[i]))
		{
			word++;
			while (!ft_is_strchr(charset, str[i]) && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (word);
}

int	ft_get_size(char *str, char *charset, int i)
{
	int	size;

	size = 0;
	while (str[i] && !ft_is_strchr(charset, str[i]))
	{
		size++;
		i++;
	}
	return (size);
}

char	*ft_strcpy(char *str, int size, int i)
{
	int		j;
	char	*substr;

	substr = (char *)malloc(sizeof(char *) * (size + 1));
	if (!substr)
		return (NULL);
	j = 0;
	size = size + i;
	while (i < size)
	{
		substr[j] = str[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	**ft_split(char *str, char *charset)
{
	int		word;
	char	**strs;
	int		i;
	int		j;
	int		word_length;

	i = 0;
	j = -1;
	word = ft_count_word(str, charset);
	strs = (char **)malloc(sizeof(char *) * (word + 1));
	if (!strs)
		return (NULL);
	while (j++ < word)
	{
		while (ft_is_strchr(charset, str[i]))
			i++;
		word_length = ft_get_size(str, charset, i);
		strs[j] = ft_strcpy(str, word_length, i);
		i += word_length;
	}
	strs[j - 1] = 0;
	return (strs);
}
