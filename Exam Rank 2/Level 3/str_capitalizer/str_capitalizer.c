
#include <unistd.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int ft_isalpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

void lowercase(char *s)
{
	while (*s)
	{
		if (*s >= 'A' && *s <= 'Z')
			*s += 32;
		++s;
	}
}

void ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		++s;
	}
	write(1, "\n", 1);
}

void	ft_strcapitalize(char *str)
{
	int	i;

	lowercase(str);
	i = 0;
	if (ft_isalpha(str[i]))
		str[i] -= 32;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i - 1]) && ft_isalpha(str[i]))
			str[i] -= 32;
		++i;
	}
	ft_putstr(str);
}

int main(int ac, char **ag)
{
	if (ac > 1)
	{
		int i = 1;
		while (i < ac)
		{
			ft_strcapitalize(ag[i]);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
