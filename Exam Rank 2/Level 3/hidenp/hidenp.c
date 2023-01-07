
#include <unistd.h>

int main(int ac, char **ag)
{
	if (ac == 3)
	{
		int i = 0;
		int j = 0;
		char *a = ag[1];
		char *b = ag[2];
		while (b[i])
		{
			if (b[i] == a[j])
				++j;
			++i;
		}
		if (!a[j])
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
