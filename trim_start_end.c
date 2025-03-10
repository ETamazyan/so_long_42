/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elen_t13 <elen_t13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:01:27 by elen_t13          #+#    #+#             */
/*   Updated: 2025/01/16 16:01:28 by elen_t13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	*check_newline2(char *join)
{
	char	*temp;
	int		i;

	temp = join;
	i = 0;
	join = ft_strtrim2(join, " \t\n\v\f\r");
	free(temp);
	return (join);
}

int	ft_check2(char const *set, char const str)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_startlen(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && ft_check2(set, s1[i]))
		i++;
	while (s1[i] != '\n' && i > 0)
		i--;
	return (i);
}

int	ft_size(int start, int end)
{
	int	size;

	size = 0;
	size = end - start;
	return (size);
}

char	*ft_strtrim2(char *s1, char *set)
{
	char	*res;
	int		i;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_startlen(s1, set);
	end = ft_strlen((char *)s1);
	while (end > start && ft_check2(set, s1[end - 1]))
		end--;
	res = (char *)malloc(sizeof(char) * (ft_size(start, end) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_size(start, end))
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

//crops start and end together joined
