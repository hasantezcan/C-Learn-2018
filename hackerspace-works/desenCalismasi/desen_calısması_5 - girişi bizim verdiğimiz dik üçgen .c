#include <stdio.h>
#include <conio.h>

main()
{
	int sayi,i,satir;
	
	printf("bir sayi giriniz=");
	scanf("%d" ,&sayi);
	
	for(i=1; i<=sayi; i++)
	{
		for(satir=1; satir<=i; satir++)
			{
				printf("*");
			}
		printf("\n");
	}
	getch();
}
