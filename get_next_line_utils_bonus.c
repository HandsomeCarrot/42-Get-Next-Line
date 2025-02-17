/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:09:01 by vpoka             #+#    #+#             */
/*   Updated: 2024/11/11 13:37:37 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*str;
	int		pos;

	s_len = ft_strlen(s);
	str = malloc(s_len * sizeof(char) + 1);
	if (!str || !s)
		return (NULL);
	pos = 0;
	while (pos <= s_len)
	{
		str[pos] = s[pos];
		pos++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	result_len;
	size_t	pos;

	result_len = ft_strlen(s1) + ft_strlen(s2);
	if (result_len == 0)
		return (ft_strdup(""));
	result = malloc((result_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	pos = 0;
	while (s1 && s1[pos])
	{
		result[pos] = s1[pos];
		pos++;
	}
	while (s2 && *s2)
	{
		result[pos] = *s2;
		s2++;
		pos++;
	}
	result[pos] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = (char *)s;
	while (result && *result)
	{
		if (*result == (char)c)
			return (result);
		result++;
	}
	if (result && *result == (char)c)
		return (result);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			pos;
	unsigned int	s_len;
	int				res_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	res_len = len;
	if (len > s_len - start)
		res_len = s_len - start;
	res = malloc(res_len * sizeof(char) + 1);
	if (!res)
		return (res);
	pos = 0;
	while (pos < len && s[start + pos])
	{
		res[pos] = s[start + pos];
		pos++;
	}
	res[pos] = '\0';
	return (res);
}
