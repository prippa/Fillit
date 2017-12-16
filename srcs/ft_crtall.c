/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:03:21 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/14 18:03:21 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	ft_delextr(char *res, char *s, int i, int y)
{
	int			x;

	x = y;
	while (i < 20)
	{
		if (s[x] != '\n' && (s[x] != '.' || s[x + 5] != '.'
			|| s[x + 10] != '.' || s[x + 15] != '.'))
		{
			*res++ = s[i + x];
			++x;
		}
		else if (s[i + 5] != '\n' && s[i + 5] && (s[i + 5] == '#' ||
			s[i + 6] == '#' || s[i + 7] == '#' || s[i + 8] == '#'))
		{
			x = y;
			i += 5;
			*res++ = '\n';
		}
		else
			break ;
	}
	*res = '\0';
}

static	char	*ft_dotout(char *res, char *s, int i, int j)
{
	int			x;
	int			z;

	z = 0;
	x = 0;
	while (i < 20)
	{
		if (s[i] == '.' && s[i + 1] == '.' &&
			s[i + 2] == '.' && s[i + 3] == '.')
			i += 5;
		else if (s[j] == '.' && s[j + 5] == '.' &&
			s[j + 10] == '.' && s[j + 15] == '.')
			++j;
		else
			break ;
	}
	ft_delextr(res, s, i, j);
	return (res);
}

static	char	*ft_crtnew(char *s, int i, int j, int x)
{
	char		*res;
	int			y;

	y = 0;
	while (i < 20)
	{
		if (s[i] == '.' && s[i + 1] == '.' &&
			s[i + 2] == '.' && s[i + 3] == '.')
			++x;
		if (s[j] == '.' && s[j + 5] == '.' &&
			s[j + 10] == '.' && s[j + 15] == '.')
			++y;
		i += 5;
		++j;
	}
	if (!(res = (char *)malloc(16 - (x * 4 + y * (4 - x)) + 4 - x)))
		return (0);
	ft_dotout(res, s, 0, 0);
	return (res);
}

void			ft_crtall(char *s, char i, int j, int x)
{
	char		**termins;
	int			*coord;
	int			y;

	y = 0;
	if ((termins = (char **)malloc(sizeof(char *) * (j + 1))) &&
		(coord = (int *)malloc(sizeof(int) * (j + 1))))
	{
		termins[j] = NULL;
		while (x < j)
		{
			termins[x] = ft_replchar(ft_crtnew(s + y, 0, 0, 0), '#', i++);
			y += 21;
			x++;
		}
		while (x)
			coord[x--] = 0;
		coord[x] = 0;
		ft_logic(termins, &coord[1], j, 0);
	}
}
