/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:51:20 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 10:55:27 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 1)
		return (-1);
	i = -1;
	while (argv[0][++i] != 0)
		write(1, &argv[0][i], 1);
	write(1, "\n", 1);
	return (0);
}
