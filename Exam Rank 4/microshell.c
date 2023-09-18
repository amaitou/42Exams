
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
void	put_error(char *error)
{
	while (*error)
	{
		write(2, error, 1);
		++error;
	}
}

int delimiter(char *argument)
{
	if (argument && argument[0] != ';' && argument[0] != '|')
		return (1);
	return (0);
}

int change_directory(char **ag, int i)
{
	if (i != 2)
	{
		put_error("error: cd: bad arguments\n");
		return (1);
	}
	if (chdir(ag[1]) == -1)
	{
		put_error("error: cd: cannot change directory to ");
        put_error(ag[1]);
        put_error("\n");
		return (1);
	}
	return (0);
}

int execute_command(char **ag, int flag, int *fd, char **envp, int i)
{
	int process_id;

	if (flag)
	{
		if (pipe(fd) == -1)
		{
			put_error("error: fatal\n");
			return (1);
		}
	}
	process_id = fork();
	if (process_id == 0)
	{
		ag[i] = 0;
		if (flag)
		{
			if (dup2(fd[1], 1) == -1
				|| close(fd[1]) == -1
				|| close(fd[0]) == -1)
			{
				put_error("error: fatal\n");
				return (1);
			}
		}
		if (execve(ag[0], ag, envp) == -1)
		{
			put_error("error: cannot execute ");
            put_error(ag[0]);
            put_error("\n");
			return (1);
		}
	}
	waitpid(process_id, NULL, 0);
	if (flag)
	{
		if (dup2(fd[0], 0) == -1
			|| close(fd[1]) == -1
			|| close(fd[0]) == -1)
		{
			put_error("error: fatal\n");
			return (1);
		}
	}
	return (0);
}

int main(int ac, char **ag, char **envp)
{
	int		iterator;
	int		pipe[2];

	if (ac < 2)
		return (0);
	iterator = 0;
	while (ag[iterator] && ag[++iterator])
	{
		ag += iterator;
		iterator = 0;
		while (delimiter(ag[iterator]))
			++iterator;
		if (!(strcmp(ag[0],"cd")))
			change_directory(ag, iterator);
		else if (iterator)
		{
			if (ag[iterator] && strcmp(ag[iterator], "|") == 0)
				execute_command(ag, 1, pipe, envp, iterator);
			else
				execute_command(ag, 0, pipe, envp, iterator);
		}
	}
	return (0);
}
