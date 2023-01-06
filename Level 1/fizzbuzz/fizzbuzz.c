
#include <unistd.h>

void ft_putnbr(int n)
{
	char c;
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		++s;
	}
}

int main(void)
{
	int i = 1;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			ft_putstr("fizzbuzz\n");
		else if (i % 3 == 0)
			ft_putstr("fizz\n");
		else if (i % 5 == 0)
			ft_putstr("buzz\n");
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		++i;
	}
	return (0);
}
