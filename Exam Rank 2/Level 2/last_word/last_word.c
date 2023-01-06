
#include <unistd.h>

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		char *p = ag[1];
		while (*p)
			++p;
		--p;
		while ((*p == ' ' || *p == '\t') && *p)
			--p;
		while ((*p != ' ' && *p != '\t') && *p)
			--p;
		++p;
		while ((*p != ' ' && *p != '\t') && *p)
		{
			write(1, p, 1);
			++p;
		}
	}
	write(1, "\n", 1);
	return (0);
}
