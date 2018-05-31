#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int main()
{
	char n[40],s[40];
	int in;
	Sleep(1000); printf("Welcome to RDS [Result Declare System]\n");
	Sleep(1000); printf("Please type your informations below, to know your result.\n\n");
		Sleep(1000); printf("\tName: "); gets(n);
		Sleep(1000); printf("\tSurname: "); gets(s);
		Sleep(1000); printf("\tIdentification Number: "); scanf("%d", &in);
	Sleep(1200); printf("\nPlease wait"); Sleep(700);printf(", scanning results "); Sleep(900);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");
	Sleep(1200); printf("\nCongratulations %s %s, You won Pamukkale University!\n", n,s);
	Sleep(2000); printf("Please follow https://pau.edu.tr to know date of registration.");
	getch();
}