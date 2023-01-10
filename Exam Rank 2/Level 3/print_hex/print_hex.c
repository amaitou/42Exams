
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

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_hex(int n)
{
	char hexadecimal[16] = "0123456789abcdef";
	if (n > 15)
	{
		print_hex(n / 16);
		ft_putchar(hexadecimal[n % 16]);
	}
	else
		ft_putchar(hexadecimal[n % 16]);
}

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int decimal = ft_atoi(ag[1]);
		print_hex(decimal);
	}
	write(1, "\n", 1);
	return (0);
}
