/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_perm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:15:31 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 22:27:13 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	read_write_arr_count(char *arr, int flag, int ic);

char	mp_max(char **arr, char *max, int ac, int i)
{
	*max = arr[ac][i];
	return (1);
}

void	mp_last_session(char **arr, char *input, int ic)
{
	int		i;
	char	up;
	char	down;
	int		ac;
	char	max;

	ac = read_write_arr_count(arr[99], 0, ic);
	i = 0;
	up = '1';
	max = arr[ac][i];
	while (++i < ic / 4)
		if (max < arr[ac][i])
			up += mp_max(arr, &max, ac, i);
	i = ic / 4 - 1;
	down = '1';
	max = arr[ac][i];
	while (--i >= 0)
		if (max < arr[ac][i])
			down += mp_max(arr, &max, ac, i);
	if (up == input[0] && down == input[1])
		read_write_arr_count(arr[99], 1, ic);
}

int	sub_make_arr(char **arr, int m_lv, int val, int ic)
{
	int	ac;
	int	i;

	ac = read_write_arr_count(arr[99], 0, ic);
	i = -1;
	while (++i < m_lv)
	{
		if (arr[ac][i] == val + '0')
			return (1);
	}
	return (0);
}

int	mp_arr(char **arr, int ac, int m_lv)
{
	int	i;

	i = -1;
	while (++i < m_lv)
		arr[ac][i] = arr[ac - 1][i];
	return (ac);
}

void	make_arr(char **arr, char *input, int ic, int m_lv)
{
	int	i;
	int	ac;
	int	temp_ac;

	m_lv++;
	if (m_lv == ic / 4)
	{
		mp_last_session(arr, input, ic);
		return ;
	}
	i = 0;
	temp_ac = read_write_arr_count(arr[99], 0, ic);
	while (++i <= ic / 4)
	{
		ac = read_write_arr_count(arr[99], 0, ic);
		if (temp_ac != ac)
			temp_ac = mp_arr(arr, ac, m_lv);
		if (sub_make_arr(arr, m_lv, i, ic) == 1)
			continue ;
		arr[ac][m_lv] = i + '0';
		make_arr(arr, input, ic, m_lv);
	}
}	
