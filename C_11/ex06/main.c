/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:09:18 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/08 21:11:59 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_string_tab(char **tab);

int	main(int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < argc)
		printf("%s\n", argv[i]);
	printf("\n\n");
	ft_sort_string_tab(argv);
	i = -1;
	while (++i < argc)
		printf("%s\n", argv[i]);
	return (0);
}
