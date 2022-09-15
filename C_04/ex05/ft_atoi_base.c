/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:23:20 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/06 11:50:18 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	i = -1;
	val = -999;
	while (base[++i] != 0)
	{
		if (c == base[i])
			val = i;
	}
	n = i;
	if (val == -999)
		return (0);
	*nbr = *nbr * n + val * pm;
	return (1);
}

void	initialize(int *i, int *f_s, int *f_pm, int *pm)
{
	*i = -1;
	*f_s = 1;
	*f_pm = 1;
	*pm = 1;
}

void	str_atoi(const char *str, const char *base, int *nbr)
{
	int	i;
	int	f_s;
	int	f_pm;
	int	pm;

	initialize(&i, &f_s, &f_pm, &pm);
	while (str[++i] != 0)
	{
		if (f_s && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'))
			continue ;
		if (f_s && (str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
			continue ;
		if (f_pm && (str[i] == '-' || str [i] == '+'))
		{
			pm *= 1 * (',' - str[i]);
			f_s = 0;
			continue ;
		}
		if (value_update(str[i], base, nbr, pm) == 0)
			break ;
		f_s = 0;
		f_pm = 0;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;

	nbr = 0;
	if (base_pre_check(base) != 0)
		str_atoi(str, base, &nbr);
	return (nbr);
}
