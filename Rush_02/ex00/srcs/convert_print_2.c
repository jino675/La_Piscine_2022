/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_print_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:15:45 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 13:58:49 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h"

int	print_hundreds(const char *str, int idx, const char *filename)
{
	char	temp[4];
	char	*wtn;
	int		flag;

	temp[0] = '1';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '\0';
	flag = print_units(str, idx, filename);
	if (flag == -99)
		return (flag);
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	write(1, " ", 1);
	free(wtn);
	return (0);
}

int	print_tens(const char *str, int idx, const char *filename)
{
	char	temp[3];
	char	*wtn;

	temp[0] = str[idx];
	temp[1] = '0';
	temp[2] = '\0';
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	write(1, " ", 1);
	free(wtn);
	return (0);
}

int	print_teen(const char *str, int idx, const char *filename)
{
	char	temp[3];
	char	*wtn;

	temp[0] = str[idx];
	temp[1] = str[idx + 1];
	temp[2] = '\0';
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	write(1, " ", 1);
	free(wtn);
	return (0);
}

int	print_units(const char *str, int idx, const char *filename)
{
	char	temp[2];
	char	*wtn;

	temp[0] = str[idx];
	temp[1] = '\0';
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	write(1, " ", 1);
	free(wtn);
	return (0);
}

int	print_zero(const char *filename)
{
	char	temp[2];
	char	*wtn;

	temp[0] = '0';
	temp[1] = '\0';
	wtn = ft_file_sweeper(temp, filename);
	if (wtn == NULL)
		return (-99);
	write(1, wtn, ft_strlen(wtn));
	write(1, " ", 1);
	free(wtn);
	return (0);
}
