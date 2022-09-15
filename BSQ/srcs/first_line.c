/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:41:59 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 12:29:14 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//check length of first line
int	calc_column(int *len, char *fname, char *buf)
{
	int		fd;
	int		flag;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
		return (print_error_f(0, NULL, 0));
	flag = 0;
	while (1)
	{
		if (read(fd, buf, 1) <= 0)
			return (print_error_f(fd, NULL, 1));
		if (flag == 0 && buf[0] == '\n')
		{
			flag = 1;
			continue ;
		}
		if (flag == 1 && buf[0] == '\n')
			break ;
		len[flag]++;
	}
	if (len[0] <= 3 || len[1] == 0)
		return (print_error_f(fd, NULL, 2));
	close(fd);
	return (0);
}

//read r_max part
int	calc_row(int *fd, char *fname, int *len, int *r_max)
{
	int		i;
	char	*nbr;

	*fd = open(fname, O_RDONLY);
	if (*fd == -1)
		return (print_error_f(0, NULL, 0));
	nbr = (char *)malloc(sizeof(char) * (len[0] - 3));
	if (nbr == NULL)
		return (print_error_f(*fd, NULL, 3));
	if (read(*fd, nbr, len[0] - 3) <= 0)
		return (print_error_f(*fd, nbr, 99));
	i = -1;
	*r_max = 0;
	while (++i < len[0] - 3)
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (print_error_f(*fd, nbr, 8));
		*r_max = *r_max * 10 + nbr[i] - '0';
	}
	if (*r_max <= 0)
		return (print_error_f(*fd, nbr, 9));
	free(nbr);
	return (0);
}

//read mark part
//transfer to next line
int	first_line(int *fd, char *fname, char *mark, int *r_max)
{
	int		i;
	int		len[2];
	char	buf[1];

	len[0] = 0;
	len[1] = 0;
	if (calc_column(len, fname, buf) == -1)
		return (-1);
	if (calc_row(fd, fname, len, r_max) == -1)
		return (-1);
	if (read(*fd, mark, 3) <= 0)
		return (print_error_f(*fd, NULL, 99));
	if (mark[0] == mark[1] || mark[0] == mark[2] || mark[1] == mark[2])
		return (print_error_f(*fd, NULL, 7));
	i = -1;
	while (++i < 3)
		if (mark[i] < 32 || mark[i] >= 127)
			return (print_error_f(*fd, NULL, 6));
	if (read(*fd, buf, 1) <= 0 || buf[0] != '\n')
		return (print_error_f(*fd, NULL, 99));
	return (len[1]);
}
