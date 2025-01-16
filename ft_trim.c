/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elen_t13 <elen_t13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:00:41 by elen_t13          #+#    #+#             */
/*   Updated: 2025/01/16 16:00:52 by elen_t13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_newline(char *join)
{
	int	i;

	i = 0;
	while (join[i])
	{
		if (join[i] == '\n' && join[i + 1] == '\n')
		{
			write(2, "Invalid map\n", 12);
			exit(0);
		}
		i++;
	}
}

void	check_whitespaces(char **res)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	while (res[i])
	{
		temp = res[i];
		res[i] = ft_strtrim(res[i], " \t\n\v\f\r");
		free(temp);
		i++;
	}
}

size_t	ft_check(char const *set, char const str)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (ft_check(set, s1[end - 1]))
		end--;
	res = (char *)malloc(sizeof(char) * (end + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < end)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
// crops only end for splitted array