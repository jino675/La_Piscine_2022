/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 07:10:02 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/02 01:08:06 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initialization(int *pm, int *nbr, int *flag_s, int *flag_pm)
{
	*pm = 1;
	*nbr = 0;
	*flag_s = 0;
	*flag_pm = 0;
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int	is_plus_minus(char c, int *pm)
{
	if (c == '-')
	{
		*pm *= -1;
		return (1);
	}
	else if (c == '+')
		return (1);
	else
		return (0);
}

void	nbr_process(char c, int *nbr, int pm)
{
	if (pm == 1)
		*nbr = *nbr * 10 + (c - '0');
	else if (pm == -1)
		*nbr = *nbr * 10 - (c - '0');
}

int	ft_atoi(char *str)
{
	int	i;
	int	pm;
	int	nbr;
	int	flag_s;
	int	flag_pm;

	initialization(&pm, &nbr, &flag_s, &flag_pm);
	i = -1;
	while (str[++i] != 0)
	{
		if (is_space(str[i]) && flag_s == 0)
			continue ;
		if (is_plus_minus(str[i], &pm) && flag_pm == 0)
		{
			flag_s = 1;
			continue ;
		}
		if (str[i] < '0' || str[i] > '9')
			break ;
		nbr_process(str[i], &nbr, pm);
		flag_s = 1;
		flag_pm = 1;
	}
	return (nbr);
}
