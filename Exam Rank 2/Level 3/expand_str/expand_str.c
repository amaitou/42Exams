
#include <unistd.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int i;
		char *p = ag[1];
		while (ft_isspace(*p))
			++p;
		while (*p)
		{
			i = 0;
			if (ft_isspace(*p) && !ft_isspace(*(p + 1)) && *(p + 1))
			{
				while (i < 3)
				{
					write(1, " ", 1);
					++i;
				}
			}
			if (!ft_isspace(*p))
				write(1, p, 1);
			++p;
		}
	}
	write(1, "\n", 1);
	return (0);
}
