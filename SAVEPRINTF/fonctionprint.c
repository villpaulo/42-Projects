#include "printf.h"

// REGARDER SI IL N'Y A PAS ENCORE UN MODULO DERIERE!!!!!!

char	*print_c(va_list	ap, int *tab)
{
	int n;
	char *ret;
	char c;
	char *str;

	if ((n = va_arg(ap, int)) == 0)
		return (NULL);
	c = (char) n;

	if ((tab = conver_c(tab)) == NULL)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}

	ret = ret_c(n, tab);
	return (ret);
}


char	*print_s(va_list	ap, int *tab)
{
	char *n;

	if ((n = va_arg(ap, char *)) == 0)
		return (0);

	if (tab[6] > 0 && tab[6] < ft_strlen(n))
		n = flag6s(n, tab);
	if (tab[5] == 0 && tab[6] == 0)
		return (n);
	n = ret_s(n, tab);
	return (n);
}

char	*print_d(va_list	ap, int *tab)
{
	int n;
	char *str;
	int b;
	int count;
	int l;

	n = 0;
	b = 0;
	count = 0;
	if (tab[0] > 0)
		b = 1;
	n = conver_d(tab, n, ap);
	l = n;
	while (l > 0)
	{
		l = l / 10;
		count++;
	}
	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 3);
		if (b == 1)
		{
			str[0] = '+';
			str[1] = '0';
			str[2] = '\0';
		}
		else
		{
			str[0] = '0';
			str[1] = '\0';
		}
		return (str);
	}
	if (tab[5] > 0 && tab[2] > 0)
	{
		tab[2] = tab[5];
		tab[5] = 0;
		b = 1;
	}
	str = ret_d(n, tab, b);
	if (tab[5] > tab[6] && tab[6] > (ft_strlen(ft_putnbr(n, 10, 0))) && b == 1)
		str = flagpos(str);
	if (tab[5] <= count && tab[2] <= count && tab[6] <= count && tab[4] > 0)
		str = flag4d(str);
	if (tab[6] <= tab[5] && (tab[6] >= count || tab[2] >= count) && tab[4] > 0)
		str = flag4d(str);
		
	return (str);
}

char	*print_i(va_list	ap, int *tab)
{
	long n;
	char *str;
	int b;

	b = 0;
	if ((n = va_arg(ap, long)) == 0)
		return (NULL);
	//if (error_d(tab) == 0)
	//	return (NULL);
	if (tab[0] > 0)
		b = 1;
	str = ret_d(n, tab, b);
	return (str);
}

char	*print_p(va_list	ap, int *tab)
{
	unsigned long n;
	char *str;
	int b;

	b = 0;
	str = NULL;
	if ((n = (unsigned long)va_arg(ap, void *)) == 0)
		return (NULL);
	//if (error_d(tab) == 0)
	//	return (NULL);
	str = ft_putnbrx(n, 16, str);
	str = ret_p(str, tab);
	return (str);
}

char	*print_D(va_list	ap, int *tab)
{
	int n;
	char *str;
	int b;

	b = 0;
	if ((n = va_arg(ap, long)) == 0)
		return (NULL);
	if (tab[0] > 0 && tab[1] == 0)
		b = 1;
	str = ret_d(n, tab, b);
	return (str);
}

char	*print_x(va_list ap, int *tab)
{
	unsigned long n;
	char *str;
	int ne;

	ne = 0;
	str = NULL;
	n = 0;

	n = conver_x(tab, n, ap);
	if (n == 0)
		return (retz(str));
	str = ft_putnbrx(n, 16, str);
	if (tab[1] > 0)
	{
		ne = 1;
		tab[2] = 0;//facultatif erreur de gcc gere ici
	}
	str = ret_x(str, tab, ne);
	if (tab[6] > 0)
		tab[2] = tab[6];
	if (tab[3] > 0)
		str = filldx(str, tab, n);
	return (str);
}

char	*print_X(va_list ap, int *tab)
{
	unsigned long n;
	char *str;

	n = 0;
	str = NULL;
	n = conver_X(tab, n, ap);
	if (n == 0)
		return (retz(str));
	str = ft_putnbrX(n, 16);
	str = ret_X(str, tab);
	if (tab[6] > 0)
		tab[2] = tab[6];
	if (tab[3] > 0)
		str = filldX(str, tab, n);
	return (str);
}

