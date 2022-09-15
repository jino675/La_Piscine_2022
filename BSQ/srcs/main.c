/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:17:15 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 12:26:12 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
int	print_error_f(char *nbr, int flag)
{
	if (flag == 0)
		write(2, "can not open this file...\n", 26);
	if (flag == 1)
		write(2, "map must have more than 1 line\n", 31);
	if (flag == 2)
		write(2, "first line's minimum length is four\n", 36);
	if (flag == 3)
		write(2, "memory allocation error!\n", 25);
	if (flag == 5)
		write(2, "too many lines!\n", 16);
	if (flag == 6)
		write(2, "marks must be consist of printable letters\n", 43);
	if (flag == 7)
		write(2, "marks must be different each other\n", 35);
	if (flag == 8)
		write(2, "numbers have to be consist of numbers\n", 38);
	if (flag == 9)
		write(2, "input number is zero or make overflow\n", 38);
	if (flag == 99)
		write(2, "I don't know why...\n", 20);
*/	
int	print_error_f(int fd, char *nbr, int flag)
{
	if ((flag != 3 && flag >= 0 && flag <= 9) || flag == 99)
		write(2, "map error\n", 10);
	free(nbr);
	if (fd != 0)
		close(fd);
	return (-1);
}

/*
int	print_error_r(int **line, int flag)
{
	if (flag == 0)
		write(2, "can not open this file...\n", 26);
	if (flag == 1)
		write(2, "this line is too short\n", 23);
	if (flag == 2)
		write(2, "map must be consist of marks\n", 29);
	if (flag == 3)
		write(2, "memory allocation error!\n", 25);
	if (flag == 4)
		write(2, "this line is too long\n", 22);
	if (flag == 5)
		write(2, "too many lines!\n", 16);
	if (flag == 6)
		write(2, "stdin error\n", 12);
	if (flag == 99)
		write(2, "I don't know why...\n", 20);
*/	
int	print_error_r(int fd, int **line, int flag)
{
	if ((flag != 3 && flag >= 0 && flag <= 6) || flag == 99)
		write(2, "map error\n", 10);
	if (line != NULL)
	{
		free(line[0]);
		free(line[1]);
	}
	if (fd != 0)
		close(fd);
	if (flag == -900)
		return (0);
	return (-1);
}

int	from_input(void)
{
	int		fd;
	int		res;
	char	*fname;
	char	buf[1];

	fname = ".temp_map_for_stdin.tmp";
	fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
	while (1)
	{
		res = read(0, buf, 1);
		if (res < 0)
			return (print_error_r(fd, NULL, 6));
		if (res == 0)
			break ;
		write(fd, buf, 1);
	}
	close(fd);
	from_files(fname);
	return (0);
}

void	from_files(char *fname)
{
	int		fd;
	int		rc_max[2];
	char	mark[3];
	t_type	p_max;

	rc_max[1] = first_line(&fd, fname, mark, &rc_max[0]);
	if (rc_max[1] == -1)
		return ;
	if (rest_line(fd, mark, &p_max, rc_max) == -1)
		return ;
	if (print_map(fname, mark, &p_max, rc_max) == -1)
		return ;
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 1)
		return (-1);
	if (ac == 1)
		if (from_input() == -1)
			return (-1);
	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
		{
			from_files(av[i]);
		}
	}
	return (0);
}
//	system("leaks bsq");
