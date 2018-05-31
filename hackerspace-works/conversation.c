#include <stdio.h>
#include <conio.h>
#include <Windows.h>

int main()
{
	char n[30],c[30],l[30];
	Sleep(750);
	printf("What is your name? : ");
	gets(n);
	Sleep(750);
	printf("Nice to meet you %s! So, where are you from? ", n);
	gets(c);
	Sleep(750);
	printf("%s is really great!\n", c);
	Sleep(1000);
	printf("\nI have one more question. If you had a chance, Where would you like to live ? ");
	gets(l);
	Sleep(750);
	printf("I hope you'll find the chance to live at %s\n", l);
	getch();
}