char	*print_O(va_list ap, int *tab)
{
	unsigned long n;
	char *str;

	str = NULL;
	if ((n = va_arg(ap, unsigned long)) == 0)
		return (NULL);
	str = ft_putnbrX(n, 16); 
	if (tab[3] > 0)
		str = filldo(str);
	str = ret_O(str, tab);
	return (str);
}

char	*print_o(va_list ap, int *tab)
{
	unsigned long n;
	char *str;

	str = NULL;
	if ((n = va_arg(ap, unsigned int)) == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	//printf("ICICICI%d\n", n);
	//printf("KLKLKL\n");
	//printf("%lu\n", n);
	str = ft_putnbrx(n, 8, str);
	if (tab[3] > 0)
		str = filldo(str);
	str = ret_o(str, tab);
	return (str);
}

char	*print_u(va_list ap, int *tab)
{
	unsigned int n;
	char *str;

	str = NULL;
	if ((n = va_arg(ap, unsigned int)) == 0)
		return (NULL);
	str = ft_putnbrx(n, 10, str);
	str = ret_o(str, tab);
	return (str);
}

char	*print_U(va_list ap, int *tab)
{
	unsigned long n;
	char *str;

	str = NULL;
	if ((n = va_arg(ap, unsigned long)) == 0)
		return (NULL);
	str = ft_putnbrx(n, 10, str);
	str = ret_o(str, tab);
	return (str);
}

char	*print_C(va_list ap, int *tab)
{
	wchar_t n;
	char *str;

	n =(wchar_t)va_arg(ap, wchar_t);
	if (n <= 0x7F)
		str = (add_char1(n));
	else if (n <= 0x7FF)
		str = (add_char2(n));
	else if (n <= 0xFFFF)
		str = (add_char3(n));
	else if (n <= 0x10FFFF)
		str = (add_char4(n));
	else
		return (NULL);
	if (tab[5] != 0)
		str = ret_s(str, tab);
	return (str);
}

char	*print_S(va_list ap, int *tab)
{
	wchar_t *n;
	int i;
	char *str;

	str = NULL;
	i = 0;
	n =(wchar_t *)va_arg(ap, wchar_t *);
	while (n[i])
	{
		str = ft_strjoin(str, print_S2(n[i]));
		i++;
	}
	str = ret_S(str, tab);
	return (str);
}

char	*print_S2(wchar_t n)
{
	char *str;

	if (n <= 0x7F)
		str = (add_char1(n));
	else if (n <= 0x7FF)
		str = (add_char2(n));
	else if (n <= 0xFFFF)
		str = (add_char3(n));
	else if (n <= 0x10FFFF)
		str = (add_char4(n));
	else
		return (NULL);
	return (str);
}

char	*print_modulo(int *tab)
{
	char *str;

	str = ret_modulo(tab);
	return (str);
}

char	*ft_putnbr(long long n, int base, int b)
{
	int tab[100];
	int i;
	char *str;
	int j;

	j = 0;
	i = 0;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0 && (n *= -1))
	{
		j++;
		b = 0;
	}
	while (n > 0)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	str = (char *)malloc(sizeof(char) * i + j + 1);
	if (b == 1)
	{
		j++;
		str[0] = '+';
	}

	if (j == 1 && b == 0)
		str[0] = '-';
	while (i--)
	{	
		if (base > 10 && tab[i] > 9)
			str[j] = ((tab[i] + 87));
		else
			str[j] = (tab[i] + 48);
		j++;
	}
	str[j] = '\0';
	//printf("%s\n", str);
	return (str);
}

char	*ft_putnbrx(unsigned long n, unsigned long base, char *str)
{
	int tab[100];
	int i;
	//	char *str;
	int j;

	j = 0;
	i = 0;

	while (n > 0)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + j + 100000));

	while (i--)
	{	
		if (base > 10 && tab[i] > 9)
			str[j] = (tab[i] + 87);
		else
			str[j] = (tab[i] + 48);
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_putnbrX(unsigned long n, int base)
{
	int tab[100];
	int i;
	char *str;
	int j;

	j = 0;
	i = 0;
	while (n > 0)
	{
		tab[i] = n % base;
		n = n / base;
		i++;
	}
	str = (char *)malloc(sizeof(char) * i + j + 1);

	while (i--)
	{	
		if (base > 10 && tab[i] > 9)
			str[j] = ((tab[i] + 55));
		else
			str[j] = (tab[i] + 48);
		j++;
	}
	str[j] = '\0';
	return (str);
}
