
#include <stdio.h>
#include <stdlib.h>

int find_max(int a, int b)
{
	return (a >= b)? a: b;
}

int find_min(int a, int b)
{
	return (a <= b)?a: b;
}

int pgcd(int a, int b)
{
	int max = find_max(a, b);
	int min = find_min(a, b);
	int i = 1;
	int result = 0;
	while (i < min)
	{
		if (min % i == 0 && max % i == 0)
				result = i;
		++i;
	}
	return (result);
}

int main(int ac, char **ag)
{
	if (ac == 3)
	{
		int a = atoi(ag[1]);
		int b = atoi(ag[2]);
		printf("%d", pgcd(a, b));
	}
	printf("\n");
	return (0);
}


