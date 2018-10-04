#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
   int data;   
   int key;
};

struct DataItem* dataList[SIZE]; 
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key) {
   return key % SIZE;
}

struct DataItem *search(int key) {
   //get the hash 
   int hashIndex = getHashCode(key);  
	
   //move in array until an empty 
   while(dataList[hashIndex] != NULL) {
	
      if(dataList[hashIndex]->key == key)
         return dataList[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(int key,int data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   //get the hash 
   int hashIndex = getHashCode(key);

   //move in array until an empty or deleted cell
   while(dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   dataList[hashIndex] = item;
}

struct DataItem* del(struct DataItem* item) {
   int key = item->key;

   //get the hash 
   int hashIndex = getHashCode(key);

   //move in array until an empty
   while(dataList[hashIndex] != NULL) {
	
      if(dataList[hashIndex]->key == key) {
         struct DataItem* temp = dataList[hashIndex]; 
			
         //assign a dummy item at deleted position
         dataList[hashIndex] = singleItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(dataList[i] != NULL)
         printf(" (%d,%d)",dataList[i]->key,dataList[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

int main() {
   singleItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   singleItem->data = -1;  
   singleItem->key = -1; 

   insert(1, 20);
   insert(2, 70);
   insert(42, 80);
   insert(4, 25);
   insert(12, 44);
   insert(14, 32);
   insert(17, 11);
   insert(13, 78);
   insert(37, 97);

   display();
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   del(item);
   item = search(37);


   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }
}