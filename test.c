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
	char *ala;
	int fd;
	int i = 0;

	ala = (char *)calloc(150, sizeof(char));
	fd = open("./map2.ber", O_RDONLY);
	read (fd, ala, 149);
	while (ala[i])
	 write (STDOUT_FILENO, &ala[i++], 1);
	return (0);
}
