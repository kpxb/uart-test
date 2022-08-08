#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define uart5 "/dev/ttyS5"

int main(int argc, char *argv[])
{
	FILE *u_fd;
	char buff[512];

	printf("Opening uart5 ...\n");

	u_fd = fopen(uart5, "r+");
	if (u_fd < 0)
	{
		printf("Fail to open uart5\n");
		exit(1);
	}
	else
	{
		printf("Success to open uart5\n");
	}

	while (1)
	{
		if (fread(buff, 512, 1, u_fd))
		{
			fwrite(buff, 512, 1, u_fd);
		}
	}
}
