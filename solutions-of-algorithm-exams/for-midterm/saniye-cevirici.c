#include <stdio.h>
#include <conio.h>

int main(){
	int saniye;
	printf("Zaman dilimini saniye olarak giriniz: "); scanf("%d", &saniye);
	int saat;
	int dakika;
	int kalan_s;
	while(saniye>=0){
	if(0<=saniye && saniye<60){
		printf("%d saniye eder.\n", saniye);
	}
	if(60<=saniye && saniye<3600){
		int dakika = saniye/60;
		int kalan_s= saniye%60;
		printf("%d dakika %d saniye eder.\n", dakika, kalan_s);
	}
	if(3600<=saniye){
		int saat = saniye/3600;
		int dakika = (saniye%3600)/60;
		int kalan_s= (saniye%3600)%60;
		printf("%d saat %d dakika %d saniye eder.\n", saat,dakika,kalan_s);
	}
	printf("Zaman dilimini saniye olarak giriniz: "); scanf("%d", &saniye);
	}
getch();
}