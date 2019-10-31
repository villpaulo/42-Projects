#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *str;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	str = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));

	j = 0;
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*funread(char *str)
{
	char buff[2];
	str = (char *)malloc(sizeof(char) * 1);
	while (read(0, buff, 1))
	{
		buff[1] = '\0';
		if (buff[0] == '\n')
			break;
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		main()
{
	char *str;

	str = NULL;
	str = funread(str);
	printf("%s\n", str);
	return (0);
}
