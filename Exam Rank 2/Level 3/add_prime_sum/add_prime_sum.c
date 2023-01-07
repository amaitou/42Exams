
#include <unistd.h>

int ft_atoi(char *p)
{
	int r = 0;
	int s = 1;
	while (*p == ' ' || *p == '\n' || *p == '\t' || *p == '\r' || *p == '\v' || *p == '\f')
		++p;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			s *= (-1);
		++p;
	}
	while (*p >= '0' && *p <= '9')
	{
		r = r * 10 + *p - 48;
		++p;
	}
	return (r * s);
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
		ft_putnbr(n % 10 );
	}
}

int is_prime(int n)
{
	int i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int main(int ac, char **ag)
{

	int sum = 0;
	if (ac == 2)
	{
		int n = ft_atoi(ag[1]);
		int i = 2;
		while (i <= n)
		{
			if (is_prime(i))
				sum += i;
			++i;
		}
	}
	ft_putnbr(sum);
	return (0);
}
