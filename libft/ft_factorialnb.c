/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorialnb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:34:40 by vgladush          #+#    #+#             */
/*   Updated: 2017/10/23 20:34:43 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorialnb(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	else if (nb < 0 || nb > 12)
		return (0);
	return (nb * ft_factorialnb(nb - 1));
}
