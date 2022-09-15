/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:56:08 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 22:09:44 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int		set_grid(char **grid, char **input, int ic, int s_lv);
int		error_check_1(char *str, int *ic);
int		error_check_2(char *str, int ic, char **input);
int		ft_memory_alloc(int ic, char ***input, char ***grid);
void	ft_memory_free(int ic, char ***input, char ***grid);
void	print_error(int code);

int	main(int argc, char **argv)
{
	int		ic;
	char	**input;
	char	**grid;

	if (argc != 2)
	{
		print_error(0);
		return (-1);
	}
	if (error_check_1(argv[1], &ic) == 1)
		return (-1);
	if (ft_memory_alloc(ic, &input, &grid) == 1)
		return (-1);
	if (error_check_2(argv[1], ic, input) == 1)
		return (-1);
	set_grid(grid, input, ic, -1);
	ft_memory_free(ic, &input, &grid);
	return (0);
}
