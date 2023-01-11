
#include <unistd.h>
#include <stdlib.h>

void ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		++s;
	}
}

int ft_spaces(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int word_len(char *s)
{
	int i = 0;
	int c = 0;
	while (s[i])
	{
		while (ft_spaces(s[i]) && s[i])
			++i;
		if (s[i])
		{
			while (!ft_spaces(s[i]) && s[i])
				++i;
			++c;
		}
	}
	return c;
}

int letters_len(char *s, int p)
{
	int c = 0;
	while (!ft_spaces(s[p]) && s[p])
	{
		++p;
		++c;
	}
	return (c);
}

char    **ft_split(char *str)
{
	char **p = malloc(sizeof(char *) * (word_len(str) + 1));
	if (!p)
		return (NULL);
	int i = 0;
	int j = 0;
	int k;
	while (str[i])
	{
		k = 0;
		while (ft_spaces(str[i]) && str[i])
			++i;
		if (str[i])
		{
			p[j] = malloc(sizeof(char) * (letters_len(str, i) + 1));
			if (!p[j])
				return (NULL);
			while (!ft_spaces(str[i]) && str[i])
			{
				p[j][k] = str[i];
				++k;
				++i;
			}
			++j;
		}
	}
	p[j] = NULL;
	return (p);
}

int main(int ac, char **ag)
{
	if (ac > 1)
	{
		char **p = ft_split(ag[1]);
		int size = word_len(ag[1]) - 1;
		int i = 1;
		while (i < size + 1)
		{
			ft_putstr(p[i]);
			write(1, " ", 1);
			++i;
		}
		ft_putstr(p[0]);
	}
	write(1, "\n", 1);
}
