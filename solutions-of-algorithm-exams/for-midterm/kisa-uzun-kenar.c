#include <stdio.h>
#include <conio.h>

int main(){
	int uzun,kisa;
	printf("Uzun kenar yildiz adedini giriniz: "); scanf("%d", &uzun);
	printf("Kisa kenar yildiz adedini giriniz: "); scanf("%d", &kisa);

	for(int i=0; i<kisa; i++){
		for(int j=0; j<i; j++){
			printf(" ");
		}
		for(int j=0; j<uzun; j++){
			printf("*");
		}
		printf("\n");
	}
	getch();
}