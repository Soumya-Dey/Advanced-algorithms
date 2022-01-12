#define STACK_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
  
typedef struct stack{
    int top;
    Node *items[STACK_SIZE];
}stack;
  
void push(stack *s, Node *item){
   if(s->top < STACK_SIZE-1){
       s->items[++(s->top)] = item;
   }
   else {
       printf("Stack is already full\n");
   }
}
  
Node * pop (stack *s){
   if(s->top > -1 ){
       return s->items[(s->top)--];
   } 
   else{
       printf("Stack is empty\n");
   }
}

int isEmpty(stack s){
   if(s.top < 0) return 1;
   else return 0;
}
 
void inorderTraversal(Node *root){
    stack s;
    s.top = -1;
    Node *currentNode = root;

    while(!isEmpty(s) || currentNode){
        if(currentNode){
            push(&s, currentNode);
            currentNode = currentNode->left;
        }
        else {
            currentNode = pop(&s);
            printf("%d  ", currentNode->value);
            currentNode = currentNode->right;
        }
    }
}

void preorderTraversal(Node *root){
    stack s;
    s.top = -1;
    Node *currentNode = root;

    while(!isEmpty(s) || currentNode){
        if(currentNode){
            printf("%d  ", currentNode->value);
            push(&s, currentNode);
            currentNode = currentNode->left;
        }
        else {
            currentNode = pop(&s);
            currentNode = currentNode->right;
        }
    }
}

void postorderTraversal(Node* root){
	if (root == NULL)
		return;

	stack s1;
	stack s2;
    s1.top = -1;
    s2.top = -1;
    Node *currentNode = root;
	push(&s1, currentNode);

	while (!isEmpty(s1)) {
		currentNode = pop(&s1);
		push(&s2, currentNode);

		if (currentNode->left)
			push(&s1, currentNode->left);
		if (currentNode->right)
			push(&s1, currentNode->right);
	}

	while (!isEmpty(s2)) {
		currentNode = pop(&s2);
		printf("%d  ", currentNode->value);
	}
}
  
Node * createNode(int value){
    Node * temp =  (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

Node * addNode(Node *node, int value){
    if(node == NULL){
        return createNode(value);
    }
    else{
        if (node->value > value){
            node->left = addNode(node->left, value);
        }
        else{
            node->right = addNode(node->right, value);
        }
    }
    return node;
}

int main(){
    Node *root = NULL;
    
    root = addNode(root, 4);
    root = addNode(root, 2);
    root = addNode(root, 6);
    root = addNode(root, 1);
    root = addNode(root, 3);
    root = addNode(root, 5);
    root = addNode(root, 7);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("\nPreorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("\nPostorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    return 0;
}