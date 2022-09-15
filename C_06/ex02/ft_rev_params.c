/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:59:44 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 11:01:25 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		return (-1);
	i = argc;
	while (--i > 0)
	{
		j = -1;
		while (argv[i][++j] != 0)
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
	}
	return (0);
}
