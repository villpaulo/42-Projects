#include "printf.h"

char	*flagpos(char *str)
{
	int i;
	char *ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 3));
	i = 0;
	while (str[i] && str[i] != '+')
		i++;
	if (i == 0)
	{
		ret[0] = '+';
		ret[1] = '0';
		ret = copystring(str, ret, 2, 1);
		return (ret);
	}
	str[i] = '0';
	str[i - 1] = '+';

	return (str);
}

char	*flag4d(char *str)
{
	char *ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));

	ret[0] = ' ';

	ret = copystring(str, ret, 0, 1);
	return (ret);

}
