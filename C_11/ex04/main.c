/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:55:48 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/09 09:19:51 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_intcmp.c"
#include "ft_is_sort.c"

int	main(void)
{
	int	(*cmp)(int, int);
	int	tab1[30] = {};
	int	tab2[30] = {};
	int length = 0;
	int	i = -1;
	int	res;

	cmp = ft_intcmp;
	res = ft_is_sort(tab1, length, cmp);
	while (++i < length)
		printf("%d ", tab1[i]);
	printf("\n%d\n", res);

	res = ft_is_sort(tab2, length, cmp);
	i = -1;
	while (++i < length)
		printf("%d ", tab2[i]);
	printf("\n%d\n", res);
}
