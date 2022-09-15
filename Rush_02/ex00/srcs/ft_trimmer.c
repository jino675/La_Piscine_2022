/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimmer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 05:04:33 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 18:10:00 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h" 

char	*ft_trimmer(const char *str, int len)
{
	int		start;
	int		end;
	int		size;
	int		i;
	char	*res;

	start = 0;
	end = len - 1;
	while (str[start] == ' ')
		start++;
	while (str[end] == ' ')
		end--;
	size = end - start + 1;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		res[i] = str[start + i];
	res[i] = '\0';
	return (res);
}
