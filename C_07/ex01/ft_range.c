/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:43:47 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/05 22:14:36 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*temp;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	temp = (int *)malloc(sizeof(int) * size);
	if (temp != NULL)
	{
		i = -1;
		while (++i < size)
			temp[i] = min + i;
	}
	return (temp);
}
