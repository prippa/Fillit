/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validterm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:36:59 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/15 12:37:00 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	*ft_valadd(char *s)
{
	int		i;
	int		j;
	int		r;

	i = 0;
	j = 0;
	r = 0;
	while (s[i])
	{
		if (i != 0 && (i - j) % 20 == 0 && ++j)
			if (s[i++] != '\n' || r % 4)
				return (0);
		if ((!((i + 1 - j) % 5) && s[i] == '\n') ||
			((i + 1 - j) % 5 && (s[i] == '#' || s[i] == '.')))
		{
			if (s[i] == '#')
				r++;
			i++;
		}
		else
			return (0);
	}
	if (!(r % 4) && !((i - j) % 20) && j < 26)
		return (s);
	return (0);
}

char			*ft_validterm(char *s, int i, int j, int x)
{
	if (!ft_valadd(s) || ft_strlen(s) < 20)
		return (0);
	while (s[i])
	{
		if (s[i] == '#')
		{
			if ((i + 1 - j * 21 < 16) && s[i + 5] == '#')
				x++;
			if ((i + 1 - j * 21 > 5) && s[i - 5] == '#')
				x++;
			if (s[i + 1] == '#')
				x++;
			if (s[i - 1] == '#')
				x++;
		}
		i++;
		if (!((i + 1) % 21))
		{
			if (x < 6 || x > 8)
				return (0);
			x = 0;
			j++;
		}
	}
	return (s);
}
