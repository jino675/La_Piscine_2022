/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:42:26 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/31 21:03:54 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex_16_write(unsigned char *cptr)
{
	int					i;
	char				hex[16];
	unsigned long long	p;

	i = 0;
	p = (unsigned long long)cptr;
	while (i < 16)
	{
		if (p % 16 < 10)
			hex[i] = p % 16 + '0';
		else
			hex[i] = p % 16 - 10 + 'a';
		p /= 16;
		i++;
	}
	i = 15;
	while (i >= 0)
	{
		write(1, &hex[i], 1);
		i--;
	}
	write(1, ": ", 2);
}

void	hex_02_write(unsigned char *cptr, int size, int flag)
{
	char	hex[2];
	int		iter;
	int		i;

	if (flag == 1 && size % 16 != 0)
		iter = size % 16;
	else
		iter = 16;
	i = -1;
	while (++i < iter)
	{
		if (cptr[i] / 16 < 10)
			hex[0] = cptr[i] / 16 + '0';
		else
			hex[0] = cptr[i] / 16 - 10 + 'a';
		if (cptr[i] % 16 < 10)
			hex[1] = cptr[i] % 16 + '0';
		else
			hex[1] = cptr[i] % 16 - 10 + 'a';
		write(1, hex, 2);
		if (i % 2 == 1)
			write(1, " ", 1);
	}
	while (i++ < 16)
		write(1, " ", 1);
}

void	char_16_write(unsigned char *cptr, int size, int flag)
{
	int	i;
	int	iter;

	i = 0;
	if (flag == 1 && size % 16 != 0)
		iter = size % 16;
	else
		iter = 16;
	while (i < iter)
	{
		if (cptr[i] < ' ' || cptr[i] >= 127)
			write(1, ".", 1);
		else
			write(1, &cptr[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				flag;
	unsigned int	low_len;
	unsigned char	*cptr;

	cptr = (unsigned char *)addr;
	low_len = size / 16;
	if (size % 16 != 0)
		low_len++;
	flag = 0;
	i = 0;
	while (i < low_len)
	{
		if (i == low_len - 1)
			flag = 1;
		hex_16_write(cptr + (16 * i));
		hex_02_write(cptr + (16 * i), size, flag);
		char_16_write(cptr + (16 * i), size, flag);
		i++;
	}
	return (addr);
}
