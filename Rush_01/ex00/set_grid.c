/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:04:44 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 22:29:31 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		read_write_arr_count(char *arr, int flag, int ic);
void	make_arr(char **arr, char *input, int ic, int m_lv);
void	memory_alloc_2(char ***arr, int ic);
void	memory_free(char **arr);

int	check_duple(char **grid, int i, int ic)
{
	int	j;
	int	k;

	j = -1;
	while (++j < ic / 4)
	{
		k = j;
		while (++k < ic / 4)
		{
			if (grid[j][i] == grid[k][i])
				return (1);
		}
	}
	return (0);
}

void	sg_max(char c, char *max, char *lr)
{
	if (*max < c)
	{
		(*lr)++;
		*max = c;
	}
}	

int	verify_grid(char **grid, char **input, int ic)
{
	int		i;
	int		j;
	char	left;
	char	right;
	char	max;

	i = -1;
	while (++i < ic / 4)
	{
		if (check_duple(grid, i, ic) == 1)
			return (0);
		j = 0;
		left = '1';
		max = grid[j][i];
		while (++j < ic / 4)
			sg_max(grid[j][i], &max, &left);
		j = ic / 4 - 1;
		right = '1';
		max = grid[j][i];
		while (--j >= 0)
			sg_max(grid[j][i], &max, &right);
		if (left != input[ic / 4 + i][0] || right != input[ic / 4 + i][1])
			return (0);
	}
	return (1);
}

int	last_session(char **grid, char **input, int ic)
{
	int	i;
	int	j;

	if (verify_grid(grid, input, ic) == 1)
	{
		i = -1;
		while (++i < ic / 4)
		{
			j = -1;
			while (++j < ic / 4)
			{
				write(1, &grid[j][i], 1);
				if (j != ic / 4 - 1)
					write(1, " ", 1);
			}
			write(1, "\n", 1);
		}
		return (1);
	}
	return (0);
}

int	set_grid(char **grid, char **input, int ic, int s_lv)
{
	int		i;
	int		j;
	char	**arr;

	s_lv++;
	if (s_lv == ic / 4)
	{
		if (last_session(grid, input, ic) == 1)
			return (1);
		return (0);
	}
	memory_alloc_2(&arr, ic);
	make_arr(arr, input[s_lv], ic, -1);
	i = -1;
	while (++i < read_write_arr_count(arr[99], 0, ic))
	{
		j = -1;
		while (++j < ic / 4)
			grid[s_lv][j] = arr[i][j];
		if (set_grid(grid, input, ic, s_lv) == 1)
			return (1);
	}
	memory_free(arr);
	return (0);
}
