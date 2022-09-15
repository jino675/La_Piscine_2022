/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 08:31:08 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 23:54:20 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h"

int	print_error(int flag)
{
	if (flag == -42)
		write(1, "Error\n", 6);
	if (flag == -99)
		write(1, "Dict Error\n", 11);
	return (-1);
}

int	sub_extract_num(const char *str, int *start, int *i, int *size)
{
	*i = 0;
	*start = 0;
	while (str[*i] != '\0' && ((str[*i] >= 9
				&& str[*i] <= 13) || str[*i] == ' '))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	while (str[*i] != '\0' && str[*i] == '0')
		(*i)++;
	if ((*i > 0 && str[*i - 1] == '0') && str[*i] == '\0')
	{
		*size = 1;
		return (0);
	}
	if (str[*i] > '0' && str[*i] <= '9')
	{
		*start = *i;
		(*i)++;
	}
	else
		return (-42);
	while (str[*i] != '\0' && (str[*i] >= '0' && str[*i] <= '9'))
		(*i)++;
	*size = *i - *start;
	return (0);
}

char	*ft_extract_num(const char *str)
{
	int		i;
	int		start;
	int		size;
	char	*res;

	if (sub_extract_num(str, &start, &i, &size) == -42)
		return (NULL);		
	if (str[i] == '.')
		return (NULL);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	ft_strncpy(res, str + start, size);
	res[size] = '\0';
	return (res);
}

char	*set_filename(const char *temp)
{
	char	*res;
	int		len;

	len = ft_strlen(PATH) + ft_strlen(temp);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strcat(res, PATH);
	ft_strcat(res, temp);
	return (res);
}

int	execute_convert(char *nbr, char *filename, const char *temp)
{
	int	flag;
	int	mode;

	mode = ft_strstr(temp, "_ko_");
	if (mode == 0)
		flag = convert_print(nbr, filename, ft_strlen(nbr), -1);
	else
		flag = convert_print_ko(nbr, filename, ft_strlen(nbr), -1);
	free(filename);
	free(nbr);
	return (flag);
}
