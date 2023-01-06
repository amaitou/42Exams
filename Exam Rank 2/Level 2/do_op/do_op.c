
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **ag)
{
	if (ac == 4)
	{
		int a = atoi(ag[1]);
		int b = atoi(ag[3]);
		char s = ag[2][0];
		if (s == '-')
			printf("%d", a - b);
		if (s == '+')
			printf("%d", a + b);
		if (s == '*')
			printf("%d", a * b);
		if (s == '/')
			printf("%d", a / b);
		if (s == '%')
			printf("%d", a % b);
	}
	printf("\n");
	return (0);
}
