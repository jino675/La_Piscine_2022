/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:02:40 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 23:37:22 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h"

char	*read_stdin(void)
{
	char	buf[1024];
	char	*res;
	int		size;

	size = -1;
	while (read(1, &buf[++size], 1) > 0)
		if (buf[size] == '\n')
			break;
	res = (char *)malloc(sizeof(char) * (size + 1));
	ft_strncpy(res, buf, size);
	res[size] = '\0';
	return (res);
}

int	main(int ac, char **av)
{
	const char	*temp;
	char		*t_nbr;
	char		*filename;
	char		*nbr;
	int			flag;

	if (ac < 1 || ac > 3)
		return (print_error(-42));
	if (ac == 2)
		temp = FILENAME;
	if (ac == 3)
		temp = av[1];
	filename = set_filename(temp);
	if (filename == NULL)
		return (print_error(-42));
	if (ac == 1)
	{
		t_nbr = read_stdin();
		nbr = ft_extract_num(t_nbr);
		free(t_nbr);
	}
	else
		nbr = ft_extract_num(av[ac - 1]);
	if (nbr == NULL)
	{
		free(filename);
		return (print_error(-42));
	}
	flag = execute_convert(nbr, filename, temp);
	if (flag == -42 || flag == -99)
		return (print_error(flag));
	return (0);
}
