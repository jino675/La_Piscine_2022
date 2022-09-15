/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 07:10:02 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/13 06:50:27 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

long long	ft_atoi(char *str)
{
	int			i;
	int			flag;
	long long	nbr;

	i = 0;
	nbr = 0;
	flag = 0;
	while (str[i] != '\0' && is_space(str[i]) == 1)
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
		if (nbr < 0)
			flag = 1;
	}
	if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		return (-1);
	if (flag == 1)
		nbr = 9223372036854775807;
	return (nbr);
}
