
#include <stdlib.h>

int ft_abs(int n)
{
	return (n < 0)? n * (-1): n;
}

int     *ft_rrange(int start, int end)
{
	int size = ft_abs(end - start) + 1;
	int *p = malloc(sizeof(int) * size);
	int i = 0;
	if (!p)
		return (0);
	if (end == start)
		p[0] = end;
	if (end > start)
	{
		while (end >= start)
		{
			p[i] = end;
			--end;
			++i;
		}
	}
	else
	{
		while (end <= start)
		{
			p[i] = end;
			end++;
			++i;
		}
	}
	return (p);
}
