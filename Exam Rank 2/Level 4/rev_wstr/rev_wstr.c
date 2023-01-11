
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
			p[j][k] = '\0';
			++j;
		}
	}
	p[j] = NULL;
	return (p);
}

void ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		++s;
	}
}

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int s = word_len(ag[1]) - 1;
		char **p = ft_split(ag[1]);
		while (s >= 0)
		{
			ft_putstr(p[s]);
			if (!(s - 1 < 0))
				write(1, " ", 1);
			--s;
		}
	}
	write(1, "\n", 1);
	return (0);
}
