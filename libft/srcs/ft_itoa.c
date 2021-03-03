/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abordack <abordack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:37:16 by abordack          #+#    #+#             */
/*   Updated: 2020/05/02 18:42:37 by abordack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int nbr)
{
	int		i;
	int		n;
	int		neg;
	char	*str;

	i = 1;
	n = nbr;
	neg = nbr < 0;
	while (n /= 10)
		i++;
	if (!(str = malloc((i + 1 + neg) * sizeof(char))))
		return (NULL);
	if (neg)
		*str++ = '-';
	str += i;
	*str-- = 0;
	if (nbr == 0)
		*str-- = '0';
	while (nbr)
	{
		*str-- = (nbr % 10) * (neg ? -1 : 1) + '0';
		nbr /= 10;
	}
	return (str + 1 - neg);
}
