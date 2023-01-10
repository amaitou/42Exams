
#include <stdio.h>

void lowercase(char *s)
{
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s += 32;
		++s;
	}
}

int base(char c, int base)
{
	int i = 0;
	char hexadecimal[16] = "0123456789abcdef";
	while (i < base)
	{
		if (c == hexadecimal[i])
			return i;
		++i;
	}
	return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
	char *p = (char *)str;
	int nb = 0;
	int i = 0;
	while (base(p[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(p[i], str_base);
		i++;
	}
	return nb;
}
