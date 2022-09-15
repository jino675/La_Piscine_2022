/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:41:40 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/27 22:30:33 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec_print(int n, int i, char *nbr)
{
	i++;
	if (i == n)
	{
		write(1, nbr, n);
		if (!(nbr[0] == 10 + '0' - n && nbr[n - 1] == 9 + '0'))
			write(1, ", ", 2);
		return ;
	}
	nbr[i] = 0 + '0';
	while (nbr[i] < 10 + '0' - (n - i - 1))
	{
		if (i > 0)
			while (nbr[i - 1] >= nbr[i])
				nbr[i]++;
		rec_print(n, i, nbr);
		nbr[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	nbr[10];
	int		i;

	i = -1;
	rec_print(n, i, nbr);
}
