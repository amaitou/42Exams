
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int len(char *s)
{
	if (!s)
		return 0;
	int i = 0;
	while (*s)
	{
		++s;
		++i;
	}
	return (i);
}

int chr(char *s, char c)
{
	if (!s)
		return (0);
	while(*s != c && *s)
		++s;
	if (*s)
		return (1);
	return (0);
}

char *join(char *a, char *b)
{
	char *p = malloc(sizeof(char) * (len(a) + len(b)) + 1);
	if (!p)
		return (NULL);
	int i = 0;
	int j = 0;
	while (a && a[i])
	{
		p[i] = a[i];
		++i;
	}
	while (b[j])
	{
		p[i] = b[j];
		++i;
		++j;
	}
	p[i] = '\0';
	free(a);
	return p;
}

char *line(char *s)
{
	char *line;
	int i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		++i;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		++i;
	}
	if (s[i] == '\n')
	{
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';
	return line;
}

char *del(char *s)
{
	char *stash;
	int i = 0;
	int j = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		++i;
	if (!s[i] || (s[i] == '\n' && !s[i+1]))
	{
		free(s);
		return (NULL);
	}
	stash = malloc(sizeof(char) * (len(s) - i));
	if (!s)
		return (NULL);
	++i;
	while (s[i])
	{
		stash[j] = s[i];
		++i;
		++j;
	}
	stash[j] = '\0';
	free(s);
	return stash;
}

char *res(int fd, char *s)
{
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	int rd = 1;
	while (rd > 0 && !chr(s, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
		{
			free(buffer);
			return (s);
		}
		buffer[rd] = '\0';
		s = join(s, buffer);
	}
	free(buffer);
	return (s);
}

char *get_next_line(int fd)
{
	char *l;
	static char *stash;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return NULL;
	stash = res(fd, stash);
	l = line(stash);
	stash = del(stash);
	return (l);
}

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		printf("failed to open the path file\n");
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
