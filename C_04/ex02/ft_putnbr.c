/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 06:47:24 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/01 16:23:56 by jiryu            ###   ########.fr       */
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
	else if (*nb < 0)
	{
		*nb *= -1;
		write(1, "-", 1);
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	arr[10];

	if (pre_process(&nb) == 0)
		return ;
	i = 0;
	while (1)
	{
		arr[i] = nb % 10 + '0';
		nb /= 10;
		if (nb == 0)
			break ;
		i++;
	}
	while (i >= 0)
	{
		write(1, &arr[i], 1);
		i--;
	}
}
