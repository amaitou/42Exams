
#include <unistd.h>

int first_contain(char c, char *s, int p)
{
	int i = 0;
	while (i < p)
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int second_contain(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		++s;
	}
	return (0);
}

int main(int ac, char **ag)
{
	if (ac == 3)
	{
		char *a = ag[1];
		char *b = ag[2];
		int i = 0;
		while (a[i])
		{
			if (!first_contain(a[i], a, i))
				write(1, &a[i], 1);
			++i;
		}
		i = 0;
		while (b[i])
		{
			if (!(first_contain(b[i], b, i)) && !(second_contain(b[i], a)))
				write(1, &b[i], 1);
			++i;
		}
	}
	write(1, "\n", 1);
}
