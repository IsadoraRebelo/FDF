/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 11:05:38 by dfreire       #+#    #+#                 */
/*   Updated: 2019/01/20 15:39:47 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	len(int n)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*fresh;
	int		i;

	i = len(n);
	fresh = ft_strnew(i);
	if (fresh == NULL)
		return (0);
	if (n < 0)
		fresh[0] = '-';
	else
		n = 0 - n;
	while (n / 10)
	{
		fresh[--i] = (0 - (n % 10)) + '0';
		n /= 10;
	}
	fresh[--i] = (0 - (n % 10)) + '0';
	return (fresh);
}
