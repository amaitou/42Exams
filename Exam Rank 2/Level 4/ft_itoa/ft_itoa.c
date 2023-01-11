
#include <stdio.h>
#include <stdlib.h>

int ft_size(long n)
{
	int i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long n = nbr;
	int s = ft_size(n);
	char *p = malloc(sizeof(char) * (s + 1));
	if (!p)
		return (NULL);
	p[s] = '\0';
	--s;
	if (n == 0)
		p[0] = 0 + 48;
	else if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		p[s] = n % 10 + 48;
		--s;
		n /= 10;
	}
	return (p);
}
