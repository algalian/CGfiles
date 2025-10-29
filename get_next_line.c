/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algalian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:02:19 by algalian          #+#    #+#             */
/*   Updated: 2023/05/04 15:02:20 by algalian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_get(int fd, char *s)
{
	char	*buf;
	int		bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !strchr(s, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			free(s);
			return (NULL);
		}
		buf[bytes] = 0;
		s = join(s, buf);
	}
	free(buf);
	return (s);
}

char	*ft_next(char *s)
{
	char	*leftover;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	leftover = (char *) malloc(sizeof(char) * (strlen(s) - i + 1));
	if (!leftover)
		return (NULL);
	j = 0;
	while (s[i + 1])
	{
		leftover[j] = s[i + 1];
		j++;
		i++;
	}
	leftover[j] = '\0';
	free(s);
	return (leftover);
}

char	*ft_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_get(fd, s);
	if (!s)
		return (NULL);
	line = ft_line(s);
	s = ft_next(s);
	return (line);
}

/*int	main()
{
	char *line;
	int	fd2;
	int i;

	fd2 = open("Necronomicon.txt", O_RDONLY);
	i = 1;
	line = "1";
	while (line)
	{
		line = get_next_line(fd2);
		free(line);
		printf("%i --> %s", i, line);
		i++;
	}
	printf("\n");
	free(line);
	system("leaks a.out");
	close(fd2);
	return (0);
}*/
