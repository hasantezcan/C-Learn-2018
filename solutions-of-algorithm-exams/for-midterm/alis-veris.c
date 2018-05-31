#include <stdio.h>

int main(){
	int fiyat, indirim, tutar;
	printf("Alisveris miktarini giriniz: "); scanf("%d", &fiyat);
	if(0<=fiyat && fiyat<=50){
		indirim = fiyat*0.02;
	}
	else if(50<fiyat && fiyat<=100){
		indirim = 50*0.02 + (fiyat-50)*0.03;
	}
	else if(100<fiyat && fiyat<=250){
		indirim = 50*0.02 + 50*0.03 + (fiyat-100)*0.04;
	}
	else if(250<fiyat){
		indirim = 50*0.02 + 50*0.03 + 150*0.04 + (fiyat-250)*0.05;
	}
	printf("Alisveris miktari: %d\n", fiyat);
	printf("Indirim miktari: %d\n", indirim);
	printf("Odeme miktari: %d\n", fiyat-indirim);
}