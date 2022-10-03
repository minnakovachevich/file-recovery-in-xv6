#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
	char mat[64][DIRSIZ + 1];
	int result;


	if(argc == 1)
		result = lsdel(".",mat);
	
	else if(argc == 2)
		result = lsdel(argv[1],mat);

	if(result == 0)
		printf("Nema ni jednog obrisanog fajla u ovom direktorijumu.\n");

	if(result == -1)
		printf("Navedena putanja nije validna.\n");

	for(int i = 0; i < result; i++)
	{
		printf("%s\n", mat[i]);
	}
	exit();
}
