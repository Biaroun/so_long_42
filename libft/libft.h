/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:46:16 by biaroun            #+#    #+#             */
/*   Updated: 2022/05/27 12:46:17 by biaroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putendl_fd(char *s, int fd);
char	*ft_get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
