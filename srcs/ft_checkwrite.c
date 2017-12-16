/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwrite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:56:47 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/18 18:56:47 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

static void	ft_writeterm(char *pole, const char *term, int j, int s)
{
	int		i;
	int		x;

	i = 0;
	x = j;
	while (term[i])
	{
		if (term[i] == '\n')
		{
			j += s;
			x = j - 1;
		}
		else if (term[i] != '.')
			pole[x] = term[i];
		x++;
		i++;
	}
}

int			ft_checkwrite(char *pole, const char *term, int *cr, int s)
{
	int		i;
	int		x;
	int		y;
	int		z;

	y = 1;
	i = 0;
	x = *cr;
	z = *cr;
	while (term[i])
	{
		if (term[i] == '\n')
			x = *cr + s * y++ - 1;
		else if (term[i] != '.' && pole[x] != '.' && (y = 1))
		{
			x = (*cr += 1) - 1;
			i = -1;
		}
		if (x >= ((s * s) - s) && (*cr = z) != -2)
			return (0);
		x++;
		i++;
	}
	ft_writeterm(pole, term, *cr, s);
	return (1);
}
