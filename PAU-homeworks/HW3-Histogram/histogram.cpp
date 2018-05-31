#include <stdio.h>
#include <math.h>
#include <conio.h>

void giris(int no[], int notu[], int N); 
float ortalama(int notu[], int N); 
void goruntule(int no[], int notu[], int N); 
int otele(int notu[],int N);
void siralaNot(int N, int no[], int notu[]); 
void siralaNO(int N, int no[], int notu[]); 
float standartsapma(int N,int notu[]); 
void yatayhistogram(int N, int no[], int notu[],int e[]);
void dikeyhistogram(int N, int no[], int notu[],int e[]);
void harfbulan(int N,int notu[], int e[]);

main()
{	int N;
	int OgrNo[BUFSIZ], BNotu[BUFSIZ];
	float ort,stndrtsapma;
	printf("Ogrenci sayisini giriniz: ");
	scanf("%d", &N);
	
	giris(OgrNo, BNotu, N);
	printf("\n=================================================================");
	goruntule(OgrNo, BNotu, N);
	
	ort = ortalama(BNotu, N);
	printf("\n=================================================================");
	printf("\n\n--->NOT ORTALAMASI: %5.2f\n", ort);
	
	otele(BNotu, N);
	printf("\n=================================================================");
	goruntule(OgrNo, BNotu, N);
	
	ort = ortalama(BNotu, N);
	printf("\n=================================================================");
	printf("\n\n---> OTELENEN NOT ORTALAMASI: %5.2f\n\n", ort);
	
	siralaNot(N, OgrNo, BNotu);
	
	siralaNO(N, OgrNo, BNotu);

	stndrtsapma=standartsapma(N, BNotu);
	printf("\n=================================================================");
	printf("\n\n---> OTELENMIS NOTLARIN STANDART SAPMASI :%5.2f\n", stndrtsapma);
	
	int e[] = {0,0,0,0,0,0,0,0,0,0,0};
	harfbulan(N,BNotu,e);
	
	yatayhistogram(N, OgrNo, BNotu,e);
	printf("\n\n");
	dikeyhistogram(N, OgrNo, BNotu,e);
	getch();
}

void giris(int no[], int notu[], int N)
{
	int i;
	for (i=0; i<N; i++)
	{	printf("Ogrenci no gir: ");
		scanf("%d", &no[i]);
		printf("%d numarali ogrencinin basari notunu gir : ", no[i]);
		scanf("%d", &notu[i]);
	}
}

int otele(int notu[], int N)
{	
	int toplam=0,ekle=0,bol20denbuyuk; 
	float Oort=0;
	
	for(int i=0;i<N;i++)
	{
		if(20<=notu[i])
		{
			toplam = toplam + notu[i];	
			bol20denbuyuk++; //20 DEN BUYUK SAYLARI SAYAR..
		}
	}
	//printf("toplam= %3.2d",toplam);  printf("\n20den buyuk saylar",bol20denbuyuk);   //PROGRAMIN CALISIP CALISMADIGINI GORMEK ICIN...
	
	Oort= toplam / bol20denbuyuk;  // "Oort" = 20 DEN BUYUK SAYILARIN ORTALAMASI
	
	//printf("\n\nOort= %3.2f\n",Oort); //PROGRAMIN CALISIP CALISMADIGINI GORMEK ICIN...
	
	if(Oort<50)
	{
		ekle=50-Oort;  // ekle = 30DAN BUYUK SAYILARA EKLENICEK SAYI  
		//printf("\nekle = %d\n",ekle);  //PROGRAMIN CALISIP CALISMADIGINI GORMEK ICIN...
	}
	
	for(int i=0;i<N;i++)
	{
		if(30<=notu[i])
		{
			notu[i]= notu[i] + ekle;
		}
		
		if(notu[i]>100)   // NOTLAR OTELENDIGINDE 100 NOTUNU GECMESINLER DIYE NOTU SINIRLADIM..
		{
			int kontrol;
			kontrol=notu[i]-100;
			notu[i]=notu[i]-kontrol;
		}
	}
}

void goruntule(int no[], int notu[], int N)
{
	printf("\n\t\t--Numarasi----Notu---\n");
	for (int i=0; i<N; i++)
		printf("\t\t  %8d    %3d\n" ,no[i],notu[i]);	
}

float ortalama(int notu[], int N)
{ 	
	float t;
	int i;
	t = 0;
	for (i=0; i<N; i++)
		t = t + notu[i];
	float ort = t / N;
	return ort;
}

void siralaNot(int N, int no[], int notu[]) //NOTLARA GORE SIRALAMA
{
	int i,j,kutu;
	for(i=0; i<N ;i++){
		for(j=1; j<N-i;j++){
			if(notu[j-1] > notu[j]){
				kutu = notu[j];
				notu[j] = notu[j-1]; 
				notu[j-1] = kutu;	
				kutu = no[j];	// !!NUMARALAR DA SIRALANDI..
				no[j] = no[j-1]; 
				no[j-1] = kutu;	
			}
		}
	}
	printf("=================================================================");
	printf("\n---> NOTA GORE SIRALI OGRENCI NOT'U VE OGRENCI NUMARASI <---\n");
	printf("\n\t\t--Notu-----Numarasi--\n");
	for (int i=0; i<N; i++)
		printf("\t\t%5d      %8d\n" ,notu[i],no[i]);	
}

