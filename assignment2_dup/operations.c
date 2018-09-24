#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 20
struct product
{
  char name[N];
  float quantityValue;
  char quantityUnit[N];
  float priceValue;
  char priceUnit[N];
  struct product *next;
};
typedef struct product product;
product * findItem(product *p, char pName[]);

int addProduct(product *head){
  char str[N];
  float flo;
  printf("\nName of product    :");
  scanf("%s", str);
  product *newNode = NULL;
  if((findItem(head, str))->name != NULL){
    (findItem(head,str))->quantityValue++;
    printf("Quantity increased by 1");
    return 1;
  }
  newNode = malloc(sizeof(product));
  if (newNode == NULL){
    return 2;
  }
  //printf("\nName of product    :");
  // scanf("%s", str);
  strncpy(newNode->name, str, N);

  printf("Price of product   :");
  scanf("%f", &(newNode->priceValue));

  printf("Unit of price      :");
  scanf("%s", str);
  strncpy(newNode->priceUnit, str, N);

  printf("Quantity of product:");
  scanf("%f", &(newNode->quantityValue));

  printf("Quantity unit      :");
  scanf("%s", str);
  strncpy(newNode->quantityUnit, str, N);

  insert(head, newNode);
  return 0;
}

//Inserts node to linked list. p is spot, node is node to be added to list
int insert(product *p, product *node){
  if(p->next != NULL)
    insert(p->next, node);
  else{
    p->next = node;
    node->next = NULL;
  }
  return 0;
}

//Removes item from list *node is item to be removed.
int rmItem(product *p, product *node){
  if(p->next == NULL){
    return 1;
  }
  else if(p->next != node){
    rmItem(p->next, node);
  }
  else if(p->next == node){
    p->next = node->next;
    free(node);
  }
  return 0;
}

//Loads file.
int loadData(char inf[], product **p){

  return 0;
}

int saveData(FILE *fp, product *p){
  //FILE *fp;
  // fp = fopen(outf, "w");
  fputs(p->name, fp);
  fputs("\n", fp);
  fprintf(fp, "%d", p->quantityValue);
  fputs("\n", fp);
  fputs(p->quantityUnit, fp);
  fputs("\n", fp);
  fprintf(fp, "%d", p->priceValue);
  fputs("\n", fp);
  fputs(p->priceUnit, fp);
  fputs("\n-NEXT-\n", fp);
  if(p->next != NULL){
    saveData(fp, p->next);
  }
  return 0;
}

//Deletes each node and free's all the memory
int deleteList(product *head){
  if(head->next != NULL){
    deleteList(head->next);
  }
  free(head);
  return 0;
}

float purchase(product *p, char product[], float *q){
  
}

void checkPrice(product *p, char pName[]){
  product *checkedItem;
  checkedItem = findItem(p, pName);
  if(checkedItem->name != NULL){
  printf("Product %s\nPrice:%0.2f %s\n", checkedItem->name, checkedItem->priceValue, checkedItem->priceUnit);
  }
  else{
    printf("\nUnable to find product in store.\n");
  }
  return;
}
/*Finds the item on the list given a name.
 */
product * findItem(product *p, char pName[]){
  if(strcmp(pName, p->name) == 0){
    return p;
  }
  else if(p->next != NULL){
    return findItem(p->next, pName);
  }
  else
    return;
}


/*Takes product and prints out the information about it.
 */
void printProduct(product *p){
  printf("Product:%s\n", p->name);
  printf("Quantity:%f %s\n", p->quantityValue, p->quantityUnit);
  printf("Price:%0.2f %s\n", p->priceValue, p->priceUnit);
}

/*Storeproducts recursively calls printproduct to display each product.
 */
void storeProducts(product *head){
  printProduct(head);
  printf("\n");
  if(head->next != NULL){
    storeProducts(head->next);
  }
  return;
}

void productInfo(product *head, char pName[]){
  product *p;
  p = findItem(head, pName);
  if(p->name != NULL){
    printProduct(p);
  }
  else{
    printf("\nUnable to find product in store.\n");
  }
  return;
}

void inventory(product *head, float *till){
  printf("\nMoney made from sales is:%0.2f\n", *till);
  storeProducts(head);
  return;
}
