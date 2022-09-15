/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:06:59 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/13 09:02:49 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_filename(char *fname, int flag)
{
	if (flag == 1)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	write(1, fname, ft_strlen(fname));
	write(1, " <==\n", 5);
}

int	error_check(char *pname, char *fname, int fd, int res)
{
	char	*emsg;

	if (fd == -1 || res == -1)
	{
		write(2, pname, ft_strlen(pname));
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

int	error_check_2(char *pname, char *fname, long long num, char *buf)
{
	if (num == -1)
	{
		write(2, pname, ft_strlen(pname));
		write(2, ": ", 2);
		write(2, "illegal offset -- ", 18);
		write(2, fname, ft_strlen(fname));
		write(2, "\n", 1);
		return (-1);
	}
	if (num == -999 && buf == NULL)
	{
		write(2, pname, ft_strlen(pname));
		write(2, ": malloc: Cannot allocate memory\n", 33);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	long long	num;

	if (ac < 3)
		return (-1);
	num = ft_atoi(av[2]);
	if (error_check_2(basename(av[0]), av[2], num, NULL) == -1)
		return (-1);
	if (ac > 3)
		print_file(ac, av, num);
	else if (ac == 3)
		if (print_input(av[0], num) == -1)
			return (-1);
	return (0);
}
