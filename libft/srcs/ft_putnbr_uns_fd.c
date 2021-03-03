/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abordack <abordack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:09:46 by abordack          #+#    #+#             */
/*   Updated: 2020/11/28 18:09:48 by abordack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_uns_fd(unsigned long long int u_n, int fd)
{
	if (u_n > 9)
	{
		ft_putnbr_uns_fd(u_n / 10, fd);
		ft_putchar_fd('0' + u_n % 10, fd);
	}
	else
		ft_putchar_fd('0' + u_n, fd);
}
