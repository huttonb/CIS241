#ifndef __H_MY_LIBRARY__
#define __H_MY_LIBRARY__

char * createEncryptArray(char word[]);

int targetFound(char charArray[],int num, char target);

void encryptMessage(char key[], char encrypt[]);

void decryptMessage(char encrypt[], char decrypt[]);

void processInput(char* inf, char* outf, char *table, char crypt);

#endif
