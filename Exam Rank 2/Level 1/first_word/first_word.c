
#include <unistd.h>

int main(int ac, char **ag)
{
	char *p = ag[1];
	if (ac == 2)
	{
		while ((*p == ' ' || *p == '\t') && *p)
			++p;
		if (*p)
		{
			while ((*p != ' ' && *p != ' ') && *p)
			{
				write(1, p, 1);
				++p;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
