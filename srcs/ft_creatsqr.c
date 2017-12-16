/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatsqr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:23:21 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/17 12:23:22 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_creatsqr(int size)
{
	char	*arr;
	int		i;

	arr = (char*)malloc(sizeof(char) * ((size + 1) * size));
	i = 0;
	while (i < ((size + 1) * size) - 1)
	{
		if (((i + 1) % (size + 1)) == 0 && (i + 1) != ((size + 1) * size))
			arr[i] = '\n';
		else
			arr[i] = '.';
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
