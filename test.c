// pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);

#include "srcs/minishell.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	// int fd[2];
	// int fd2;

	// fd2 = open("u", O_RDWR, 0644);
	// fd = open("s", O_RDONLY, 0644);
	// fd2 = open("u", O_APPEND | O_CREAT | O_RDWR, 0644);
	// fd = open("unuse.c", O_CREAT | O_RDWR, 0644); >
	// if (fd2 < 0)
	// 	open("u", O_CREAT | O_RDWR, 0644);
	// dup2(fd2, 1);
	// printf("herere");
	// int r = 1;
	// char c;
	// while (r)
	// {
	// 	r = read(fd2, &c, 1);
	// 	if (r <=0)
	// 		break;
	// 	printf("%c", c);
	// }
	// int s = 1;
	// char ch;
	// while (s)
	// {
	// 	s = read(fd, &ch, 1);
	// 	if (s <=0)
	// 		break;
	// 	printf("%c", ch);
	// }
	// printf("here");
	// int fd[2];
	// pipe(fd);
	// int pid;
	// int i = 0;

	// 	while (i < 2)
	// 	{
	// 		pid = fork();
	// 		if (pid == 0)
	// 		{
	// 			if (i == 0)
	// 			{
	// 				printf("i = 0;\n");
	// 				exit(0);
	// 			}
	// 			if (i == 1)
	// 			{
	// 				dup2(1, 1);
	// 				printf("i = 1;\n");
	// 				exit(0);
	// 			}
	// 		}
	// 		// wait(0);
	// 		i++;
	// 	}
		
	int fd[2];
	// int fd2[2];

	pipe(fd);
	// pipe(fd2);

	pid_t	pid;
	pid_t	pid2;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		execlp(av[1], av[1], NULL);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[1], 1);
		execlp(av[1], av[1], NULL);
	}
	close(fd[1]);
	close(fd[0]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
}
// 				<		>		<<		>>
// fd [in]		 filename  NULL	 userinput  NULL
// fd [out]	   NULL	 filename   NULL  filename

// 1 pipe

// fork
// id==0
// 	dup(fd[0][1], 1)
// 	execve
// fork
// id==0
// 	dup(fd[0][0], 0)
// 	execve

// 2 pipe

// fork
// id==0
// 	dup(fd[0][1], 1)
// 	execve
// fork
// id==0
// 	dup(fd[0][0], 0)
// 	dup(fd[1][1], 1)
// 	execve
// fork
// id==0
// 	dup(fd[1][0], 0)
// 	execve