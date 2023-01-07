
#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		++i;
	return (i);
}

void ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		++s;
	}
}

int main(int ac, char **ag)
{
	if (ac == 3)
	{
		char *a = ag[1];
		char *b = ag[2];
		int i = 0;
		int j = 0;
		while (b[i])
		{
			if (b[i] == a[j])
				++j;
			++i;
		}
		if (!a[j])
			ft_putstr(a);
}
	write(1, "\n", 1);
	return (0);
}
