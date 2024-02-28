/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igama <igama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:09:02 by igama             #+#    #+#             */
/*   Updated: 2024/02/28 13:09:05 by igama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_counter(char *str, char c)
{
	int	i;
	int	indicator;
	int	nstr;

	i = 0;
	nstr = 0;
	while (str[i])
	{
		indicator = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			indicator = 1;
			i++;
		}
		while (str[i] == c && str[i])
			i++;
		if (indicator == 1)
			nstr++;
	}
	return (nstr);
}

static int	str_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ptr_free(char **ptr, int i)
{
	while (i > 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		nstr;
	int		i;

	if (!s)
		return (NULL);
	nstr = str_counter((char *)s, c);
	ptr = (char **)malloc((nstr + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (nstr > 0)
	{
		while (*s && *s == c)
			s++;
		ptr[i] = ft_substr(s, 0, str_len(s, c));
		if (!ptr[i])
			return (ptr_free(ptr, i));
		s = s + str_len(s, c);
		i++;
		nstr--;
	}
	ptr[i] = 0;
	return (ptr);
}
