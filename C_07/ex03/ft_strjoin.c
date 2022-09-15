/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:52:13 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/05 20:27:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	sub_join(char *arr, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != 0)
			arr[++k] = strs[i][j];
		if (i != size - 1)
		{
			j = -1;
			while (sep[++j] != 0)
				arr[++k] = sep[j];
		}
	}
	arr[++k] = '\0';
}

int	arr_size(char **strs, int size, int sep_size)
{
	int	res;
	int	i;
	int	j;

	res = 1;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != 0)
			res++;
		if (i != size - 1)
			res += sep_size;
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sep_size;
	char	*arr;

	sep_size = 0;
	while (sep != NULL && sep[sep_size] != 0)
		sep_size++;
	arr = (char *)malloc(sizeof(char) * arr_size(strs, size, sep_size));
	sub_join(arr, strs, sep, size);
	return (arr);
}
