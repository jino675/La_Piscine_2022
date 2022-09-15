/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:17:00 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/09 09:11:00 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	flag = 0;
	if (length < 0)
		return (-1);
	if (length >= 0 && length <= 2)
		return (1);
	i = 0;
	while (i < length - 2 && f(tab[i], tab[i + 1]) == 0)
		i++;
	if (f(tab[i], tab[i + 1]) > 0)
		flag = 1;
	else if (f(tab[i], tab[i + 1]) < 0)
		flag = -1;
	else
		return (1);
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) * flag < 0)
			return (0);
	return (1);
}
