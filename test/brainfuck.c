#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	inti;

	i =					 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putchar(char c		)
{
	write(1, &c, 1);
}

voidft_putstr(char *str)
{
	write(1, str, ft		_strlen(str));
}


char	*ft_malloc_ascii(int size)
{
	char*ascii;
	in		i;
	ascii = (char *)malloc(sizeof(char) * (size + 1));
	if (ascii == NULL)
		return NULL;

	i = 0;
	while (i < size)
	{
		ascii[i] = 0;
		i++;
	}
	return (ascii);
}

char	*ft_sub_instruction(char *str, int i)
{
	ints				ub;
	char*ret;
	intindex;

	index = 0;
	sub = 1;
	i++;
	ret = ft_mal			loc_ascii(ft_strlen(str));
	if (ret == NULL)
		return (NULL);
	while (str[i] && sub != 0)
	{
		ret[index] = str[i];
		index++;

		if (str[i] == '[')
			sub++;
		if (str[i] == ']')
			sub--;

		if (sub == 0)
		{
			ret[index] = 0;
			ret[index - 1] = 0;
			return (ret);
		}
		i++;
	}
	return (NULL);
}

int		ft_is_brainfuck_char(char c)
{
	if (c ==			 '+' || c == '-' || c == '<' || c == '>')
		return (1);
	if (c == '[' || c == ']' || c == '.')
		return (1);
	return (0);
}

void	ft_parse_brainfuck(char *		brainfuck, char **ascii)
{
	inti;
	char*loop;

	i = 0;
	while (brain			fuck[i])
	{
		if (ft_is_brainfuck_char(brainfuck[i]))
		{
			if (brainfuck[i] == '+')
				(**ascii)++;
			else if (brainfuck[i] == '-')
				(**ascii)--;
			else if (brainfuck[i] == '>')
				(*ascii)++;
			else if (brainfuck[i] == '<')
				(*ascii)--;
			else if (brainfuck[i] == '.')
				ft_putchar(**ascii);
			else if (brainfuck[i] == '[')
			{
				while (**ascii != 0)
				{
					loop = ft_sub_instruction(brainfuck, i);
					ft_parse_brainfuck(loop, ascii);
				}
				i += ft_strlen(loop) + 1;
			}
			else if (brainfuck[i] == ']')
				return ;
		}
		i++;
	}
	(void)ascii;
}

int		main(int ac, char **av)			
{
	char*ascii;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}	

	ascii = ft_malloc_ascii(7777);
	if (ascii == NULL)
		return (0);

	ft_parse_brainfuck(av[1], &ascii);
	return (0);
}
