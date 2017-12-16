/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:56:58 by prippa            #+#    #+#             */
/*   Updated: 2017/11/13 18:57:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

int		ft_checkwrite(char *pole, const char *term, int *cr, int s);
char	*ft_creatsqr(int size);
void	ft_crtall(char *s, char i, int j, int x);
void	ft_logic(char **terms, int *coord, int i, int j);
char	*ft_validterm(char *s, int i, int j, int x);

#endif
