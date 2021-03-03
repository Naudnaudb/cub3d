/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns_base_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abordack <abordack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:09:42 by abordack          #+#    #+#             */
/*   Updated: 2020/11/28 18:09:45 by abordack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_uns_base_fd(unsigned long long int u_n, int fd, char *charset)
{
	unsigned long long int	base;

	base = ft_strlen(charset);
	if (u_n >= base)
	{
		ft_putnbr_uns_base_fd(u_n / base, fd, charset);
		ft_putchar_fd(charset[u_n % base], fd);
	}
	else
		ft_putchar_fd(charset[u_n], fd);
}
