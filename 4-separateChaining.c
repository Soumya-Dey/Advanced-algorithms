#include <stdio.h>
#include <stdlib.h>

struct hash *hashTable = NULL;
int eleCount = 0;

struct node {
    int key;
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};

struct node * createNode(int key) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;

    return newnode;
}


void insertToHash(int key) {
    int hashIndex = key % eleCount;
    struct node *newnode =  createNode(key);
    
    // insert at head if the has table in this index is empty
    if (!hashTable[hashIndex].head) {
            hashTable[hashIndex].head = newnode;
            hashTable[hashIndex].count = 1;
            return;
    }

    // otherwise insert at first
    // attach the old head as the next node of the new node
    newnode->next = (hashTable[hashIndex].head);
    // then add the new node as the head and increment count
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;

    return;
}

void searchInHash(int key) {
    int hashIndex = key % eleCount;
    int count = 0;
    struct node *myNode;

    myNode = hashTable[hashIndex].head;
    if (!myNode) {
        printf("\nSearch element unavailable in hash table\n");
        return;
    }

    while (myNode != NULL) {
        if (myNode->key == key) {
            printf("\n%d found in Hash Table %d at index %d\n", myNode->key, hashIndex, count);
            return;
        }
        count++;
        myNode = myNode->next;
    }

    printf("\nSearch element unavailable in hash table\n");

    return;
}

void display() {
    struct node *myNode;
    int i;

    for (i = 0; i < eleCount; i++) {
        if (hashTable[i].count == 0)
                continue;

        myNode = hashTable[i].head;
        if (!myNode)
                continue;

        printf("\nNodes at %dth Hash Table: ", i);
        while (myNode != NULL) {
            printf("%d -> ", myNode->key);
            myNode = myNode->next;
        }
        printf("NULL");
    }
    printf("\n");
    return;
}

int main() {
    int n, ch, key;

    printf("\nEnter the number of hash tables:");
    scanf("%d", &n);
    eleCount = n;

    // create n hash tables
    hashTable = (struct hash *)calloc(n, sizeof (struct hash));

    while (1) {
        printf("\n1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        printf("\nChoose the option: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the key value: ");
                scanf("%d", &key);

                insertToHash(key);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("\nEnter the key to search: ");
                scanf("%d", &key);

                searchInHash(key);
                break;

            case 4:
                exit(0);

            default:
                printf("\nWrong choice enetered!\n");
                break;
        }
    }
    return 0;
}