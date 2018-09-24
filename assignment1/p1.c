#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "functions.h"

int main(char argc, char* argv[]){
  char* fin = argv[3];
  char* fout = argv[4];
  char* key = argv[2];
  char* table;
  int i =0;
  char crypt = (argv[1])[0];
    while(key[i]){
      key[i] =(toupper(key[i]));
      i++;
    }
    table = createEncryptArray(key);
    processInput(fin, fout, table, (argv[1])[0]);
   
  free(table);
  return 0;

}
