/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:44:22 by jiryu             #+#    #+#             */
/*   Updated: 2022/09/15 12:22:09 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_type
{
	int	x;
	int	y;
	int	val;
}	t_type;

int		main(int ac, char **av);
int		print_error_f(int fd, char *nbr, int flag);
int		print_error_r(int fd, int **line, int flag);
int		from_input(void);

int		init_print(char *fname, int *fd, char *buf);
int		print_map(char *fname, char *mark, t_type *p_max, int *rc_max);

void	from_files(char *fname);

int		first_line(int *fd, char *fname, char *mark, int *r_max);
int		calc_row(int *fd, char *fname, int *len, int *r_max);
int		calc_column(int *len, char *fname, char *buf);

int		rest_line(int fd, char *mark, t_type *p_max, int *rc_max);
int		init_rest(int **line, t_type *max, int c_max);
int		calc_map(char *buf, char *mark, int **line, int i);
void	max_update(t_type *max, int *idx, int val);
void	ptr_swap(int **line);

#endif
