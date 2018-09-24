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

  //Attempts to load in file.
    head = malloc(sizeof(product));
  if(head == NULL){
    printf("Error in creating first product.");
  }
  if(loadData("data1.dat", &head) == 1){
    printf("\nInventory Loaded\n");
  }
  else{
    printf("\nInventory could not be loaded.\n");
    head = malloc(sizeof(product));
    if( head == NULL){
      //Something went wrong
      return 1;
    }
    head->next = NULL;
    till = 0.00;
    //Default item.
    strncpy(head->name, "beans",20);
    head->priceValue = 2.0;
    strncpy(head->priceUnit, "cents", 20);
    head->quantityValue = 3.0;
    strncpy(head->quantityUnit, "cans", 20);
  }


  printf("\n\nWelcome to Bryce Hutton Grocery Store!\n");
  printf("=========================================================\n");
  printf("1:Add product to store     2:Purchase product from store\n");
  printf("3:Check price of product   4:Show products in store\n");
  printf("5:Remove product           6:Find product in store\n");
  printf("7:Inventory                8:Exit\n");
  printf("What do you want to do?\n");
  printf("=========================================================\n");
    


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
      printf("\nEnter name of product to purchase: ");
      scanf(" %s", ans);
      purchaseItem(head, ans, &till);
      printCmds();
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
      printf("-----Store Products-----\n");
      storeProducts(head);
      printCmds();
    }
    //Remove product
    else if(str[0] == '5'){
      printf("\nEnter name of product to delete: ");
      scanf(" %s", ans);
      rmItem(head, (findItem(head, ans)));
      printCmds();
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
      inventory(head, &till);
      printCmds();
    }
    //else exit.
  }

  
  FILE *fp;
  fp = fopen("data.dat", "w");
  saveData(fp, head);
  printf("\nGoodbye.\n");
  return 0;
}

/*Prints the commands, called after every command.
 */
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
