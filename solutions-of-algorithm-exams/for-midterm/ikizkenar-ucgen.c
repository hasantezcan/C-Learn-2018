#include <stdio.h>
#include <conio.h>
int main(){
	int kenar;
	printf("Ikizkenar ucgenin kenar uzunlugu: ");
	scanf("%d", &kenar);

	for(int i=0; i<kenar; i++){
		for(int k=0; k<i; k++){
			printf(" ");
		}
		for(int j=kenar; j>i; j--){
			printf("*");
		}
		printf("\n");
	}
getch();
}