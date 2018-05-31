#include <stdio.h>
#include <conio.h>

int main(){
	int n,i,k;
	printf("Lutfen sayiyi giriniz.. \n"); scanf("%d", &n);
	for(i=0; i<n; i++){
		for (k=n-1; k>i; k--){
			printf(" ");
		}

		for(k=0; k<=i; k++){
			printf("*");
		}

		printf("\n");
	}
	
	getch();
}
