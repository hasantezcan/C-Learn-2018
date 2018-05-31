#include <stdio.h>
#include <stdlib.h>
void durum1(int x);
void durum2(int x);
void durum3(int x);
char sorgulama();
void temizle();
void uyari();

int main(){
	int x;
	char sorgu;
	do{
		printf("Hosgeldiniz.. Lutfen \"x\" degerini giriniz.. (x>0)\n");
		printf("x = "); scanf("%d", &x);
		if(x>=20)
			durum1(x);
		else if(x>=10)
			durum2(x);
		else if(x>0)
			durum3(x);
		else
			uyari();
		sorgu = sorgulama(); temizle();
	} while(sorgu == 'e' || sorgu == 'E');
	return 0;
}

void durum1(int x){
	temizle();
	float toplam = 0.0;
	for(int i=2; i<=2*x; i+=2)
		toplam += 1/float(i);
	printf("F(x) = 1/2 + 1/4 + 1/8 + ...... + 1/2x\n");
	printf("fonksiyonuna dayanarak sonuc = %5.2f", toplam);
}

void durum2(int x){
	temizle();
	int toplam = 0;
	for(int i=1; i<=(2*x)+1; i+=2)
		toplam += i;
	printf("F(x) = 1 + 3 + 5 + ...... + 2x+1\n");
	printf("fonksiyonuna dayanarak sonuc = %d", toplam);
}

void durum3(int x){
	temizle();
	int toplam = 1;
	for(int i=x; i>0; i--)
		toplam *= i;
	printf("F(x) = x!\n");
	printf("fonksiyonuna dayanarak sonuc = %d", toplam);
}

char sorgulama(){
	printf("\n\nTekrar bir \"x\" degeri girecek misiniz (E/e)? ");
	char sorgu; sorgu = getchar();
	if ( sorgu == '\n') sorgu = getchar();
	return sorgu;
}

void temizle(){
	system("clear||cls");
}

void uyari(){
	printf("Lutfen programin kurallarina uygun girdi yapiniz.\n");
}