#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int num;
    struct Node* left;
    struct Node* right;
    char collor;
} Node;

Node* insert(Node* redBlackTree, int num);
Node* leftRotation(Node* node);
Node* rightRotation(Node* node);
void flipCollors(Node* node);
Node* factory(int num);
int isRed(Node* node);
void binarySearchTree(Node* tree, int num);

int main() {

    Node* redBlackTree;

    int num;
    while (scanf("%d", &num)!=EOF) redBlackTree = insert(redBlackTree, num);
    return 0;
}

Node* insert(Node* redBlackTree, int num) {

    if (redBlackTree==NULL) return factory(num);

    if (num>redBlackTree->num) redBlackTree->right = insert(redBlackTree->right, num);
    else redBlackTree->left = insert(redBlackTree->left, num);

    if (isRed(redBlackTree->right)) redBlackTree = leftRotation(redBlackTree);
    if (isRed(redBlackTree->left) && isRed(redBlackTree->left->left)) redBlackTree = rightRotation(redBlackTree);
    if (isRed(redBlackTree->left) && isRed(redBlackTree->right)) flipCollors(redBlackTree);
    
    return redBlackTree;
}

Node* leftRotation(Node* node) {
    // Change collor
    char aux = node->collor;
    node->collor=node->right->collor;
    node->right->collor=aux;

    // rotate
    Node* right = node->right;

    node->right = right->left;
    right->left = node;

    return right;
}

Node* rightRotation(Node* node) {
    // Change collor  
    char aux = node->collor;
    node->collor = node->left->collor;
    node->left->collor= aux;

    // Rotate
    Node* left = node->left;

    node->left = left->right;
    left->right = node;

    return left;
}

void flipCollors(Node* node) {
    if (node->collor=='r') node->collor='b';
    else node->collor='r';

    if (node->left->collor=='r') node->left->collor='b';
    else node->left->collor='r';

    if (node->right->collor=='r') node->right->collor='b';
    else node->right->collor = 'r';
}

Node* factory(int num) {
    Node* element = (Node*)malloc(sizeof(Node));
    element->collor='r';
    element->left=NULL;
    element->right=NULL;
    element->num=num;

    return element;
}

int isRed(Node* node) {
    return (node!=NULL && node->collor=='r');
}
