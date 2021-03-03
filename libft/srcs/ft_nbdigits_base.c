/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigits_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abordack <abordack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:09:14 by abordack          #+#    #+#             */
/*   Updated: 2020/11/28 18:09:29 by abordack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_nbdigits_base(unsigned long long int nb, int base)
{
	int i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb != 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}
