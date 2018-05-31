#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

int main()
{
	while(1){
	int f_i,s_i,cn,iws,mws,bill_number,tc,money;
	char bill[BUFSIZ],name[BUFSIZ],surname[BUFSIZ],adress[BUFSIZ];
	char codkit[BUFSIZ];
	strcpy (codkit, "github.com/codkit, boratanrikulu && hasantezcan");
	printf("\n\t-WELCOME TO POWERBANK- \t\t\t\t\t\t%s", codkit);
	Sleep(1000);
	printf("\n\n");
		printf("---------------------------------------\n");
		printf("\t\t MENU\n");
		printf("---------------------------------------\n\n");
			printf("1-Processing with card\n");
			printf("2-Processing without card\n");
			printf("\t\t\tCategory: "); scanf("%d",&f_i);
			printf("---------------------------------------\n\n");
			
			if (f_i==1)	{
				printf("Please type your card number    : ", cn); scanf("%d", &cn); 
				printf("Please type your password       : ", cn); scanf("%s", &cn); printf("\n");
				printf("1-Money Transfer\n"); printf("2-Bills Payments\n"); printf("3-Credit Application\n");
				printf("\t\t\tCategory: "); scanf("%d",&s_i);
				printf("---------------------------------------\n\n");
				if (3>=s_i && s_i>=1) {
					switch(s_i)	{
						case 1:
							printf("IBAN of the account which you will send: "); scanf("%d", &iws);
							printf("Amount of the money which will be send : "); scanf("%d", &mws);
							/* IBAN numaralarına sınır getir */
						if (iws==1){
								Sleep(1200); printf("\nPlease wait"); Sleep(700);printf(", the money is sending "); Sleep(900);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");
								printf("\nThe money has been sent. ");getch();
								printf("\nPlease push enter to return main menu ");getch(); for (int i = 1; i <= 50; i++){printf("\n");};
								}
						case 2:
							printf("The bill which will be paid: "); scanf("%s", &bill);
							printf("Equipment number: "); scanf("%d", &bill_number);
							Sleep(1200); printf("\nPlease wait"); Sleep(700);printf(", the process is in progress"); Sleep(900);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");
							printf("\n%s bill has been paid. ", bill);getch();
							printf("\nPush enter to return main menu ");getch(); for (int i = 1; i <= 50; i++){printf("\n");};
						case 3:
							printf("Name: "); scanf("%s", &name);
							printf("Surname: "); scanf("%s", &surname);
							printf("Identification Number: "); scanf("%d",&tc);
							printf("Adress: "); scanf("%s", &adress);
							printf("How much money do you need? "); scanf("%d", &money);
							Sleep(1200); printf("\nPlease wait"); Sleep(700);printf(", Your request is sending."); Sleep(900);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");
							printf("\nThe request has been sent. ");getch();
							printf("\nPush enter to return main menu ");getch(); for (int i = 1; i <= 50; i++){printf("\n");};
					}
				}
				else printf("Please type between 1-3.\n");
				printf("Push enter to return main menu "); for (int i = 1; i <= 50; i++){printf("\n");};
			}
	
			else if(f_i==2)	{
				printf("1-Exam Payments\n"); printf("2-Bills Payments\n"); printf("3-Helping\n");
				printf("\t\t\tCategory: "); scanf("%d",&s_i);
				printf("---------------------------------------\n\n");
				if (3>=s_i && s_i>=1) {
					switch(s_i)	{
						case 1:
							printf("Which exam will you pay for it? "); scanf("%s", &money);
							printf("Identification Number: "); scanf("%d", &tc);
							printf("Please type your acoount number you will pay with it: "); scanf("%s", &cn);
							printf("Please type your password: "); scanf("%s", &cn); printf("\n");
							Sleep(1200); printf("\nPlease wait"); Sleep(700);printf(", the process is in progress"); Sleep(900);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");
							printf("\n%s has been paid. ", bill);getch();
							printf("\nPush enter to return main menu ");getch(); for (int i = 1; i <= 50; i++){printf("\n");};
						case 2:
							printf("The bill which will be paid: "); scanf("%s", &bill);
							printf("Equipment number: "); scanf("%d", &bill_number);
							Sleep(1200); printf("\nPlease wait"); Sleep(700);printf(", the process is in progress"); Sleep(900);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");
							printf("\n%s bill has been paid. ", bill);getch();
							printf("\nPush enter to return main menu ");getch(); for (int i = 1; i <= 50; i++){printf("\n");};
						case 3:
							printf("404 not found."); getch();
							printf("\nWe cannot help you right now. Please try again later. God helps you.");getch();
							printf("\nPush enter to return main menu ");getch(); for (int i = 1; i <= 50; i++){printf("\n");};
					}
				}
				else printf("Please type between 1-3.\n");
				for (int i = 1; i <= 50; i++){printf("\n");};
			}
			else 
				printf("Please type 1 or 2.\t\t  ");
				Sleep(1200);printf("\nPush enter to return main menu\t  ");getch(); Sleep(700);printf("\nReturning to homepage"); Sleep(900);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");Sleep(700);printf(".");
				for (int i = 1; i <= 50; i++){printf("\n");};	
	}
}

