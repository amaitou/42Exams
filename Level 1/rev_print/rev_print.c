
#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		++i;
	return (i);
}

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *p = ag[1];
		int i = ft_strlen(p) - 1;
		while (i >= 0)
		{
			write(1, &p[i], 1);
			--i;
		}
	}
	write(1, "\n", 1);
	return (0);
}
