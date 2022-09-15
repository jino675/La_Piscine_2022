/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:47:50 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/03 15:06:25 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_slot(char *arr, int lv, int i)
{
	int	t_lv;
	int	j;

	t_lv = lv - 1;
	j = 1;
	while (t_lv >= 0)
	{
		if (arr[t_lv] == i + '0')
			return (1);
		if (arr[t_lv] == i - j + '0' || arr[t_lv] == i + j + '0')
			return (1);
		t_lv--;
		j++;
	}
	return (0);
}

void	rec_queens(char *arr, int lv, int *n)
{
	int	i;

	lv++;
	if (lv == 10)
	{
		(*n)++;
		write(1, arr, 10);
		write(1, "\n", 1);
		return ;
	}
	i = -1;
	while (++i < 10)
	{
		if (check_slot(arr, lv, i) == 1)
			continue ;
		arr[lv] = i + '0';
		rec_queens(arr, lv, n);
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	arr[10];
	int		lv;
	int		n;

	lv = -1;
	n = 0;
	rec_queens(arr, lv, &n);
	return (n);
}
