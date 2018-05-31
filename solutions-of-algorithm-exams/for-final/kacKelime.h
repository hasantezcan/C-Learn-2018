#include <string.h>

int kacKelime(char *sentence){
	int control=0;
	int len = strlen(sentence);
	if(sentence[0]==' '){ // cumlenin basinda bosluk varsa control bir azaltilir
		control--;
	}
	for(int i=0; i<len; i++){
		if(sentence[i]==' ' && sentence[i+1]!=' '){ // (bosluk)(HARF) şeklindeki her birlesimi bir kelime sayar
			control++;
		}
	}
	if (sentence[len-1]==' '){ // cumlenin sonun bosluk varsa control bir azaltilir
		control--;
	}
	control++;
	return control;
}