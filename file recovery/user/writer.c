#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fcntl.h"

int
main(int argc, char *argv[])
{		
	if(argc != 3)
		fprintf(2,"Wront number of arguments.");
	
	int fd = open( argv[1], O_CREATE | O_WRONLY);
	
	char str[atoi(argv[2])];
	memset(str,'m',atoi(argv[2]));	
	write(fd,str,atoi(argv[2]));
	close(fd);
	exit();
}
