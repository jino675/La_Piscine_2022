/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushrushrush.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 02:16:29 by haeem             #+#    #+#             */
/*   Updated: 2022/09/11 23:53:47 by jiryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSHRUSHRUSH_H
# define RUSHRUSHRUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define FILENAME "numbers.dict"
# define PATH "dictionaries/"

/* main.c */
int		execute_convert(char *nbr, char *filename, const char *temp);
char	*set_filename(const char *temp);
char	*ft_extract_num(const char *str);
int		sub_extract_num(const char *str, int *start, int *i, int *size);
int		print_error(int flag);

/* convert_print_1.c */
int		convert_print(const char *str, const char *filename, int len, int lv);
int		sub_convert_print(const char *str,
			const char *filename, int len, int lv);
int		print_mid(int lv, const char *filename);
int		print_nbr(const char *str, const char *filename, int start, int len);
int		sub_print_nbr(const char *str, const char *filename,
			int start, int len);

/* convert_print_2.c */
int		print_zero(const char *filename);
int		print_units(const char *str, int idx, const char *filename);
int		print_teen(const char *str, int idx, const char *filename);
int		print_tens(const char *str, int idx, const char *filename);
int		print_hundreds(const char *str, int idx, const char *filename);

/* convert_print_1_ko.c */
int		convert_print_ko(const char *str,
			const char *filename, int len, int lv);
int		sub_convert_print_ko(const char *str,
			const char *filename, int len, int lv);
int		print_mid_ko(int lv, const char *filename);
int		print_nbr_ko(const char *str, const char *filename,
			int start, int len);
int		sub_print_nbr_ko(const char *str, const char *filename,
			int start, int len);

/* convert_print_2_ko.c */
int		print_zero_ko(const char *filename);
int		print_units_ko(const char *str, int idx, const char *filename);
int		print_tens_ko(const char *str, int idx, const char *filename);
int		print_hundreds_ko(const char *str, int idx, const char *filename);
int		print_thousands_ko(const char *str, int idx, const char *filename);

/* ft_file_sweeper.c */
char	*ft_file_sweeper(const char *target, const char *filename);
char	*sub_sweeper(const char *target, char *buf, int fd);
int		sub_sub_sweeper(char *buf, char **temp, int fd);
int		sub_sub_sub_sweeper(char *buf, char *temp, char **key, int fd);

/* etc */
int		ft_strstr(const char *dest, const char *src);
int		ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcat(char *dest, const char *src);
char	*ft_trimmer(const char *str, int len);

#endif
