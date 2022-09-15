/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:05:19 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/31 18:23:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_write(char c)
{
	char			hex[2];
	unsigned char	h;

	h = (unsigned char)c;
	if (h / 16 < 10)
		hex[0] = h / 16 + '0';
	else
		hex[0] = h / 16 - 10 + 'a';
	if (h % 16 < 10)
		hex[1] = h % 16 + '0';
	else
		hex[1] = h % 16 - 10 + 'a';
	write(1, "\\", 1);
	write(1, hex, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < ' ' || str[i] >= 127)
			convert_write(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
