/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:46:14 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/28 10:59:09 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	iter;
	int	temp;
	int	front;
	int	end;

	front = 0;
	iter = size / 2;
	while (iter > 0)
	{
		end = size - 1 - front;
		temp = tab[front];
		tab[front] = tab[end];
		tab[end] = temp;
		front++;
		iter--;
	}
}
