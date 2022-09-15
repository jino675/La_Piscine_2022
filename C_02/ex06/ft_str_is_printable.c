/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:49:49 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/31 18:26:03 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < ' ' || str[i] == 127)
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
