
#include <stdio.h>
#include <unistd.h>

static int contain(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		++s;
	}
	return (0);
}

static int spaces(char c)
{
	return (contain("\t\n\f\v\r \t", c));
}

static int signs(char c)
{
	return (contain("-+", c));
}

int	ft_atoi(const char *str)
{
	char *p = (char *)str;
	int sign = 1;
	int r = 0;
	int i = 0;
	while (spaces(p[i]))
		++i;
	if (signs(p[i]))
	{
		if (p[i] == '-')
			sign *= -1;
		++i;
	}
	while (p[i] >= '0' && p[i] <= '9')
	{
		r = r * 10 + p[i] - 48;
		++i;
	}
	return (r * sign);
}
