
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		i += ft_putchar(*s);
		++s;
	}
	return (i);
}

int ft_len_signed(int n)
{
	int i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int ft_len_unsigned(unsigned int n)
{
	int i = 0;
	if (n == 0)
		++i;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int ft_len_hex(unsigned long n)
{
	int i = 0;
	if (n == 0)
		++i;
	while (n != 0)
	{
		++i;
		n /= 16;
	}
	return (i);
}

int ft_putsigned(int n)
{
	char c;
	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		ft_putchar(c);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putsigned(n * -1);
	}
	else
	{
		ft_putsigned(n / 10);
		ft_putsigned(n % 10);
	}
	return ft_len_signed(n);
}

int ft_putunsigned(unsigned int n)
{
	char c;
	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putunsigned(n / 10);
		ft_putunsigned(n % 10);
	}
	return ft_len_unsigned(n);
}

int ft_printhex(char *s, unsigned long n)
{
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n > 15)
	{
		ft_printhex(s, n / 16);
		ft_putchar(s[n % 16]);
	}
	else
		ft_putchar(s[n % 16]);
	return (ft_len_hex(n));
}

int helper(va_list arg, char c)
{
	int i = 0;
	if (c == '%')
		i += ft_putchar('%');
	else if (c == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (c == 'd')
		i += ft_putsigned(va_arg(arg, signed int));
	else if (c == 'u')
		i += ft_putunsigned(va_arg(arg, unsigned int));
	else if (c == 'x')
		i += ft_printhex("0123456789abcdef", va_arg(arg, unsigned int));
	else if (c == 'X')
		i += ft_printhex("0123456789ABCDEF", va_arg(arg, unsigned int));
	else if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_printhex("0123456789abcdef", va_arg(arg, unsigned long));
	}
	return (i);
}

int ft_printf(char *s, ...)
{
	va_list arg;

	va_start(arg, s);
	int i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			++s;
			i += helper(arg, *s);
			++s;
		}
		else
		{
			i += ft_putchar(*s);
			++s;
		}
	}
	va_end(arg);
	return (i);
}
