/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:32:16 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/06 01:07:47 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*temp;

	if (src == NULL)
		return (NULL);
	len = 0;
	while (src[len] != 0)
		len++;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp != NULL)
	{
		i = -1;
		while (++i < len + 1)
			temp[i] = src[i];
	}
	return (temp);
}
