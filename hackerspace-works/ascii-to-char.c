#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	int c;
	while(1)
	{
		Sleep(500);
		printf("Please type your ASCII code!\n");
			printf("The ASCII code:");scanf("%d", &c);
		Sleep(500);
		printf("The result of your ASCII code is %c\n\n\n", c);
	}
}