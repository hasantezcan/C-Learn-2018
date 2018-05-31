#include <stdio.h>
#include <conio.h>

int main(){
	int i,sayi,k;
	printf("Lutfen bir sayi giriniz.. \n"); scanf("%d", &sayi);

	for(i=0; i<sayi; i++){
		for(k=0; k<sayi; k++){
			printf("*");
		}
		printf("\n");
	}
	getch();
}