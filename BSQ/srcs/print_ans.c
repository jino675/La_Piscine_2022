/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:01:27 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 12:29:31 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	init_print(char *fname, int *fd, char *buf)
{
	*fd = open(fname, O_RDONLY);
	if (*fd == -1)
		return (print_error_r(0, NULL, 0));
	while (1)
	{
		if (read(*fd, buf, 1) <= 0)
			return (print_error_r(*fd, NULL, 99));
		if (buf[0] == '\n')
			break ;
	}
	return (0);
}

int	print_map(char *fname, char *mark, t_type *p_max, int *rc_max)
{
	int		i;
	int		j;
	int		fd;
	char	buf[1];

	if (init_print(fname, &fd, buf) == -1)
		return (-1);
	i = -1;
	while (++i < rc_max[0])
	{
		j = -1;
		while (++j < rc_max[1] + 1)
		{
			if (read(fd, buf, 1) <= 0)
				return (print_error_r(fd, NULL, 99));
			if (i > (p_max->x - p_max->val) && i <= p_max->x
				&& j > (p_max->y - p_max->val) && j <= p_max->y)
				write(1, &mark[2], 1);
			else
				write(1, buf, 1);
		}
	}
	close(fd);
	return (0);
}
