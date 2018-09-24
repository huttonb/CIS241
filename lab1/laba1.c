#include <stdio.h>
#include <ctype.h>
#define MAXSTRING 100
int main () {
char ch;
char word[MAXSTRING];
int sequences;
int words;
int i = 0;
puts ("Enter text (Ctrl-D to quit).");
while ( ch = getchar(), ch != EOF ) {	
	word[i] = ch;
	i = i + 1;
}

int stillword = 0;
int symbseq = 0;
int a;
for( a = 0; a < i; a = a + 1){
	if((isalpha(word[a]) != 0) || (isdigit(word[a]) != 0) || (word[a] == 95)){
		if(stillword == 0){
			words = words + 1;
			stillword = 1;
			symbseq = 0;
		}
	}
	else if(isspace(word[a]) != 0){
		symbseq = 0;
		stillword = 0;
	}
	else{
		if(symbseq == 0){
			sequences = sequences + 1;
			stillword = 0;
			symbseq = 1;
		}

	}	


}

printf("\n Words are: %i ", words);
printf( "\n symbol sequences are: %i \n", sequences);

return 0;
}
