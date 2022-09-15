/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:32:13 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/05 22:11:37 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	pre_process(char *arr, int nbr, char *base, int *flag)
{
	int		i;
	int		n;
	long	lnbr;

	n = ft_strlen(base);
	lnbr = (long)nbr;
	if (lnbr < 0)
	{
		lnbr *= -1;
		*flag = 1;
	}
	i = 0;
	while (1)
	{
		arr[i] = base[lnbr % n];
		lnbr /= n;
		i++;
		if (lnbr == 0)
			break ;
	}
	return (i);
}

void	sub_make_arr(char *res, char *arr, int len, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		res[i] = '-';
		i++;
	}
	while (--len >= 0)
	{
		res[i] = arr[len];
		i++;
	}
	res[i] = '\0';
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char	arr[33];
	int		flag;
	int		len;
	char	*res;

	flag = 0;
	len = pre_process(arr, nbr, base, &flag);
	res = (char *)malloc(sizeof(char) * (len + 1 + flag));
	sub_make_arr(res, arr, len, flag);
	return (res);
}
