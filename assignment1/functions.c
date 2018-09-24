#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

int targetFound(char charArray[], int num, char target);

char* createEncryptArray(char word[]){
  int length = strlen(word);
  int i;
  int c;
  int g;
  int repeat;
  char* newWord;
  int removedChars = 0;
  char startChar = 'A';
  char swapChar;
  newWord = (char*)malloc(27 * sizeof(char));
  for(i = 0; i < 26; i++){
    newWord[i] = startChar;
    startChar++;
  }
  for(i = 0; i < length; i++){
    for(g = i+1; g < length; g++){
      if(word[i] == word[g] && word[i] != ' '){
      //If the target is found it shifts every letter after it one to the left.
	for(c = g; c < length; c++){
	  word[length] = ' ';
	  word[c] = word[c+1];
	}
	removedChars++;
	g--;
      }
    }
  }
  //Same as before but check for repeats from the cleaned word array with the
  // newWord array.
  for(i = 0; i < length; i++){
    for(g = 0; g < 26; g++){
      if(word[i] == newWord[g] && word[i] != ' '){
	for(c = g; c < 26; c++){
	  newWord[26] = ' ';
	  newWord[c] = newWord[c+1];
	  
	}
      }
    }
  }
  //This forloop reverses the alphabet array newWord, so that it goes from Z to A
  for(i = 0; i < 13; i++){
    swapChar = newWord[i];
    newWord[i] = newWord[26-i-1];
    newWord[26-i-1] = swapChar;
  }
  for(i = 0; i < (length - removedChars); i++){
    newWord[i] = word[i];
  }
  newWord[26] = '\0';
  return newWord;

}

int targetFound(char charArray[], int num, char target){
  int i;
  for(i = 0; i < num; i++){
    if(charArray[i] == target)
      return i;
  }

  return 0;
}

void encryptMessage(char key[], char encrypt[], int size){
  
  int eLength = size;
  //Not really but 27th char is /0
  int kLength = 26;
  int i;
  int charNum;
  for(i = 0; i < eLength; i++){
    if(isalpha(encrypt[i])){
	charNum = (encrypt[i] - 'A');
	encrypt[i] = key[charNum];
      }   
  }
 
  return;
}

void decryptMessage(char key[], char decrypt[], int size){
  int dLength = size;
  int kLength = 26;
  int i;
  char charNum;
  for(i = 0; i < dLength; i++){
    if(isalpha(decrypt[i])){
      charNum = (targetFound(key, 26, decrypt[i])+'A');
	decrypt[i] = charNum;
      }

  }

}

void processInput(char* inf, char* outf, char *table, char crypt){
  char *message1;
  int i = 0;
  FILE *fp;
  char c;
  int size;

  fp = fopen(inf, "r");
  if (fp == NULL){
    printf("File could not be opened");
    return;
  }
  //I don't know why I added 2000, I had a memory corruption,
  //but wasn't sure at what point it was corrupting and I'm really tired
  //I'm sorry for the bad code professor.
  message1 = malloc(sizeof(fp) * sizeof(char)+200);
  while(fscanf(fp, "%c", &c) != EOF){
    message1[i] = c;
    i++;
  }
  message1[i] = '\n';

    while(message1[i]){
    if(isalpha(message1[i]))
      message1[i] =(toupper(message1[i]));
    else
      message1[i] = ' ';
    i++;
  }  
  size = i;
  i = 0;
  
  if(crypt == 'e'){
    encryptMessage(table, message1, size);
  }
  else if(crypt == 'd'){
    decryptMessage(table, message1, size);
  }

  write_file(outf, message1, size);
  free(message1);
  fclose(fp);
  return;
  
}

int write_file(char* filename, char *buffer, int size){
	FILE *fp;
	fp = fopen(filename, "w");
	fputs(buffer, fp);
	fclose(fp);
	return 0;
}
