#include <stdio.h>
#include <conio.h>

int main(){
	int x;
	printf("Lutfen sayiyi giriniz.\n"); scanf("%d", &x);
	if (10 > x && x >= 8)
	{
		printf("A\n");
	}
	if (8 > x && x >= 6)
	{
		printf("B\n");
	}
	if (6 > x && x >= 4)
	{
		printf("C\n");
	}
getch();
}