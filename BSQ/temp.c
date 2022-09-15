/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:42:08 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 09:35:40 by jiryu            ###   ########.fr       */
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
			return (print_error_r(NULL, 3));
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
		return (print_error_r(line, 2));
	return (0);
}

int	free_print_error_r(char **file, int *rc_max, int **line, int flag)
{
	int	i;

	i = -1;
	while (++i < rc_max[0])
		free(file[i]);
	free(file);
	return (print_error_r(line,flag));
}

int	rest_line(int fd, char *mark, t_type *p_max, int *rc_max)
{
	int		*line[2];
	int		idx[2];
	char	buf[1];

	char **file = (char **)malloc(sizeof(char *) * rc_max[0]);
	int i;
	i = -1;
	while (++i < rc_max[0])
	{
		file[i] = (char *)malloc(sizeof(char) * (rc_max[1] + 1));
		if (read(fd, file[i], rc_max[1] + 1) == -1)
			return (free_print_error_r(file, rc_max, NULL, 1));
	}
	close(fd);
	if (init_rest(line, p_max, rc_max[1]) == -1)
		return (-1);
	idx[0] = -1;
	while (++idx[0] < rc_max[0])
	{
		idx[1] = -1;
		while (++idx[1] < rc_max[1])
		{
			if (file[idx[0]][idx[1]] == '\n')
				return (free_print_error_r(file, rc_max, line, 1));
			if (calc_map(&file[idx[0]][idx[1]], mark, line, idx[1]) == -1)
				return (free_print_error_r(file, rc_max, NULL, -1));
			max_update(p_max, idx, line[1][idx[1]]);
		}
		if (file[idx[0]][idx[1]] != '\n')
			return (free_print_error_r(file, rc_max, line, 4));
		ptr_swap(line);
	}
	if (read(fd, buf, 1) != 0)
		return (free_print_error_r(file, rc_max, line, 5));
	free_print_error_r(file, rc_max, line, -1);
	return (0);
}
