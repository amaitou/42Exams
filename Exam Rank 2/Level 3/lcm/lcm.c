
#include <stdio.h>

static int find_max(unsigned int a, unsigned int b)
{
	return (a >= b) ? a: b;
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	int num = find_max(a, b);
	if (!a || !b)
		return (0);
	while (1)
	{
		if (num % a == 0 && num % b == 0)
			return (num);
		++num;
	}
}
