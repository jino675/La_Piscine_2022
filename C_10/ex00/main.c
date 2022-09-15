/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:31:41 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/13 09:52:12 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ac_check(int ac)
{
	if (ac == 1)
	{
		write(2, "File name missing.\n", 19);
		return (-1);
	}
	else if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (-1);
	}
	return (0);
}

int	fr_check(int fr)
{
	if (fr == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	int		res;
	char	buf[1];

	if (ac_check(ac) == -1)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fr_check(fd) == -1)
		return (-1);
	while (1)
	{
		res = read(fd, buf, 1);
		if (fr_check(res) == -1)
			return (-1);
		if (res == 0)
			break ;
		write(1, buf, 1);
	}
	close(fd);
	return (0);
}
