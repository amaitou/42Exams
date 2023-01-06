
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		++i;
	return (i);
}

char    *ft_strdup(char *src)
{
	char *p;
	int i = 0;

	p = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!p)
		return (NULL);
	while (src[i])
	{
		p[i] = src[i];
		++i;
	}
	return (p);
}
