/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abordack <abordack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:37:29 by abordack          #+#    #+#             */
/*   Updated: 2020/05/01 19:37:30 by abordack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char const	*is_in_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i++])
		if (c == set[i - 1])
			return (set + i - 1);
	return (NULL);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	if (i == j)
		len = 0;
	else
	{
		while (j >= i && is_in_set(s1[j], set))
			j--;
		len = j - i + 1;
	}
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	return (ft_substr(s1, i, len));
}
