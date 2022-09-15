/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:09:04 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/11 20:35:51 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_verify(const char *dest_ptr, const char *to_find, int *flag)
{
	int	i;

	i = 1;
	while (dest_ptr[i] == to_find[i] && to_find[i] != 0)
		i++;
	if (to_find[i] != 0)
		*flag = 0;
	else
		*flag = 1;
}

int	ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;
	int	flag;

	if (to_find[0] == 0)
		return (0);
	i = 0;
	j = 0;
	flag = 0;
	while (str[i] != 0)
	{
		if (str[i] == to_find[j])
		{
			ft_verify(&str[i], to_find, &flag);
			if (flag == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
