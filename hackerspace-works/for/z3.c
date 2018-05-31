#include <stdio.h>

int main(){
	int n,i,k,j,t;
	printf("Lutfen sayiyi giriniz.. \n"); scanf("%d", &n);
	for(i=0; i<n; i++){
		for (k=n-1; k>=i; k--){
			printf("*");
		}

		for(k=0; k<i; k++){
				printf(" ");
		}

		for(k=0; k<i; k++){
			printf(" ");
		}

		for (k=n-1; k>=i; k--){
			printf("*");
		}
		printf("\n");
	}

	for(i=n; i>=0; i--){
		for (k=n-1; k>=i; k--){
			printf("*");
		}

		for(k=0; k<i; k++){
			printf(" ");
		}

		for(k=0; k<i; k++){
			printf(" ");
		}

		for (k=n-1; k>=i; k--){
			printf("*");
		}
		printf("\n");
	}
}
