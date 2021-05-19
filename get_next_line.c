/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:01:57 by acrucesp          #+#    #+#             */
/*   Updated: 2021/05/19 17:51:31 by acrucesp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ret;
	int	len;
	int	i;
	int	j;

	if (str1 && str2)
		len = ft_strlen(str1) + ft_strlen(str2);
	else
		len = ft_strlen(str1);
	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	while (str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		ret[i] = str2[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int	i;

	i = 0;
	if (!str)
	{
		ret = malloc(sizeof(char) * 1);
		*ret = '\0';
		return (ret);
	}
	else
		ret = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	get_next_line(char **line)
{
	char	buff[2];
	char	*aux;
	int		sz;

	buff[1] = '\0';
	*line = 0;
	sz = read(0, buff, 1);
	while (sz && buff[0] != '\n')
	{
		if (!*line)
			*line = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(*line, buff);
			free(*line);
			*line = ft_strdup(aux);
			free(aux);
			aux = 0;
		} 
		sz = read(0, buff, 1);
	}
	if (sz < 0)
		return (-1);
	if (!*line && buff[0] == '\n')
		*line = ft_strdup(""); 
	if (sz > 0)
		return (1);
	else
		return (0);
}

int	main()
{
	char *line;
	int ret;

	while ((ret = get_next_line(&line)))
	{
		printf("%s, %i\n", line, ret);
		free(line);
	}
	printf("%s, %i\n", line, ret);
}
