
int contain(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return 1;
		++s;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	char *a = (char *)s1;
	char *b = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	while (*a)
	{
		if (contain(*a, b))
			return (a);
		++a;
	}
	return (NULL);
}
