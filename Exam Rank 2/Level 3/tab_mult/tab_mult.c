
#include <unistd.h>

int ft_atoi(char *p)
{
	int s = 1;
	int r = 0;
	while (*p == ' ' || *p == '\n' || *p == '\t' || *p == '\f' || *p == '\r' || *p == '\v')
		++p;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			s *= -1;
		++p;
	}
	while (*p >= '0' && *p <= '9')
	{
		r = r * 10 + *p - 48;
		++p;
	}
	return (r);
}

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
	if (ac == 2)
	{
		int n = ft_atoi(ag[1]);
		int i = 1;
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(n * i);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
