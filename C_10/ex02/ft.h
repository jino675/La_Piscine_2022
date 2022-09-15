/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:53:35 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/13 09:05:05 by jiryu            ###   ########.fr       */
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

int			pre_process_file(char *pname, char *fname, long long *size);
int			pro_process_file(char *pname, char *fname, long long size,
				long long num);
void		print_file(int ac, char **av, long long num);
int			process_input(char *buf, char *pname, long long num);
int			print_input(char *pname, long long num);
long long	ft_atoi(char *str);
int			ft_strlen(char *str);
void		print_filename(char *fname, int flag);
int			error_check(char *pname, char *fname, int fd, int res);
int			error_check_2(char *pname, char *fname, long long num, char *buf);

#endif