void siralaNO(int N, int no[], int notu[]) //NOTLARA GORE SIRALAMA
{
	int i,j,kutu;
	for(i=0; i<N ;i++){
		for(j=1; j<N-i;j++){
			if(no[j-1] > no[j]){   
				kutu = no[j];
				no[j] = no[j-1]; 
				no[j-1] = kutu;	
				kutu = notu[j];   // !!NOTLAR DA SIRALANDI..
				notu[j] = notu[j-1]; 
				notu[j-1] = kutu;	
			}
		}
	}
	printf("=================================================================");
	printf("\n---> NUMARAYA GORE SIRALI OGRENCI NUMARASI'U VE OGRENCI NOTU <---\n");
	printf("\n\t\t--Numarasi----Notu---\n");
	for (int i=0; i<N; i++)
		printf("\t\t  %8d    %3d\n" ,no[i],notu[i]);
}

float standartsapma(int N,int notu[])   //Ötelenmis notlarin standart sapmasi
{					
	float stp=0,gonder;
	for(int i=0; i<N; i++)
		{
			stp = pow(notu[i]- ortalama(notu, N), 2) + stp;
	   	}
	gonder = sqrt(stp/(N));
	return gonder;
}

void harfbulan(int N,int notu[],int e[]) //Histogramda kullandigim e[] dizesini dolduran fonksiyon.
{
	int A1=0,A2=0,B1=0,B2=0,C1=0,C2=0,D1=0,D2=0,E=0,F=0;
	
	for(int i=0;i<N;i++)
	{
		if(notu[i]>=90)
			{e[0]++;}
		else if(notu[i]<=89 && notu[i]>=80)
			{e[1]++;}	
		else if(notu[i]<=79 && notu[i]>=75)
			{e[2]++;}
		else if(notu[i]<=74 && notu[i]>=70)
			{e[3]++;}
		else if(notu[i]<=69 && notu[i]>=65)
			{e[4]++;}
		else if(notu[i]<=64 && notu[i]>=60)
			{e[5]++;}
		else if(notu[i]<=59 && notu[i]>=55)
			{e[6]++;}
		else if(notu[i]<=54 && notu[i]>=50)
			{e[7]++;}
		else if(notu[i]<=49 && notu[i]>=40)
			{e[8]++;}
		else if(notu[i]<=39 && notu[i]>=0)
			{e[9]++;}
	}
	
}

void yatayhistogram(int N, int no[], int notu[],int e[])
{ 
	printf("\n\n************* YATAY HISTOGRAM ***************\n\n");
	
	printf("A1|"); 
		for(int i=0; i<e[0];i++)
			{printf("  *");}
	printf("\nA2|"); 
		for(int i=0; i<e[1];i++)
			{printf("  *");}		
	printf("\nB1|"); 
		for(int i=0; i<e[2];i++)
			{printf("  *");}
	printf("\nB2|"); 
		for(int i=0; i<e[3];i++)
			{printf("  *");}
	printf("\nC1|"); 
		for(int i=0; i<e[4];i++)
			{printf("  *");}
	printf("\nC2|"); 
		for(int i=0; i<e[5];i++)
			{printf("  *");}
	printf("\nD1|"); 
		for(int i=0; i<e[6];i++)
			{printf("  *");}
	printf("\nD2|"); 
		for(int i=0; i<e[7];i++)
			{printf("  *");}
	printf("\nE |"); 
		for(int i=0; i<e[8];i++)
			{printf("  *");}
	printf("\nF |"); 
		for(int i=0; i<e[9];i++)
			{printf("  *");}
int max=0;
	for(int i=0;i<11;i++)
	{
		if(max<e[i]) //histogramda basi ceken degeri buldurdum
			{max=e[i];}
	}			
	printf("\n--+");
	for(int i=1; i<=max;i++)
	{printf("--+");}
	printf("\n"); printf("  |");
	for(int i=1; i<=max;i++)
	{printf("  %d",i);}
}

void dikeyhistogram(int N, int no[], int notu[],int e[])
{
	printf("\n\n************* DIKEY HISTOGRAM ***************\n\n");
	int max=0;
	for(int i=0;i<11;i++)
	{
		if(max<e[i]) //histogramda basi ceken degeri buldurdum
			{max=e[i];}
	}
	
	while(1)   // Bu kod 1.odevin sonunda dikey histogran olusturmak icin kullandigim kodun aynisidir. Sadece programa adapte ettim.
	{
		printf(" %2d|",max);
		for(int i=0;i<10;i++)
		{
			if(e[i]>=max)   //En üst satirdan baslayip max a esit yada büyük varsa (en üst saatirda zaten en büyük max) |o| koyuyor [ yoksa  |  | koyar ]sonra saga dogru devam ediyor. Sonra maxi bir düsürüp alt satira iniyoruz.
			{
				printf(" * |");
			}
			else
			{
				printf("   |");
			}	
		}
		printf("\n");
		max--;
		if(max==0) //max sifirlandiginda donguden cikiyoruz.
		{
			break;
		}
	}
	printf("---+---+---+---+---+---+---+---+---+---+---+\n");
	printf("   | A1| A2| B1| B2| C1| C2| D1| D2|  E|  F|\n\n");
}
