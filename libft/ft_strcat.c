/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 19:35:05 by dfreire       #+#    #+#                 */
/*   Updated: 2019/01/19 18:05:24 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *d1;
	char *d2;

	d1 = s1;
	d2 = (char*)s2;
	while (*d1 != '\0')
		d1++;
	while (*d2 != '\0')
	{
		*d1 = *d2;
		d1++;
		d2++;
	}
	*d1 = '\0';
	return (s1);
}
