#include <string.h>
void cumleninTersi(char *sentence, char *sentence_copy){

	int len = strlen(sentence);
	for(int i=0; i<len; i++){
		sentence_copy[i]=sentence[len-1-i];
	}
	sentence_copy[len]='\0';
}