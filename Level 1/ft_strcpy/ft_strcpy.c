
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	char *p = s1;
	while (*s2)
	{
		*p = *s2;
		++p;
		++s2;
	}
	*p = '\0';
	return (s1);
}
