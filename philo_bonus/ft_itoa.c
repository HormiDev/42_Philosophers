/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:44:25 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/05/25 16:41:19 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_intlen(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_intlen(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (str == 0)
		return (NULL);
	str[len] = 0;
	if (n >= 0)
		n = n * -1;
	else
		str[0] = '-';
	while ((len > 0 && str[0] == 0) || (len > 1 && str[0] == '-'))
	{
		str[len - 1] = ((n % 10) * -1 + '0');
		n = n / 10;
		len--;
	}
	return (str);
}

static int	ft_intlen(int n)
{
	int	len;
	int	mult;

	if (n == -2147483648)
		return (11);
	len = 1;
	mult = 1;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n / mult > 9)
	{
		len++;
		mult = mult * 10;
	}
	return (len);
}