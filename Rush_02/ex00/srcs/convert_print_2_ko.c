/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_print_2_ko.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:15:45 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 14:00:55 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h"

int	print_thousands_ko(const char *str, int idx, const char *filename)
{
	char	temp[5];
	char	*wtn;
	int		flag;

	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '0';
	temp[4] = '\0';
	if (str[idx] != '1')
	{
		flag = print_units_ko(str, idx, filename);
		if (flag == -99)
			return (flag);
	}
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	free(wtn);
	return (0);
}

int	print_hundreds_ko(const char *str, int idx, const char *filename)
{
	char	temp[4];
	char	*wtn;
	int		flag;

	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '\0';
	if (str[idx] != '1')
	{
		flag = print_units_ko(str, idx, filename);
		if (flag == -99)
			return (flag);
	}
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	free(wtn);
	return (0);
}

int	print_tens_ko(const char *str, int idx, const char *filename)
{
	char	temp[3];
	char	*wtn;
	int		flag;

	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '\0';
	if (str[idx] != '1')
	{
		flag = print_units_ko(str, idx, filename);
		if (flag == -99)
			return (flag);
	}
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	free(wtn);
	return (0);
}

int	print_units_ko(const char *str, int idx, const char *filename)
{
	char	temp[2];
	char	*wtn;

	temp[0] = str[idx];
	temp[1] = '\0';
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	free(wtn);
	return (0);
}

int	print_zero_ko(const char *filename)
{
	char	temp[2];
	char	*wtn;

	temp[0] = '0';
	temp[1] = '\0';
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	free(wtn);
	return (0);
}
