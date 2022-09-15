/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_print_1_ko.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:55:33 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 20:20:40 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h"

int	sub_print_nbr_ko(const char *str, const char *filename, int start, int len)
{
	int	flag;

	if (len >= 1 && str[start + len - 1] != '0')
	{
		flag = print_units_ko(str, start + len - 1, filename);
		if (flag == -99)
			return (flag);
	}
	if (len == 1 && str[start + len - 1] == '0')
	{
		flag = print_zero_ko(filename);
		if (flag == -99)
			return (flag);
	}
	return (0);
}

int	print_nbr_ko(const char *str, const char *filename, int start, int len)
{
	int	flag;

	if (len == 4 && str[start + len - 4] != '0')
	{
		flag = print_thousands_ko(str, start + len - 4, filename);
		if (flag == -99)
			return (flag);
	}
	if (len >= 3 && str[start + len - 3] != '0')
	{
		flag = print_hundreds_ko(str, start + len - 3, filename);
		if (flag == -99)
			return (flag);
	}
	if (len >= 2 && str[start + len - 2] != '0')
	{
		flag = print_tens_ko(str, start + len - 2, filename);
		if (flag == -99)
			return (flag);
	}
	flag = sub_print_nbr_ko(str, filename, start, len);
	if (flag == -99)
		return (flag);
	return (0);
}

int	print_mid_ko(int lv, const char *filename)
{
	int		i;
	char	*temp;
	char	*wtn;

	temp = (char *)malloc(sizeof(char) * (1 + (4 * lv) + 1));
	if (temp == NULL)
		return (-42);
	temp[0] = '1';
	i = 0;
	while (++i <= 4 * lv)
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

int	sub_convert_print_ko(const char *str, const char *filename, int len, int lv)
{
	int	flag;
	int	start;

	start = len - 4;
	flag = convert_print_ko(str, filename, len - 4, lv);
	if (flag == -42 || flag == -99)
		return (flag);
	if (str[start] != '0' || str[start + 1] != '0'
		||str[start + 2] != '0' || str[start + 3] != '0')
		write(1, " ", 1);
	return (0);
}

int	convert_print_ko(const char *str, const char *filename, int len, int lv)
{
	int	start;
	int	flag;

	lv++;
	start = (len - 4) * (len / 5 != 0);
	if (len > 4)
	{
		flag = sub_convert_print_ko(str, filename, len, lv);
		if (flag == -42 || flag == -99)
			return (flag);
		len = 4;
	}
	if (print_nbr_ko(str, filename, start, len) == -99)
		return (flag);
	if (lv > 0 && (str[start] != '0' || str[start + 1] != '0'
			|| str[start + 2] != '0' || str[start + 3] != '0'))
	{
		flag = print_mid_ko(lv, filename);
		if (flag == -42 || flag == -99)
			return (flag);
	}
	if (lv == 0)
		write(1, "\b\n", 2);
	return (0);
}
