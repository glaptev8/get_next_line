
#include "get_next_line.h"
#include "libft/libft.h"

int		new_str(char **str, int fd, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\0' && str[fd][len] != '\n')
		len++;
	*line = ft_strsub(str[fd], 0, len);
	tmp = ft_strdup(str[fd] + len + (str[fd][len] == '\n' ? 1 : 0));
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}

int get_next_line(const int fd, char **line)
{
	static char	*str[252];
	char 		*tmp;
	int 		ret;
	char 		buf[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (str[fd][0] == '\0'))
		return (0);
	return (new_str(str, fd, line));
}
