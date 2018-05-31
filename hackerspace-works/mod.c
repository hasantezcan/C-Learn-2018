#include <stdio.h>
#include <conio.h>

int main()
{
	int x,bolen,remainder,bolum;
	while(1)
	{
		printf("Please type first count!\t", x);
			printf("\t"); scanf("%d", &x);
		printf("Please type second count!\t", bolen);
			printf("\t"); scanf("%d", &bolen);
		remainder=x%bolen;
		bolum=x/bolen;
		printf("\t\t\t  Result = %d/%d  =  %d.%d+%d\n\n\n", x,bolen,bolen,bolum,remainder);
	}
}