
#include <string.h>

int contain(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		++s;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	char *p = (char *)s;
	char *r = (char *)reject;
	int i = 0;
	while (*p)
	{
		if (contain(*p, r))
			return (i);
		++p;
		++i;
	}
	return (i);
}
