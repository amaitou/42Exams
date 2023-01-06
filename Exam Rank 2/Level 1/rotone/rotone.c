
#include <unistd.h>

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *p = ag[1];
		while (*p)
		{
			if ((*p >= 'a' && *p <= 'y') || (*p >= 'A' && *p <= 'Y'))
			{
				*p += 1;
				write(1, p, 1);
			}
			else if (*p == 'z' || *p == 'Z')
			{
				*p -= 25;
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
