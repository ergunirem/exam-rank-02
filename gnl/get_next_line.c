/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_linex.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 17:35:22 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/01/12 09:00:33 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_linex.h"

int	ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	// printf("s1: %s\n", s1);
	while (s1[i])
	{
			str[j] = s1[i];
			i++;
			j++;
	}
	i = 0;
	// printf("s2: %s\n", s2);
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	//printf("str_join: %s\n", str);
	free(s1);
	return (str);
}

char	*get_line(char *container)
{
	char *line;
	int i;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		line[i] = container[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_container(char *container)
{
	char *tmp;
	int		i;
	int		j;
	i= 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (!(container[i]))
	{
		free(container);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(container) - i + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	i++;
	while (container[i])
	{
		tmp [j] = container[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	free(container);
	return (tmp);
}
char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int	get_next_line(char **line)
{
	static char		*container;
	char			buffer[BUFFER_SIZE + 1];
	int				result;

	if (line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	result = 1;
	while (result != 0 && ft_strchr(container, '\n') == NULL)
	{
		result = read(0, buffer, BUFFER_SIZE);
		//printf("res: %d\n", result);
		if (result < 0)
			return (-1);
		buffer[result] = '\0';
		if (container == NULL)
		{
			container = (char *)malloc(sizeof(char) * 1);
			container[0] = '\0';
		}
		container = ft_strjoin(container, buffer);
		if (container == NULL)
			return (-1);
	}
	*line = get_line(container);
	//printf("line: %s\n", *line);
	//printf("containerB: %s\n", container);
	container = update_container(container);
	//printf("containerA: %s\n", container);
	if (*line == NULL || (container == NULL && result != 0))
		return (-1);
	if (result == 0)
		return (0);
	return (1);
}
