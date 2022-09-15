/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:56:25 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 10:58:37 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		return (-1);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != 0)
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
	}
	return (0);
}
