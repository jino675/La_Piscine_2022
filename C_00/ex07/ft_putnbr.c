/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:55:45 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/28 06:01:33 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	pre_process(int *nb)
{
	if (*nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	if (*nb < 0)
	{
		*nb *= -1;
		write(1, "-", 1);
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	n[12];
	char	flag;

	flag = pre_process(&nb);
	if (flag == 0)
		return ;
	i = 0;
	while (1)
	{
		n[i] = nb % 10 + '0';
		nb /= 10;
		if (nb == 0)
			break ;
		i++;
	}
	while (i >= 0)
	{
		write(1, &n[i], 1);
		i--;
	}
}
