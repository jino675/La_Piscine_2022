/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:24:46 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/06 17:45:25 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != 0)
		dest[i] = src[i];
	dest[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	res = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = (char *)malloc(sizeof(char) * (res[i].size + 1));
		if (res[i].copy == NULL)
			return (NULL);
		ft_strcpy(res[i].copy, res[i].str);
	}
	res[i].size = 0;
	res[i].str = NULL;
	res[i].copy = NULL;
	return (res);
}
