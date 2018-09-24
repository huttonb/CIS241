#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt(char ch, int k);

int main(int argc, char* argv[])
{  
	int choice, i, len;
	int courtney = 0;
	char ch;
	char* input;
	char*  key_arr;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}
	
	choice = atoi(argv[1]);
	key_arr = (argv[2]);

	len = strlen(argv[2]);
	input =  malloc (len * sizeof(int));

//	printf("%s\n", input);
		
	for(i = 0; i < len; i++){
		if(key_arr[i] <= 'Z')
			input[i] = (int)key_arr[i] - 65;
		else
			input[i] = (int)key_arr[i] - 97;
	
	}

	if (choice == 2){
		for(i = 0; i < len; i++){
			input[i] = -1 * (input[i]);
		}
	}
		
    	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}

	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt(ch, input[courtney % len]));
		courtney++;
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';
	
	return ch;
}

