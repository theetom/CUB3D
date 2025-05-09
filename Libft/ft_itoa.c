/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:19:21 by toferrei          #+#    #+#             */
/*   Updated: 2025/03/25 14:17:00 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		m;

	nb = n;
	m = find_size(nb);
	str = malloc(sizeof * str *(m + 1));
	if (!str)
		return (NULL);
	str[m] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[--m] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
