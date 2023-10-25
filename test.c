#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


int main()
{
	char **jebala;
	int i, j = 0;

	jebala = (char **)calloc(4, sizeof(char *));
	jebala[0] = strdup("123");
	jebala[1] = strdup("456");
	jebala[2] = strdup("789");
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			write (STDOUT_FILENO, &jebala[j][i], 1);
			i++;
		}
		j++;
	}

}