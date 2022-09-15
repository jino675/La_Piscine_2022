/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:42:08 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 12:21:33 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	init_rest(int **line, t_type *p_max, int c_max)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 2)
	{
		line[i] = (int *)malloc(sizeof(int) * c_max);
		if (line[i] == NULL)
			return (print_error_r(0, NULL, 3));
		j = -1;
		while (++j < c_max)
			line[i][j] = 0;
	}
	p_max->x = 0;
	p_max->y = 0;
	p_max->val = 0;
	return (0);
}

void	max_update(t_type *p_max, int *idx, int val)
{
	if (val > p_max->val)
	{
		p_max->x = idx[0];
		p_max->y = idx[1];
		p_max->val = val;
	}
}

void	ptr_swap(int **line)
{
	int	*temp;

	temp = line[0];
	line[0] = line[1];
	line[1] = temp;
}

int	calc_map(char *buf, char *mark, int **line, int j)
{
	int	min;

	if (buf[0] == mark[0])
	{
		line[1][j] = 1;
		if (j > 0)
		{
			min = line[1][j - 1];
			if (min > line[0][j - 1])
				min = line[0][j - 1];
			if (min > line[0][j])
				min = line[0][j];
			line[1][j] += min;
		}
	}
	else if (buf[0] == mark[1])
		line[1][j] = 0;
	else
		return (print_error_r(0, line, 2));
	return (0);
}

int	rest_line(int fd, char *mark, t_type *p_max, int *rc_max)
{
	int		*line[2];
	int		idx[2];
	char	buf[1];

	if (init_rest(line, p_max, rc_max[1]) == -1)
		return (print_error_r(fd, NULL, -999));
	idx[0] = -1;
	while (++idx[0] < rc_max[0])
	{
		idx[1] = -1;
		while (++idx[1] < rc_max[1])
		{
			if (read(fd, buf, 1) <= 0 || buf[0] == '\n')
				return (print_error_r(fd, line, 1));
			if (calc_map(buf, mark, line, idx[1]) == -1)
				return (print_error_r(fd, NULL, -999));
			max_update(p_max, idx, line[1][idx[1]]);
		}
		if (read(fd, buf, 1) <= 0 || buf[0] != '\n')
			return (print_error_r(fd, line, 4));
		ptr_swap(line);
	}
	if (read(fd, buf, 1) != 0)
		return (print_error_r(fd, line, 5));
	return (print_error_r(fd, line, -900));
}
