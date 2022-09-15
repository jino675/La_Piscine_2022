/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:00:04 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/06 13:08:38 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_nbr(char *arr, int nbr)
{
	int	i;

	i = 0;
	while (1)
	{
		arr[i] = nbr % 10 + '0';
		nbr /= 10;
		i++;
		if (nbr == 0)
			break ;
	}
	while (--i >= 0)
		write(1, &arr[i], 1);
	write(1, "\n", 1);
}

void	print_str(char *str, int size)
{
	write(1, str, size);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;
	char	arr[33];

	i = -1;
	while (par[++i].str != NULL)
	{
		print_str(par[i].str, par[i].size);
		print_nbr(arr, par[i].size);
		print_str(par[i].copy, par[i].size);
	}
}
