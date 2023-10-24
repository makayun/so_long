/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:43:31 by mmakagon          #+#    #+#             */
/*   Updated: 2023/09/29 20:22:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	int		i;
	char	*new_str;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[len])
		len++;
	len += 1;
	new_str = (char *) malloc(len * sizeof(char));
	if (new_str != NULL)
	{
		while (i != len)
		{
			new_str[i] = str[i];
			i++;
		}
	}
	return (new_str);
}
