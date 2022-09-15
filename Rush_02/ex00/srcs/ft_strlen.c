/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 08:27:13 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 08:27:53 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h"

int	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str[size] != 0)
		size++;
	return (size);
}
