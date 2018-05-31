#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

main()
{
	printf("bir cumle giriniz");
	
	char cumle[100];
	
	gets(cumle);
	
	int sayac = 0;
	
	for(int i=0; i<strlen(cumle); i++)
	{
		if(tolower(cumle[i])== 'a')
			sayac++;
	}
 
}
