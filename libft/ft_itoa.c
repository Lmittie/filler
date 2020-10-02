/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshawn <yshawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:28:43 by yshawn            #+#    #+#             */
/*   Updated: 2020/02/27 15:22:39 by yshawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	z;
	unsigned int	numlen;
	char			*dest;

	numlen = ft_numlen(n, 10);
	dest = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!dest)
		return (NULL);
	i = numlen - 1;
	if (n < 0)
		z = n * -1;
	else
		z = n;
	while (i > 0)
	{
		dest[i] = (z % 10) + 48;
		z = z / 10;
		i--;
	}
	dest[0] = (z % 10) + 48;
	if (n < 0)
		dest[0] = '-';
	dest[numlen] = '\0';
	return (dest);
}
