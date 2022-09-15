/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:13:49 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/02 02:58:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

int	pre_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

void	pre_process(long long *lnbr)
{
	if (*lnbr < 0)
	{
		*lnbr *= -1;
		write(1, "-", 1);
	}
}

void	convert_print(long long lnbr, char *arr, char *base, int n)
{
	int	i;

	i = 0;
	while (1)
	{
		arr[i] = base[lnbr % n];
		lnbr /= n;
		if (lnbr == 0)
			break ;
		i++;
	}
	while (i >= 0)
	{
		write(1, &arr[i], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char		arr[33];
	int			n;
	long long	lnbr;

	if (pre_check(base) == 0)
		return ;
	n = ft_strlen(base);
	lnbr = (long long)nbr;
	pre_process(&lnbr);
	convert_print(lnbr, arr, base, n);
}
