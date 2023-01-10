
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
	int r = 0;
	int s = 1;
	while (*p == ' ' || *p == '\n' || *p == '\t' || *p == '\f' || *p == '\v' || *p == '\r')
		++p;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			s *= -1;
		++p;
	}
	while (base(*p, str_base) != -1)
	{
		r = r * str_base;
		r = r + base(*p, str_base);
		p++;
	}
	return r * s;
}
