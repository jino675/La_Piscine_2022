/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:51:59 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 22:09:40 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_size(int size, int lv)
{
	if (lv == 1)
	{
		write(1, &("0123456789abcdef"[size]), 1);
		return ;
	}
	else
		print_size(size / 16, lv - 1);
	write(1, &("0123456789abcdef"[size % 16]), 1);
}

void	print_hex(char *buf, int iter, int flag)
{
	int				i;
	unsigned char	c;

	i = -1;
	while (++i < 16)
	{
		if (i < iter)
		{
			c = (unsigned char)buf[i];
			write(1, &("0123456789abcdef"[c / 16]), 1);
			write(1, &("0123456789abcdef"[c % 16]), 1);
		}
		else
			write(1, "  ", 2);
		if (i != 15)
			write(1, " ", 1);
		if (i == 7 && flag == 1)
			write(1, " ", 1);
	}
}

void	print_char(char *buf, int iter)
{
	int	i;

	write(1, "|", 1);
	i = -1;
	while (++i < iter)
	{
		if (buf[i] < 32 || buf[i] == 127)
			write(1, ".", 1);
		else
			write(1, &buf[i], 1);
	}
	write(1, "|", 1);
}

int	print_line(char *buf, int size, int iter, int flag)
{
	if (iter == 0)
		return (0);
	print_size(size, 7 + flag);
	write(1, " ", 1);
	if (flag == 1)
		write(1, " ", 1);
	print_hex(buf, iter, flag);
	if (flag == 1)
	{
		write(1, "  ", 2);
		print_char(buf, iter);
	}
	write(1, "\n", 1);
	return (0);
}

void	print_hexdump(int ac, char **av, char *buf, int flag)
{
	int		fd;
	int		res;
	int		i;
	int		idx;
	int		size;

	i = flag;
	idx = 0;
	size = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (error_check(av[0], av[i], fd, 0) == -1)
			continue ;
		while (1)
		{
			res = read(fd, &buf[idx], 1);
			if (error_check(av[0], av[i], 0, res) == -1)
				break ;
			if (res == 0)
				break ;
			if (idx == 15)
				idx = print_line(buf, size - 15, 16, flag);
			else
				idx++;
			size++;
		}
		close(fd);
	}
	print_line(buf, size - idx, idx, flag);
	print_size(size, 7 + flag);
	write(1, "\n", 1);
}
