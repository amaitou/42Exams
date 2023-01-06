
#include <unistd.h>

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *p = ag[1];
		//char l;
		while (*p)
		{
			if (*p >= 'A' && *p <= 'Z')
				*p = 'Z' - (*p - 'A');
			else if (*p >= 'a' && *p <= 'z')
				*p = 'z' - (*p - 'a');
			write(1, p, 1);
			++p;
		}
	}
	write(1, "\n", 1);
	return (0);
}
