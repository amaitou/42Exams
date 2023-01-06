
#include <unistd.h>
#include <stdio.h>

int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main(int ac, char**ag)
{
	int c;
	char *p;
	if (ac == 2)
	{
		p = ag[1];
		while (*p)
		{
			if (is_alpha(*p))
			{
				if (*p >= 'A' && *p <= 'Z')
					c = (*p - 'A') + 1;
				else
					c = (*p - 'a') + 1;
				while (c > 0)
				{
					write(1, p, 1);
					--c;
				}
			}
			else
				write(1, p, 1);
			++p;
		}
	}
	write(1, "\n", 1);
	return (0);
}
