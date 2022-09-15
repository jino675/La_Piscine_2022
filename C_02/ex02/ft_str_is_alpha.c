/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:51:06 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/28 16:10:53 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			if (!(str[i] >= 'A' && str[i] <= 'Z'))
			{
				flag = 0;
				break ;
			}
		}
		i++;
	}
	if (flag == 0)
		return (0);
	else
		return (1);
}
