/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:16:59 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 22:13:08 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	print_error(int code);

void	set_input(char *str, char **input, int ic, int i)
{
	int	p;

	p = i / 2;
	if (p < ic / 2)
	{
		if (p < ic * 1 / 4)
			input[p][0] = str[i];
		else
			input[p - ic / 4][1] = str[i];
	}
	else
	{
		if (p < ic * 3 / 4)
			input[p - ic / 4][0] = str[i];
		else
			input[p - ic / 2][1] = str[i];
	}
}

int	error_check_1(char *str, int *ic)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
	{
		if (i % 2 == 0)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
			{
				print_error(1);
				return (1);
			}
			else
				(*ic)++;
		}
		if (i % 2 == 1)
		{
			if (!(str[i] == ' '))
			{
				print_error(2);
				return (1);
			}
		}
	}
	return (0);
}

int	error_check_2(char *str, int ic, char **input)
{
	int	i;

	if (ic % 4 != 0)
	{
		print_error(3);
		return (1);
	}	
	i = -1;
	while (str[++i] != 0)
	{
		if (i % 2 == 0)
		{
			if (str[i] > ic / 4 + '0' || str[i] == '0')
			{
				print_error(4);
				return (1);
			}
			else
				set_input(str, input, ic, i);
		}
	}
	return (0);
}

int	ft_memory_alloc(int ic, char ***input, char ***grid)
{
	int	i;

	*input = (char **)malloc(sizeof(char *) * (ic / 2));
	i = -1;
	while (++i < ic / 2)
		(*input)[i] = (char *)malloc(sizeof(char) * 2);
	*grid = (char **)malloc(sizeof(char *) * ic / 4);
	i = -1;
	while (++i < ic / 4)
		(*grid)[i] = (char *)malloc(sizeof(char) * ic / 4);
	if (input == NULL || grid == NULL)
	{
		print_error(5);
		return (1);
	}
	return (0);
}

void	ft_memory_free(int ic, char ***input, char ***grid)
{
	int	i;

	i = -1;
	while (++i < ic / 4)
		free((*grid)[i]);
	free(*grid);
	i = -1;
	while (++i < ic / 2)
		free((*input)[i]);
	free(*input);
}
