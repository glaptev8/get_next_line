
#include "get_next_line.h"
#include "libft/libft.h"


static void	*new_str(char **str, int fd)
{
	size_t	len;
	int		i;
	char	*new_str;
	i = 0;
	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	new_str = ft_strsub(str[fd], 0, len);
//	if (str[fd][len] == '\n')
//		*str += len + 1;
//	else if (str[fd][len] == '\0')
//		*str += len;
while (len-- > 0)
	str[fd]++;
str[fd]++;
return (new_str);
}
int		get_next_line(const int fd, char **line)

{
	int 			ret;
	char			buf[BUFF_SIZE + 1];
	static	char	*s[512];

	if (fd == -1 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strnew(ret);
//		free(s[fd]);
		s[fd] = ft_strjoin(s[fd], buf);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && !s[fd])
		return (0);
	*line = new_str(s,fd);
	return (1);
}
//
//int		main(void)
//{
//	int		fd;
////	char	*str[256];
//	char	*str2[256];
//
//	fd = open("gleb", O_RDONLY);
//
//
//
//
//	//fd = open("alp", O_RDONLY);
//	get_next_line(fd, str2);
////	get_next_line(fd, str2);
//	//fd = open("gleb", O_RDONLY);
//	//printf("%d\n",get_next_line(fd, str));
//	//printf("%d",get_next_line(fd, str2));
//	printf("%d",get_next_line(fd, str2));
//	printf("%s", *str2);
//	return (0);
//}