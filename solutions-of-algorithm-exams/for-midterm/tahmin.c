#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(){
	int x,k,i;
	srand(time(NULL));
	x = rand()%101; /*101, 0-100 arasında demek*/
	
	for(i=1; x!=k; i++){
		printf("Uretilen sayiyi tahmin ediniz: [0-100 arasında]"); scanf("%d", &k);
		if (100>=k && k>=0){
			if ( k > x){
				printf("girdiginiz sayi buyuk... \n");
			}
			if ( k < x){
				printf("girdiginiz sayi kucuk... \n");
			}
		}
		else {
			printf("Lutfen sadece 0-100 arasinda bir tahminde bulunun.\n");
		}
	}
	printf("Sayiyi %d denemede buldunuz.", i); 
	getch();
}