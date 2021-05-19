/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrucesp <acrucesp@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:01:57 by acrucesp          #+#    #+#             */
/*   Updated: 2021/05/19 14:28:45 by acrucesp         ###   ########.fr       */
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

int	get_next_line(char **line)
{
	char	buff[2];
	char	*ret;
	char	*aux;

	buff[1] = '\0';
	ret = 0;
	while (read(0, buff, 1) && buff[0] != '\n')
	{
		if (!ret)
			ret = ft_strjoin(buff, "");
		else
		{
			aux = ft_strjoin(ret, buff);
			free(ret);
			ret = ft_strjoin(aux, "");
			free(aux);
			aux = 0;
		} 
	}
	if (ret)
	{
		*line = ret;
		return (1);
	}
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
