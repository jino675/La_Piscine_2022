/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:24:11 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/01 06:28:52 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && n > 0)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else
		{
			i++;
			n--;
		}
	}
	if (n == 0)
		return (0);
	else if (s1[i] != 0 && s2[i] == 0)
		return (1);
	else if (s1[i] == 0 && s2[i] != 0)
		return (-1);
	else
		return (0);
}
