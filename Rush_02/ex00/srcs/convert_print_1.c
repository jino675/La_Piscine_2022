/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_print_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:55:33 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 20:19:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h"

int	sub_print_nbr(const char *str, const char *filename, int start, int len)
{
	int	flag;

	if (len >= 2 && str[start + len - 2] == '1')
	{
		flag = print_teen(str, start + len - 2, filename);
		return (flag);
	}
	if (len >= 1 && str[start + len - 1] != '0')
	{
		flag = print_units(str, start + len - 1, filename);
		if (flag == -99)
			return (flag);
	}
	if (len == 1 && str[start + len - 1] == '0')
	{
		flag = print_zero(filename);
		if (flag == -99)
			return (flag);
	}
	return (0);
}

int	print_nbr(const char *str, const char *filename, int start, int len)
{
	int	flag;

	if (len == 3 && str[start + len - 3] != '0')
	{
		flag = print_hundreds(str, start + len - 3, filename);
		if (flag == -99)
			return (flag);
	}
	if (len >= 2 && str[start + len - 2] > '1')
	{
		flag = print_tens(str, start + len - 2, filename);
		if (flag == -99)
			return (flag);
		if (str[start + len - 1] != '0')
			write(1, "\b-", 2);
	}
	flag = sub_print_nbr(str, filename, start, len);
	if (flag == -99)
		return (flag);
	return (0);
}

int	print_mid(int lv, const char *filename)
{
	int		i;
	char	*temp;
	char	*wtn;

	temp = (char *)malloc(sizeof(char) * (1 + (3 * lv) + 1));
	if (temp == NULL)
		return (-42);
	temp[0] = '1';
	i = 0;
	while (++i <= 3 * lv)
		temp[i] = '0';
	temp[i] = '\0';
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
	{
		free(temp);
		return (-99);
	}
	write(1, wtn, ft_strlen(wtn));
	free(temp);
	free(wtn);
	return (0);
}

int	sub_convert_print(const char *str, const char *filename, int len, int lv)
{
	int	flag;
	int	start;
	int	o_len;
	int	i;

	start = len - 3;
	flag = convert_print(str, filename, len - 3, lv);
	if (flag == -42 || flag == -99)
		return (flag);
	if (str[start] != '0' || str[start + 1] != '0' || str[start + 2] != '0')
		write(1, ", ", 2);
	o_len = len + 3 * lv;
	i = 0;
	while (str[o_len - 1 - i] == '0')
		i++;
	if (lv == i / 3)
		write(1, "and ", 4);
	return (0);
}

int	convert_print(const char *str, const char *filename, int len, int lv)
{
	int	start;
	int	flag;

	lv++;
	start = (len - 3) * (len / 4 != 0);
	if (len > 3)
	{
		flag = sub_convert_print(str, filename, len, lv);
		if (flag == -42 || flag == -99)
			return (flag);
		len = 3;
	}
	if (print_nbr(str, filename, start, len) == -99)
		return (flag);
	if (lv > 0 && (str[start] != '0' || str[start + 1] != '0'
			|| str[start + 2] != '0'))
	{
		flag = print_mid(lv, filename);
		if (flag == -42 || flag == -99)
			return (flag);
	}
	if (lv == 0)
		write(1, "\b\n", 2);
	return (0);
}
