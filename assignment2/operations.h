#ifndef			__H_MY_LIBRARY__
#define			__H_MY_LIBRARY__
#include <stdio.h>

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

int addProduct(product *head);
int insert(product *p, product *node);
int rmItem(product *p, product *node);
int loadData(char inf[], product **p);
int saveData(FILE *fp, product *p);
int deleteList(product *head);
float purchaseItems(product *head, char product[], float *q);
void checkPrice(product *p, char pName[]);
product * findItem(product *p, char pName[]);
void productInfo(product *p, char pName[]);
void storeProducts(product *head);
void inventory(product *head, float *till);


#endif
