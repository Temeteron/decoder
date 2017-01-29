/********************************************************
 *                                                      *
 *      			Dimitris Greasidis                  *
 *                                                      *
 *				Email: temeteron@gmail.com				*
 *														*
 *      		Github Username: Temeteron         		*
 *                                                      *
 *      			Decode an encrypted       			*
 *      		  file with key-distance	            *
 *            			                       			*
 *                                                      *
 ********************************************************/
#include<stdio.h>
#define N 1024 	/* Number of characters to read */
#define K 95 	/* Number of printable characters in ASCII */

int main (int argc, char* argv[]){
	char c, Words[N], decodedWords[N] ;
	int i, key, lengthWords, times_of_view[K], pos_element_max_hits;

	/* Initialize array that contains the number of hits */
    for (i = 0; i <= K - 1; i++){
    	times_of_view[i] = 0;
    }
    
    /* Read and save char in the array, count number of hits and save */
	c = getchar();
	for(i = 0; c != EOF && i < N; i++){
		Words[i] = c;
		times_of_view[c-32]++;
		c = getchar();
	}

	lengthWords = i - 2;

	/* Find char with most hits */
	pos_element_max_hits = 0;
	for (i = 1; i<K; i++){
		if (times_of_view[i] > times_of_view[pos_element_max_hits]){
			pos_element_max_hits = i;
		}
	}
	
	/* Decode */
	key = pos_element_max_hits + 32 - ' ';
	printf("KEY: %d\n\n", key);
	
	printf("TEXT: ");
	for (i=0;  i < lengthWords; i++){
		if ((int)Words[i] >= 32 && (int)Words[i] <= 126){
			decodedWords[i] = '~' - (('~' - Words[i] + key) % ('~' - ' ' + 1));
		}
		else{
			decodedWords[i] = Words[i];
		}
		printf("%c",decodedWords[i] );
	}
	printf("\n\n");
	
	return 0;
}
