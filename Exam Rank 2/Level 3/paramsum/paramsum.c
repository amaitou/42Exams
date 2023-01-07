
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

int main(int ac, char **ag)
{
	(void)ag;
	if (ac >= 1)
		ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}
