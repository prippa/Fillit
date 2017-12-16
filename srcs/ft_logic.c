/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:11:24 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/16 19:11:24 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		*ft_checkcord(char **terms, int *cr, int j)
{
	int			i;
	int			x;

	if (!j)
		return (&cr[j]);
	i = j;
	x = 0;
	while (i--)
	{
		while (terms[j][x])
		{
			if ((terms[j][x] == '.' && terms[i][x] == '.') || (terms[j][x] !=
				'.' && terms[i][x] != '.' && terms[j][x] != '\n' && terms[i][x]
				!= '\n') || (terms[j][x] == '\n' && terms[i][x] == '\n'))
				++x;
			else
				break ;
		}
		if (!terms[j][x])
			if (cr[j] < cr[i])
				cr[j] = cr[i] + 1;
		x = 0;
	}
	return (&cr[j]);
}

static	void	ft_setcoord(int *coord, int s, int c)
{
	int			j;

	j = 1;
	if (*coord > s * 3)
	{
		while (c-- && ++j)
			if (*coord - s * 3 < coord[j])
				coord[j] = *coord - s * 3 + 1;
	}
	else if (*coord > s * 2)
	{
		while (c-- && ++j)
			if (*coord - s * 2 < coord[j])
				coord[j] = *coord - s * 2;
	}
	else if (*coord > s)
	{
		while (c-- && ++j)
			if (*coord - s < coord[j])
				coord[j] = *coord - s;
	}
	else
		while (c-- && ++j)
			if (*coord < coord[j])
				coord[j] = *coord;
}

static	void	ft_rmterm(char *pole, const char *term, int j, int s)
{
	int			i;
	int			x;

	i = 0;
	x = j;
	while (term[i])
	{
		if (term[i] == '\n')
		{
			j += s;
			x = j;
		}
		else
		{
			if (term[i] != '.')
				pole[x] = '.';
			x++;
		}
		i++;
	}
}

void			ft_logic(char **terms, int *coord, int i, int j)
{
	char		*pole;
	int			z;

	z = ft_sqrtrd(i * 4, 1);
	pole = ft_creatsqr(z);
	while (terms[j])
	{
		if (ft_checkwrite(pole, terms[j], ft_checkcord(terms, coord, j), z + 1))
			++j;
		else if (j == 0)
		{
			coord[j] = 0;
			pole = ft_creatsqr(++z);
			ft_setcoord((int *)&coord[j - 1], z + 1, i - 1);
		}
		else
		{
			j--;
			ft_rmterm(pole, terms[j], coord[j], z + 1);
			coord[j] += 1;
			ft_setcoord((int *)&coord[j - 1], z + 1, i - j - 1);
		}
	}
	ft_putendl(pole);
}
