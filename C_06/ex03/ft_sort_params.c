/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:02:06 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/04 11:43:15 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else
			i++;
	}
	if (s1[i] != 0 && s2[i] == 0)
		return (1);
	else if (s1[i] == 0 && s2[i] != 0)
		return (-1);
	else
		return (0);
}

void	print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != 0)
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	if (argc == 1)
		return (-1);
	i = -1;
	while (++i < (argc - 1) - 1)
	{
		j = 0;
		while (++j < (argc - 1) - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) == 1)
			{
				temp = argv[j + 1];
				argv[j + 1] = argv[j];
				argv[j] = temp;
			}
		}
	}
	print(argc, argv);
	return (0);
}
