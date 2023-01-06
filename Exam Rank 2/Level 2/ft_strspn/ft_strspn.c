
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

size_t	ft_strspn(const char *s, const char *accept)
{
	char *a = (char *)s;
	char *b = (char *)accept;
	int i = 0;
	while (contain(*a, b))
	{
		++a;
		++i;
	}
	return (i);
}
