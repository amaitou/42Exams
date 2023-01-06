
int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		++i;
	return i;
}

char    *ft_strrev(char *str)
{
	int r = ft_strlen(str) - 1;
	int l = 0;
	char c;
	while (r > l)
	{
		c = str[l];
		str[l] = str[r];
		str[r] = c;
		++l;
		--r;
	}
	return (str);
}
