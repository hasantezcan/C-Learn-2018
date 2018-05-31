#include <stdio.h>
#include <conio.h>

main()
{
	int i,j;
	
	for(i=1; i<=5; i++)
	{
		for(j=5; j>=i; j--)
			printf("*");
	
	
		printf("\n");
	}
	

}
