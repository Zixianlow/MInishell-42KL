// pipex.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0644);

#include "srcs/minishell.h"
#include <fcntl.h>

int main()
{
	int fd;
	int fd2;

	fd2 = open("u", O_RDWR, 0644);
	fd = open("s", O_RDONLY, 0644);
	// fd = open("unuse.c", O_TRUNC | O_CREAT | O_RDWR, 0644); > 
	// fd = open("unuse.c", O_CREAT | O_RDWR, 0644); >
	if (fd2 < 0)
		open("u", O_CREAT | O_RDWR, 0644);

	dup2(fd2, 1);
	int r = 1;
	char c;
	while (r)
	{
		r = read(fd2, &c, 1);
		if (r <=0)
			break;
	}
	int s = 1;
	char ch;
	while (s)
	{
		s = read(fd, &ch, 1);
		if (s <=0)
			break;
		printf("%c", ch);
	}
	// printf("here");
}
				<		>		<<		>>
fd [in]		 filename  NULL	 	NULL   NULL
fd [out]	   NULL	 filename   NULL  filename