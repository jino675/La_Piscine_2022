/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:14:08 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/09 09:06:05 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int	i;
	int	(*cmp)(char *, char *);

	cmp = ft_strcmp;
	i = -1;
	while (++i < argc)
		printf("%s\n", argv[i]);
	printf("\n\n");
	ft_advanced_sort_string_tab(argv, cmp);
	i = -1;
	while (++i < argc)
		printf("%s\n", argv[i]);
	return (0);
}
