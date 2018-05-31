#include <stdio.h>
#include <conio.h>
#include <windows.h>

//This program shows us how to use i++ or ++i
int main()
{
	int x,y,T;
	while(1)
	{
			printf("Please type a count! ");
				printf("\t\t"); scanf("%d", &x);
			printf("Please type another count! ");
				printf("\t"); scanf("%d", &y);
		Sleep(500);
			printf("We added one to X (before the process)\t= \t%d\n", ++x);
			T=x+y;
		Sleep(500);
			printf("We added one to Y (after the process)\t= \t%d\n", y++);
		Sleep(500);
			printf("The total of the counts\t\t\t= \t%d\n\n", T);
	}
}
