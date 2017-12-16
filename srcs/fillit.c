/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:38:22 by vgladush          #+#    #+#             */
/*   Updated: 2017/11/12 20:38:23 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*res;
	char	buf;

	i = 0;
	if ((ac != 2) || (fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	while (read(fd, &buf, 1) > 0)
		++i;
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	fd = open(av[1], O_RDONLY);
	i = 0;
	while (read(fd, &buf, 1) > 0)
		res[i++] = buf;
	res[i] = '\0';
	close(fd);
	if (ft_validterm(res, 0, 0, 0))
		ft_crtall(res, 65, (ft_strlen(res) + 1) / 21, 0);
	else
		ft_putstr("error\n");
	free(res);
	return (0);
}
