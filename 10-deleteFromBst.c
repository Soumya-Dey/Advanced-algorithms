#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};

struct node* newNode(int item){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = NULL;
    temp->right = NULL;

	return temp;
}

struct node* insert(struct node* node, int key){
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}

void inorder(struct node* root){
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

// finding the leftmost leaf node
struct node* inorderSuccessor(struct node* node){
	struct node* current = node;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int key){
	if (root == NULL) return root;

	// key is  in left subtree
	if (key < root->key) 
        root->left = deleteNode(root->left, key);

	// key is in right subtree
	else if (key > root->key) 
        root->right = deleteNode(root->right, key);

	// key is same as root's key
	else {
        // node with two children
        if(root->left != NULL && root->right != NULL){
            struct node* temp = inorderSuccessor(root->right);

            // Copy the inorder
            // successor's content to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
		// node with only one child or no child
		else if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);

			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);

			return temp;
		}
	}
	return root;
}

int main()
{
	/*
		  5
		/   \
	   3    7
	  / \  / 
	 2  4 6  
    */
	struct node* root = NULL;
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 6);

	printf("Inorder traversal: ");
	inorder(root);

    // deleting leaf node
	printf("\n\nDeleting 2...\n");
	root = deleteNode(root, 2);
	printf("Inorder traversal: ");
	inorder(root);

    // deleting half node
	printf("\n\nDeleting 7...\n");
	root = deleteNode(root, 7);
	printf("Inorder traversal: ");
	inorder(root);

    // deleting full node
	printf("\n\nDeleting 5...\n");
	root = deleteNode(root, 5);
	printf("Inorder traversal: ");
	inorder(root);
    printf("\n");

	return 0;
}
