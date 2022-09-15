/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_sweeper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:57:54 by haeem             #+#    #+#             */
/*   Updated: 2022/09/11 22:48:34 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rushrushrush.h"

int	sub_sub_sweeper(char *buf, char **temp, int fd)
{
	int	i;

	i = -1;
	while (1)
	{
		if (read(fd, &buf[++i], 1) <= 0)
		{
			free(buf);
			return (-42);
		}
		if (buf[i] == ':')
			break ;
	}
	buf[i] = '\0';
	*temp = ft_trimmer(buf, i);
	if (*temp == NULL)
	{
		free(buf);
		return (-42);
	}
	return (0);
}

int	sub_sub_sub_sweeper(char *buf, char *temp, char **key, int fd)
{
	int	i;
	int	flag;

	i = -1;
	while (1)
	{
		flag = read(fd, &buf[++i], 1);
		if (flag < 0)
		{
			free(buf);
			free(temp);
			return (-42);
		}
		if (buf[i] == '\n' || flag == 0)
			break ;
	}
	buf[i] = '\0';
	*key = ft_trimmer(buf, i);
	if (*key == NULL)
	{
		free(buf);
		free(temp);
		return (-42);
	}
	return (0);
}

char	*sub_sweeper(const char *target, char *buf, int fd)
{
	char	*temp;
	char	*key;

	while (1)
	{
		if (sub_sub_sweeper(buf, &temp, fd) == -42)
			return (NULL);
		if (sub_sub_sub_sweeper(buf, temp, &key, fd) == -42)
			return (NULL);
		if (ft_strcmp(temp, target) == 0)
		{
			free(buf);
			free(temp);
			return (key);
		}
		else
		{
			free(temp);
			free(key);
		}
	}
}

char	*ft_file_sweeper(const char *target, const char *filename)
{
	char	*buf;
	char	*key;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
		close(fd);
		return (NULL);
	}
	key = sub_sweeper(target, buf, fd);
	close(fd);
	return (key);
}
