
#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (*s)
	{
		s++;
		++i;
	}
	return (i == 1);
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
	if (ac == 4)
	{
		char *p = ag[1];
		if (ft_strlen(ag[2]) == 1 && ft_strlen(ag[3]) == 1)
		{
			char s = ag[2][0];
			char r = ag[3][0];
			while (*p)
			{
				if (*p == s)
					write(1, &r, 1);
				else
					write(1, p, 1);
				++p;
			}
		}
		else
			ft_putstr(p);
	}
	write(1, "\n", 1);
	return (0);
}
