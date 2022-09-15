/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:29:41 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/05 22:27:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char *base);

int	base_pre_check(const char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
	}
	if (i <= 1)
		return (0);
	i = -1;
	while (base[++i] != 0)
	{
		j = i;
		while (base[++j] != 0)
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

int	value_update(char c, const char *base, int *nbr, int pm)
{
	int	i;
	int	val;
	int	n;

	val = -999;
	i = -1;
	while (base[++i] != 0)
		if (c == base[i])
			val = i;
	n = i;
	if (val == -999)
		return (0);
	*nbr = *nbr * n + val * pm;
	return (1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	i;
	int	pm;
	int	res;

	res = 0;
	pm = 1;
	i = 0;
	while (str[i] != 0 && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++ ;
	while (str[i] != 0 && (str[i] == '-' || str [i] == '+'))
	{
		if (str[i] == '-')
			pm *= -1;
		i++;
		continue ;
	}
	while (str[i] != 0)
	{
		if (value_update(str[i], base, &res, pm) == 0)
			break ;
		i++;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		val;
	char	*arr;

	if (base_pre_check(base_from) != 0 && base_pre_check(base_to) != 0)
	{
		val = ft_atoi_base(nbr, base_from);
		arr = ft_putnbr_base(val, base_to);
		return (arr);
	}
	else
		return (NULL);
}
