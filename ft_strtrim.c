/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:08:14 by fraqioui          #+#    #+#             */
/*   Updated: 2022/10/20 13:17:51 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static	int	ft_search(char c, char const *from)
{
	while (*from)
	{
		if (*from == c)
			return (1);
		from++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	first;
	int	last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (s1[first] && ft_search(s1[first], set) == 1)
		first++;
	while (last >= first && ft_search(s1[last], set) == 1)
		last--;
	if (last == -1)
		return (ft_substr(s1, first, 0));
	else
		return (ft_substr(s1, first, (last - first + 1)));
}
