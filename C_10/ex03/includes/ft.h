/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:53:35 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 02:16:27 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>

void		print_hexdump(int ac, char **av, char *buf, int flag);
void		print_input(char **av, char *buf, int flag);

int			print_line(char *buf, int size, int iter, int flag);

void		print_size(int size, int lv);
void		print_hex(char *buf, int iter, int flag);
void		print_char(char *buf, int iter);

int			ft_strlen(char *str);
int			ft_strcmp(char *str1, char *str2);
int			error_check(char *pname, char *fname, int fd, int res);

#endif
