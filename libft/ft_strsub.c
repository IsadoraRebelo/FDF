/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 18:55:10 by dfreire        #+#    #+#                */
/*   Updated: 2019/01/25 20:10:10 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	fresh = (char*)malloc(sizeof(char) * (len + 1));
	if (fresh == NULL)
		return (0);
	i = 0;
	if (s)
	{
		while (i < len)
		{
			fresh[i] = s[start + i];
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
