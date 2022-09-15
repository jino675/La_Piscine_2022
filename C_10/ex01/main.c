/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:10 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/13 15:21:13 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	error_check(char *pname, char *fname, int fd, int res)
{
	char	*emsg;

	if (fd == -1 || res == -1)
	{
		write(2, pname, ft_strlen(pname));
		write(2, ": ", 2);
		write(2, fname, ft_strlen(fname));
		write(2, ": ", 2);
		emsg = strerror(errno);
		write(2, emsg, ft_strlen(emsg));
		write(2, "\n", 1);
		return (-1);
	}
	return (0);
}

void	print_input(char **av)
{
	int		res;
	char	buf[1];

	while (1)
	{
		while (1)
		{
			res = read(0, buf, 1);
			if (error_check(basename(av[0]), NULL, 0, res) == -1)
				break ;
			if (res == 0)
				return ;
			write(1, buf, 1);
			if (buf[0] == '\n')
				break ;
		}
	}
}

void	print_files(int ac, char **av)
{
	int		i;
	int		res;
	int		fd;
	char	buf[1];

	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (error_check(basename(av[0]), av[i], fd, 0) == -1)
			continue ;
		while (1)
		{
			res = read(fd, buf, 1);
			if (error_check(basename(av[0]), av[i], 0, res) == -1 || res == 0)
				break ;
			write(1, buf, 1);
		}
		close(fd);
	}
}

int	main(int ac, char **av)
{
	if (ac < 1)
		return (-1);
	if (ac == 1)
		print_input(av);
	if (ac > 1)
		print_files(ac, av);
	return (0);
}
