/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:48:31 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 22:54:27 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_input(char **av, char *buf, int flag)
{
	int		res;
	int		idx;
	int		size;
	int		equal;
	int		ext;
	char	c;

	ext = 0;
	equal = 0;
	idx = 0;
	size = 0;
	while (1)
	{
		if (size > 15)
			c = buf[idx];
		res = read(0, &buf[idx], 1);
		if (error_check(av[0], NULL, 0, res) == -1)
			break ;
		if (size > 15 && c == buf[idx])
			equal++;
		if (res == 0 && (idx == 0 || ext == 1))
			break ;
		if (idx == 15 && equal == 16)
			write(1, "*\n", 2);
		if (idx == 15 && (equal == 0 || equal % 16 != 0))
		{
			print_line(buf, size - 15, 16, flag);
			equal = 0;
		}
		idx = (idx + 1) % 16;
		size++;
		ext = (res == 0);
	}
	print_line(buf, size - idx, idx, flag);
	print_size(size, 7 + flag);
	write(1, "\n", 1);
}
