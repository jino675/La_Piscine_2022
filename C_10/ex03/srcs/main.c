/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:06:59 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/16 06:00:08 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	error_check(char *pname, char *fname, int fd, int res)
{
	char	*emsg;

	if (fd == -1 || res == -1)
	{
		write(2, basename(pname), ft_strlen(pname));
		write(2, ": ", 2);
		if (fname != NULL)
		{
			write(2, fname, ft_strlen(fname));
			write(2, ": ", 2);
		}
		emsg = strerror(errno);
		write(2, emsg, ft_strlen(emsg));
		write(2, "\n", 1);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	buf[16];

	if (ac < 1)
		return (-1);
	if (ac == 1)
		print_input(av, buf, 0);
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "-C") == 0)
			print_input_C(av, buf);
		else
			print_hexdump(ac, av, buf, 0);
	}
	if (ac >= 3)
	{
		if (ft_strcmp(av[1], "-C") == 0)
			print_hexdump(ac, av, buf, 1);
		else
			print_hexdump(ac, av, buf, 0);
	}
	return (0);
}
