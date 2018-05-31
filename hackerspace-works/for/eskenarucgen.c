#include <stdio.h>

int main(){
	int s = 5;
	printf("    *\n");
	for(int i=0; i<5; i++){

		for(int j=4; j>i; j--)
			printf(" ");
		for(int j=0; j<=i; j++)
			printf("*");
		for(int j=0; j<=i; j++)
			printf("*");
		printf("\n");

	}
	return 0;
}