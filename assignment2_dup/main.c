/**
Author: Bryce Hutton
Date: 3/15/2018
**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"

void printCmds();

int main(char argc,char* argv[]){
  char dataFile[] = "invList.dat";
  char str[20];
  int i;
  product * head = NULL;
  char ans[20];
  float till;
  printf("\n\nWelcome to Bryce Hutton Grocery Store!\n");
  printf("=========================================================\n");
  printf("1:Add product to store     2:Purchase product from store\n");
  printf("3:Check price of product   4:Show products in store\n");
  printf("5:Remove product           6:Find product in store\n");
  printf("7:Inventory                8:Exit\n");
  printf("What do you want to do?\n");
  printf("=========================================================\n");
  //scanf("%s", str);
    
  if(loadData("data.dat", &head) == 1){


  }
  else{
    head = malloc(sizeof(product));
    if( head == NULL){
      //Something went wrong
      return 1;
    }
    head->next = NULL;
    strncpy(head->name, "beans", 6);
    head->quantityValue = 3;
    strncpy(head->quantityUnit, "Cans", 5);
    head->priceValue = .99;
    strncpy(head->priceUnit, "cents", 6);
    till = 20.00;
   // printf("How many cents? %f", head->priceValue);
       
  }


  //Main while loop and customer interface
  while(str[0] != '8'){
    scanf(" %c", str);
    //add product
    if(str[0] == '1'){
      addProduct(head);
      printCmds();
    }
    //Purchase
    else if(str[0] == '2'){
    }
    //check price
    else if(str[0] == '3'){
      printf("\nEnter name of product: ");
      scanf(" %s", ans);
      checkPrice(head, ans);
      printCmds();
    }
    //Show products
    else if(str[0] == '4'){
      storeProducts(head);
      printCmds();
    }
    //Remove product
    else if(str[0] == '5'){
    }
    //Product info
    else if(str[0] == '6'){
      printf("\nEnter name of product: ");
      scanf(" %s", ans);
      productInfo(head, ans);
      printCmds();
    }
    //Inventory info
    else if(str[0] == '7'){
    }
    //else exit.
  }

  /*
  product *testNode = NULL;
  testNode = malloc(sizeof(product));
  testNode->next = NULL;
  strncpy(testNode->name, "potato", 8);
  
  insert(head, testNode);
  //beans.name = "beans";
  //printf("\n%s", head->name);

  */
  //TODO: put at header
  FILE *fp;
  fp = fopen("data.dat", "w");
  saveData(fp, head);
  printf("\nGoodbye.\n");
  return 0;
}

void printCmds(){
    printf("\n=========================================================\n");
  printf("1:Add product to store     2:Purchase product from store\n");
  printf("3:Check price of product   4:Show products in store\n");
  printf("5:Remove product           6:Find product in store\n");
  printf("7:Inventory                8:Exit\n");
  printf("What do you want to do?\n");
  printf("=========================================================\n");
  return;
}
