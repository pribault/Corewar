/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:06:03 by pribault          #+#    #+#             */
/*   Updated: 2017/05/12 17:51:05 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_joinf.h"

size_t		get_next_arg(va_list va, const char *format, size_t *i)
{
	if (format[*i] == 'd')
		return (get_number_len(va));
	else if (format[*i] == 's')
		return (get_string_len(va));
	return (0);
}

void		print_next_arg(va_list va, char *new, size_t *j, char c)
{
	if (c == 'd')
		print_number(va, new, j);
	else if (c == 's')
		print_string(va, new, j);
}

void		fill_string(va_list va, const char *format, char *new)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			print_next_arg(va, new, &j, format[i++]);
		}
		else
			new[j++] = format[i++];
	}
}

char		*ft_joinf(const char *format, ...)
{
	char	*new;
	va_list	va;
	size_t	len;
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	len = 0;
	va_start(va, format);
	while (format[i])
	{
		if (format[i++] == '%')
		{
			n++;
			len += get_next_arg(va, format, &i);
		}
	}
	new = (char*)malloc(sizeof(char) * (len + i - 2 * n + 1));
	ft_bzero(new, len + i - 2 * n + 1);
	va_start(va, format);
	fill_string(va, format, new);
	va_end(va);
	return (new);
}
