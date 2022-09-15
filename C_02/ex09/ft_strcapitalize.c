/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:18:45 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/28 21:20:06 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_flag(char *str, int i, int *flag)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		if (*flag == 0)
			*flag = 1;
	}
	else if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if (*flag == 0)
			*flag = 1;
	}
	else if (str[i] >= '0' && str[i] <= '9')
	{
		if (*flag == 0)
			*flag = 1;
	}
	else
	{
		if (*flag > 0)
			*flag = 0;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] != 0)
	{
		set_flag(str, i, &flag);
		if (flag > 0)
		{
			if (flag == 1)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 'a' - 'A';
			}
			else if (flag > 1)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 'a' - 'A';
			}
			flag++;
		}
		i++;
	}
	return (str);
}
