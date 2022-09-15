/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:55:15 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/31 23:36:41 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (n > 0)
	{
		if (src[i] != 0 && flag == 0)
			dest[i] = src[i];
		else
		{
			dest[i] = 0;
			flag = 1;
		}
		i++;
		n--;
	}
	return (dest);
}
