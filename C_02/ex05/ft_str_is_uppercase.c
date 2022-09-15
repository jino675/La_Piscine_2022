/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:42:47 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/28 16:43:31 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			flag = 0;
			break ;
		}
		i++;
	}
	if (flag == 0)
		return (0);
	else
		return (1);
}
