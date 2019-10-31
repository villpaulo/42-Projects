#include "printf.h"

char	*ret_p(char *str, int *tab)
{
	tab = ft_zero(tab, 13);
	return (str);
}

char	*ret_S(char *str, int *tab)
{
	tab = ft_zero(tab, 13);
	return (str);
}

char	*ret_c(char c, int *tab)//NORME MED
{
	char *str;
	int i;

	str = (char *)malloc(sizeof(char) * (tab[5] + 2));

	if (tab[5] > 0 && tab[i = 1] > 0)
	{
		str[0] = c;
		while (tab[5]-- != 1)
			str[i++] = ' ';
		str[i] = '\0';
	}
	else if (tab[5] > 0)
	{
		i = 0;
		while (tab[5]-- != 1)
			str[i++] = ' ';
		str[i] = c;
		i++;
		str[i] = '\0';
	}
	else
	{
		str[0] = c;
		str[1] = '\0';
	}
	return (str);
}

char	*ret_modulo(int *tab)//NORME MED
{
	char *str;
	int i;

	str = (char *)malloc(sizeof(char) * (tab[5] + 2));

	if (tab[5] > 0 && tab[i = 1] > 0)
	{
		str[0] = '%';
		while (tab[5]-- != 1)
			str[i++] = ' ';
		str[i] = '\0';
	}
	else if (tab[5] > 0)
	{
		i = 0;
		while (tab[5]-- != 1)
			str[i++] = ' ';
		str[i] = '%';
		i++;
		str[i] = '\0';
	}
	else
	{
		//printf("TOTO\n");
		str[0] = '%';
		str[1] = '\0';
	}
	return (str);
}

char	*ret_s(char	*n, int *tab)//NORME M
{
	int i;
	char *str;
	int j;

	if (tab[5] > ft_strlen(n))
		j = tab[5] - ft_strlen(n);
	else
		j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(n) + j + 1));
	i = 0;

	if (tab[5] > 0 && tab[1] > 0)
	{
		i = -1;
		while (n[++i])//care modif here norme
			str[i] = n[i];
		if (j != 0)
			str = fill(str, i, j);
	}
	else if (tab[5] > 0)
	{
		if (j != 0)
			str = fill(str, i, j);
		str = ft_strjoin(str, n);
	}
	return (str);
}

char		*ret_x(char *str, int *tab, int ne)
{
	int j;
	int z;

	z = 0;
	j = 0;

	if (tab[6] > ft_strlen(str))// appelle d'une autre fonction ici
	{
		z = tab[6];
		if (str[0] == '+' || str[0] == '-')
			z++;
		if (tab[2] > tab[6] || tab[5] > tab[6])
		{
			j = tab[2] + tab[5];
			if (str[0] == '+' || str[0] == '-')
				j++;
		}
	}
	else if ((tab[5] > ft_strlen(str)) && (tab[6] <= ft_strlen(str)))
		j = tab[2] + tab[5];
	else if ((tab[2] > ft_strlen(str)) && (tab[6] <= ft_strlen(str)))
		z = tab[2] + tab[5];
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}

char		*ret_d(unsigned long n, int *tab, int b)
{
	char *str;
	int ne;
	int j;
	int z;

	z = 0;
	j = 0;
	ne = 0;
	if (!(str = ft_putnbr(n, 10, b)))
		return (NULL);
	if (tab[1] > 0)
		ne = 1;
	if (tab[6] > ft_strlen(str))
	{
		z = tab[6];
		if (str[0] == '+' || str[0] == '-')
			z++;
		if (tab[2] > tab[6] || tab[5] > tab[6])
		{
			j = tab[2] + tab[5];
			if (str[0] == '+' || str[0] == '-')
				j++;
		}
		str = checkfill(str, j, ne, z);
		return (str);
	}
	else if (tab[5] > ft_strlen(str))
		j = tab[2] + tab[5];
	else if (tab[2] > ft_strlen(str))
		z = tab[2] + tab[5];
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}

