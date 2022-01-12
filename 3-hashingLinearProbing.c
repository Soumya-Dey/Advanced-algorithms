#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE];

void init(){
    int i;
    for(i = 0; i < TABLE_SIZE; i++){
        h[i] = -1;
    }
}

void insert(){
    int key, index, i, flag = 0, hkey;

    printf("\nEnter a value to insert: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;

    for(i = 0; i < TABLE_SIZE; i++){
        index = (hkey + i) % TABLE_SIZE;

        if(h[index] == -1){
            h[index] = key;
            break;
        }
    }

    if(i == TABLE_SIZE)
        printf("\nElement cannot be inserted.\n");
}

void search(){
    int key, index, i, flag = 0, hkey;

    printf("\nEnter element to search: ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;

    for(i = 0; i < TABLE_SIZE; i++){
        index = (hkey + i) % TABLE_SIZE;

        if(h[index] == key){
        printf("Value is found at index %d\n", index);
        break;
        }
    }

    if(i == TABLE_SIZE)
        printf("\nValue is not found\n");
}

void display(){
  int i;
  printf("\nElements in the hash table:\n");
  for(i = 0; i < TABLE_SIZE; i++)
    printf("\nindex %d \t value =  %d", i, h[i]);
  printf("\n");
}

int main(){
    init();

    int opt;
    while(1){
        printf("\n1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        printf("Choose the option: ");
        scanf("%d", &opt);

        switch(opt){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}