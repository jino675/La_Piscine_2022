/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:24:06 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/10 18:39:32 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

int	is_operator(char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i] != 0)
		if (i >= 1)
			flag = -1;
	if (flag != -1)
	{
		if (str[0] == '+')
			return (0);
		else if (str[0] == '-')
			return (1);
		else if (str[0] == '*')
			return (2);
		else if (str[0] == '/')
			return (3);
		else if (str[0] == '%')
			return (4);
	}
	write(2, "0\n", 2);
	return (-42);
}

int	zero_check(int b, int idx)
{
	if (b == 0)
	{
		if (idx == 3)
		{
			write(2, "Stop : division by zero\n", 24);
			return (-42);
		}
		if (idx == 4)
		{
			write(2, "Stop : modulo by zero\n", 22);
			return (-42);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	(*f[5])(int, int);
	int	idx;
	int	a;
	int	b;
	int	res;

	if (argc != 4)
		return (-1);
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	idx = is_operator(argv[2]);
	if (idx == -42)
		return (-1);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (zero_check(b, idx) == -42)
		return (-1);
	res = f[idx](a, b);
	ft_putnbr(res);
	return (0);
}
