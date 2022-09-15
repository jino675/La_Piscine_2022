/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:32:05 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/06 03:48:23 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_seperator(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i] != 0)
		if (c == charset[i])
			return (1);
	return (0);
}

void	word_count(char *str, char *charset, int *count)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i] != 0)
	{
		if (is_seperator(str[i], charset) == 0)
		{
			if (flag == 0)
			{
				(*count)++;
				flag = 1;
			}
		}
		else
			if (flag == 1)
				flag = 0;
	}
}

int	sub_copy(char **res, char *str, int cur, int end)
{
	int	i;
	int	len;

	len = end - cur;
	*res = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (cur < end)
	{
		(*res)[i] = str[cur];
		i++;
		cur++;
	}
	(*res)[i] = '\0';
	return (0);
}

void	sub_split(char **res, char *str, char *charset, int *idx)
{
	int	i;
	int	flag;
	int	start;

	i = -1;
	flag = 0;
	while (str[++i] != 0)
	{
		if (is_seperator(str[i], charset) == 0)
		{
			if (flag == 0)
			{
				start = i;
				flag = 1;
			}
		}
		else
			if (flag == 1)
				flag = sub_copy(&res[++(*idx)], str, start, i);
	}
	if (flag == 1)
		sub_copy(&res[++(*idx)], str, start, i);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		idx;
	int		count;

	count = 0;
	word_count(str, charset, &count);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	idx = -1;
	sub_split(res, str, charset, &idx);
	res[++idx] = NULL;
	return (res);
}
