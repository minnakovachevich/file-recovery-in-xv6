#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
	

	if(argc < 2)
	{
		printf("Wront number of arguments\n");
		return -1;
	}
	int result = rec(argv[1]);

		if(result == -1)
		 	printf("Nije naveden parametar na komandnoj liniji."); 
		
		else if(result == -2)
			printf("Roditeljski direktorijum za navedenu datoteku nije validan"); 
		
		else if(result == -3)
			printf("Ne postoji obrisana datoteka sa navedenim nazivom"); 

		else if(result == -4)
			printf("Inode datoteke je iskoriscen za nesto drugo"); 

		else if(result == -5)
			printf("Neki blok je  iskoriscen za nesto drugo"); 
		
		else
			printf("Fajl uspesno oporavljen.");
	
	exit();
}
