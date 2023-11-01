#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

void change_me(int *i)
{
	*i = 8;
}

int main()
{
	int i = 7;

	change_me(&i);
	printf ("%d", i);
}
