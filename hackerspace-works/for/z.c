#include <stdio.h>
#include <conio.h>

int main()	{
	int s;
	printf("Please type a count: \n"); scanf("%d", &s);
	for (int i = 0; i <s; i++)
	{
		for(int j=5-1; j>0; j--){
			printf(" ");
				for (int j=0; j<=i; j++){
					printf("*");
				}
		}

		printf("\n");
	}
	
	getch();
}