#include <unistd.h>

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *p = ag[1];
		while (*p)
		{
			if (*p >= 'A' && *p <= 'Z')
			{
				write(1, "_", 1);
				*p += 32;
			}
			write(1, p, 1);
			++p;
		}
	}
	write(1, "\n", 1);
	return (0);
}
