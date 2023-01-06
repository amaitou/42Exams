
#include <unistd.h>

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *p = ag[1];
		while (*p)
		{
			if (*p == '_' && *(p + 1))
			{
				++p;
				*p -= 32;
				write(1, p, 1);
			}
			else
				write(1, p, 1);
			++p;
		}
	}
	write(1, "\n", 1);
	return (0);
}
