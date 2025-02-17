/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:21:06 by vpoka             #+#    #+#             */
/*   Updated: 2024/11/11 14:30:21 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	/* int		fd1;
	int		fd2;
	int		fd3;
	char	*str1;
	char	*str2;
	char	*str3;
	int		i;

	fd1 = open("1", O_RDONLY);
	fd2 = open("2", O_RDONLY);
	fd3 = open("3", O_RDONLY);
	str1 = get_next_line(fd1);
	str2 = get_next_line(fd2);
	str3 = get_next_line(fd3);
	i = 0;
	while (i < 13)
	{
		printf(" -> file: 1 line #%i, size = %i\n", i + 1, printf("%s", str1));
		free(str1);
		str1 = get_next_line(fd1);
		printf(" -> file: 2 line #%i, size = %i\n", i + 1, printf("%s", str2));
		free(str2);
		str2 = get_next_line(fd2);
		printf(" -> file: 3 line #%i, size = %i\n", i + 1, printf("%s", str3));
		free(str3);
		str3 = get_next_line(fd3);
		i++;
	}
	free(str1);
	close(fd1);
	free(str2);
	close(fd2);
	free(str3);
	close(fd3); */
	/* int fd = open("1", O_RDONLY);
	int i = 0;
	char *str;
	while (i < 2)
	{
		str = get_next_line(fd);
		printf(" -> line #%i, size = %i\n", i + 1, printf("%s", str));
		free(str);
		i++;
	}
	close(fd);
	str = get_next_line(fd);
	printf(" -> line #%i, size = %i\n", i + 1, printf("%s", str));
	free(str);
	i = 0;
	fd = open("1", O_RDONLY);
	while (i < 5)
	{
		str = get_next_line(fd);
		printf(" -> line #%i, size = %i\n", i + 1, printf("%s", str));
		free(str);
		i++;
	}
	close(fd); */
	int fd = open("2", O_RDONLY);
	char *str = get_next_line(fd);
	printf(" -> size = %i\n", printf("%s", str));
	free(str);
	str = get_next_line(fd);
	printf(" -> size = %i\n", printf("%s", str));
	close(fd);
	free(str);
	/* int fd = open("3", O_RDONLY);
	char *str = get_next_line(fd);
	printf(" -> size = %i\n", printf("%s", str));
	free(str);
	str = get_next_line(fd);
	printf(" -> size = %i\n", printf("%s", str));
	free(str);
	close(fd); */
	return (0);
}
