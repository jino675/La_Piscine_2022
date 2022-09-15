/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:51:59 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/13 08:54:52 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	pre_process_file(char *pname, char *fname, long long *size)
{
	int		res;
	int		fd;
	char	buf[1];

	fd = open(fname, O_RDONLY);
	if (error_check(pname, fname, fd, 0) == -1)
		return (-1);
	*size = 0;
	while (1)
	{
		res = read(fd, buf, 1);
		if (error_check(pname, fname, 0, res) == -1)
			return (-1);
		if (res == 0)
			break ;
		(*size)++;
	}
	close(fd);
	return (0);
}

int	pro_process_file(char *pname, char *fname, long long size, long long num)
{
	int		i;
	int		fd;
	int		res;
	char	buf[1];

	if (size <= num)
		num = size;
	fd = open(fname, O_RDONLY);
	i = -1;
	while (++i < size - num)
	{
		res = read(fd, buf, 1);
		if (error_check(pname, fname, 0, res) == -1)
			return (-1);
	}
	i = -1;
	while (++i < num)
	{
		res = read(fd, buf, 1);
		if (error_check(pname, fname, 0, res) == -1)
			return (-1);
		write(1, buf, 1);
	}
	close(fd);
	return (0);
}

void	print_file(int ac, char **av, long long num)
{
	int			i;
	int			flag;
	long long	size;

	i = 2;
	flag = 0;
	while (++i < ac)
	{
		if (pre_process_file(basename(av[0]), av[i], &size) == -1)
			continue ;
		if (ac > 4)
			print_filename(av[i], flag);
		if (pro_process_file(basename(av[0]), av[i], size, num) == -1)
			continue ;
		flag = 1;
	}
}

int	process_input(char *buf, char *pname, long long num)
{
	long long	end;
	int			res;
	int			flag;

	flag = 0;
	end = 0;
	while (1)
	{
		res = read(0, &buf[end], 1);
		if (error_check(pname, NULL, 0, res) == -1)
			return (-1);
		if (res == 0)
			break ;
		end++;
		if (end == num || num == 0)
		{
			end = 0;
			flag = 1;
		}
	}
	if (flag == 1)
		write(1, buf + end, num - end);
	write(1, buf, end);
	return (0);
}

int	print_input(char *pname, long long num)
{
	char		*buf;

	buf = (char *)malloc(sizeof(char) * num);
	if (error_check_2(basename(pname), NULL, -999, buf))
		return (-1);
	if (process_input(buf, basename(pname), num) == -1)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	return (0);
}
