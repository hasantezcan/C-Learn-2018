#include <stdio.h>
#include <conio.h>

int main()	
{
	char karakter;
	int sayi;
	printf("karekter ve sayi giriniz: ");
	scanf("%c%d", &karakter, &sayi);
	
	for(int satir=0; satir<sayi; satir++)
	{
		for(int bosluk=0; bosluk<satir; bosluk++)
		printf(" ");
		
		for(int simge=0; simge<sayi-satir; simge++)
		printf("%c", karakter);
		printf("\n");
	}
}