char		*ret_o(char *str, int *tab)
{
	int ne;
	int j;
	int z;

	z = 0;
	j = 0;
	ne = 0;

	if (tab[1] > 0)
	{
		ne = 1;
		tab[2] = 0;//facultatif erreur de gcc gere ici
	}
	if (tab[6] > ft_strlen(str))
	{
		z = tab[6];
		if (str[0] == '+' || str[0] == '-')
			z++;
		if (tab[2] > tab[6] || tab[5] > tab[6])
		{
			j = tab[2] + tab[5];
			if (str[0] == '+' || str[0] == '-')
				j++;
		}
		str = checkfill(str, j, ne, z);
		return (str);
	}
	else if (tab[5] > ft_strlen(str))
		j = tab[2] + tab[5];
	else if (tab[2] > ft_strlen(str))
		z = tab[2] + tab[5];
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}

char		*ret_O(char *str, int *tab)
{
	int ne;
	int j;
	int z;

	z = 0;
	j = 0;
	ne = 0;

	if (tab[1] > 0)
	{
		ne = 1;
		tab[2] = 0;//facultatif erreur de gcc gere ici
	}
	if (tab[6] > ft_strlen(str))
	{
		z = tab[6];
		if (str[0] == '+' || str[0] == '-')
			z++;
		if (tab[2] > tab[6] || tab[5] > tab[6])
		{
			j = tab[2] + tab[5];
			if (str[0] == '+' || str[0] == '-')
				j++;
		}
		str = checkfill(str, j, ne, z);
		return (str);
	}
	else if (tab[5] > ft_strlen(str))
		j = tab[2] + tab[5];
	else if (tab[2] > ft_strlen(str))
		z = tab[2] + tab[5];
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}

char		*ret_X(char *str, int *tab)
{
	int ne;
	int j;
	int z;

	z = 0;
	j = 0;
	ne = 0;

	if (tab[1] > 0)
	{
		ne = 1;
		tab[2] = 0;//facultatif erreur de gcc gere ici
	}
	if (tab[6] > ft_strlen(str))
	{
		z = tab[6];
		if (str[0] == '+' || str[0] == '-')
			z++;
		if (tab[2] > tab[6] || tab[5] > tab[6])
		{
			j = tab[2] + tab[5];
			if (str[0] == '+' || str[0] == '-')
				j++;
		}
		str = checkfill(str, j, ne, z);
		return (str);
	}
	else if (tab[5] > ft_strlen(str))
	{
		j = tab[2] + tab[5];
	}
	else if (tab[2] > ft_strlen(str))
		z = tab[2] + tab[5];
	//printf("%d\n", z);
	if (j > 0 || z > 0)
		str = checkfill(str, j, ne, z);
	return (str);
}

/*char		*ret_C(wchar_t n, char *str)
  {

  if (n <= 0x7F)
  str = add_char(n, 1, str);
  else if (n <= 0x7FF)
  {
  str = add_char(((n >> 6) + 0xC0), 1,  str);
  str =add_char(((n & 0x3F) + 0x80), 2, str);
  }
  else if (n <= 0xFFFF)
  {
  str = add_char(((n >> 12) + 0xE0), 1, str);
  str = add_char((((n >> 6) & 0x3F) + 0x80), 2, str);
  str = add_char(((n & 0x3F) + 0x80), 3, str);
  }
  else if (n <= 0x10FFFF)
  {
  str = add_char(((n >> 18) + 0xE0), 1, str);
  str = add_char((((n >> 12) & 0x3F) + 0x80), 2, str);
  str = add_char((((n >> 6) & 0x3F) + 0x80), 3, str);
  str = add_char(((n & 0x3F) + 0x80), 4, str);
  }
  printf("ALOALO\n");
  write(1, str, ft_strlen(str));
  return (str);
  }
  */






// ET L A RENVOIE POUR tab[5], ettab[6](une seule pour les deux), qui gere le -, avec boleen pris en param
/*char	*ret_C(int n, int *tab)
  {

  return (str);
  }
  */
