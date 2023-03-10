/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:48:54 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/14 13:57:51 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strjoin_f(char *s1, char *s2, int mode)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	res = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	if (mode == 1)
		free(s1);
	else if (mode == 2)
		free(s2);
	else if (mode == 3)
	{
		free(s1);
		free(s2);
	}
	return (res);
}

char	*ft_strtrim_head(char *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	res = ft_substr(s1, i, j - i + 1);
	free(s1);
	return (res);
}

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_nbrlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (9 < n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_strlen_c(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}


// char	*ft_strtrim_tail(char *s1, char const *set)
// {
// 	char	*res;
// 	int		i;
// 	int		j;

// 	if (!s1 || !set)
// 		return (NULL);
// 	i = 0;
// 	j = ft_strlen(s1);
// 	while (i < j && ft_strchr(set, s1[j]))
// 		j--;
// 	res = ft_substr(s1, i, j - i + 1);
// 	free(s1);
// 	return (res);
// }
