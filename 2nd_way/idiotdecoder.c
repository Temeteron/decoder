/* Dimitrios Greasidis AM : 1624 */
#include<stdio.h>
#define N 1024
#define K 95 /*arithmos ektupwsimwn xaraktirwn tou pinaka ASCII*/

int main (int argc, char* argv[]){
	char c, Words[N], characters_of_ASCII[K], number_to_char, decodedWords[N] ;
	int i, j, key, distance, lengthWords, times_of_view[K], thesi_stoixeiou_megistis_emfanisis;
//1o stadio	
/*dimiourgia pinaka me tous ektupwsimous xaraktires tou pinaka ASCII*/
	for (j = 0, i = 32; i < 127; j++, i++){
        number_to_char = i;
        characters_of_ASCII[j] = number_to_char;
    }
/*Midenismos pinaka p periexei to plithos emfanisewn twn xaraktirwn*/
    for (i = 0; i <= K - 1; i++){
    	times_of_view[i] = 0;
    }
    	
    
    
/* anagnwsi kai kataxwrisi xaraktirwn se pinaka kai kataxwrisi arithmou emfanisewn tous sto keimeno*/
	
	c = getchar();
	for(i = 0; c != EOF && i < N; i++){
		Words[i] = c;
		for (j = 0; j <= K-1; j++){
			if (c == characters_of_ASCII[j]){
				times_of_view[j]++;
			}
		}
		c = getchar();
	}
	
	lengthWords = i - 2;

//2o stadio
	thesi_stoixeiou_megistis_emfanisis = 0;
	for (i = 1; i<K; i++){
		if (times_of_view[i] > times_of_view[thesi_stoixeiou_megistis_emfanisis]){
			thesi_stoixeiou_megistis_emfanisis = i;
		}
	}
	
//3o stadio
	key = characters_of_ASCII[thesi_stoixeiou_megistis_emfanisis] - ' ';
	printf("KEY: %d\n\n", key);
	
	 		
/*apostasi + apo ~ sto pinaka ASCII : xrisi autis tis apostasis gia tin apokodikopihsh twn stoixeiwn pou einai stis theseis 32 - 43*/
	distance = '~' - '+';	
	
	printf("TEXT: ");
	for (i=0;  i < lengthWords; i++){
		if ((int)Words[i] >= 32 && (int)Words[i] <= 126){
			if (Words[i] - ' ' - key < 0){
				decodedWords[i] = Words[i] + distance;
			}
			else{
				decodedWords[i] = Words[i] - key;
			}
		}
		else{
			decodedWords[i] = Words[i];
		}
		printf("%c",decodedWords[i] );
		
	}
	printf("\n\n");
	
	return 0;
}
