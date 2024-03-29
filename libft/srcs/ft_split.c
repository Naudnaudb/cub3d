/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abordack <abordack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:37:26 by abordack          #+#    #+#             */
/*   Updated: 2020/05/01 19:37:26 by abordack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	stringscount(char const *s, char c)
{
	int	comp;
	int	new_word;

	comp = 0;
	new_word = 1;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == c)
			new_word = 1;
		else if (new_word == 1)
		{
			new_word = 0;
			comp++;
		}
		s++;
	}
	return (comp);
}

static int	charscount(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	free_all(char **dst, int j)
{
	while (j-- > 0)
		free(dst[j]);
	free(dst);
}

static void	fill(char const *s, char ***dst, char c, int nbstrings)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < nbstrings)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(dst[0][j] = (char *)malloc(charscount(s, c, i) + 1)))
		{
			free_all(*dst, j);
			*dst = NULL;
			return ;
		}
		while (s[i] != 0 && s[i] != c)
			dst[0][j][k++] = s[i++];
		dst[0][j][k] = 0;
		j++;
	}
}

char		**ft_split(char const *s, char c)
{
	char	**dst;
	int		nbstrings;

	if (s == NULL)
		return (NULL);
	nbstrings = stringscount(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (nbstrings + 1))))
		return (NULL);
	dst[nbstrings] = NULL;
	fill(s, &dst, c, nbstrings);
	return (dst);
}
