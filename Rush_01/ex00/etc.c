/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:46:34 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 22:24:28 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	read_write_arr_count(char *arr, int flag, int ic)
{
	int	i;
	int	temp;

	temp = 0;
	i = -1;
	while (++i < ic / 4)
		temp = temp * 10 + arr[i] - '0';
	if (flag == 1)
	{
		temp++;
		i = ic / 4;
		while (--i >= 0)
		{
			arr[i] = temp % 10 + '0';
			temp /= 10;
		}
	}
	return (temp);
}

void	memory_alloc_2(char ***arr, int ic)
{
	int	i;

	*arr = (char **)malloc(sizeof(char *) * 100);
	i = -1;
	while (++i < 100)
		(*arr)[i] = (char *)malloc(sizeof(char) * ic / 4);
	i = -1;
	while (++i < ic / 4)
		(*arr)[99][i] = '0';
}

void	memory_free(char **arr)
{
	int	i;

	i = -1;
	while (++i < 100)
		free(arr[i]);
	free(arr);
}

void	print_error(int code)
{
	char	c;

	write(2, "Error", 5);
	c = code + '0';
	write(2, &c, 1);
	write(2, "\n", 1);
}
