
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int m = tab[0];
	unsigned int i = 0;
	while (i < len)
	{
		if (m < tab[i])
			m = tab[i];
		++i;
	}
	return (m);
}
