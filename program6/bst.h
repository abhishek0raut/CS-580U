#ifndef BST_H
#define BST_H

typedef struct data{
    int value;
}Data;

typedef struct node{
    Data data;
    struct node * left;
    struct node * right;
    struct node * parent;
}Node;

typedef struct tree{
    Node * root;
    Data * (*insert)(struct Tree *, Data);
    void (*sort)(struct Tree *, Data *);
    Data * (*search)(struct Tree *, Data);
    struct Tree * (*clone)(struct Tree *);
    int (*compare)(struct Tree *,struct Tree *);
    void (*removeData)(struct Tree *, Data);
    void (*delete)(struct Tree *);
}Tree;

Node * newNode(Data , Node *);
Tree * newTree();
Data * insert(Tree *, Data);
Node * insertBSTNode(Node *, Data);
Data * search(Tree *, Data);
Node * searchNode(Node *, Data);
void sort(Tree *, Data *);
int sortTree(Node *,Data *, int);
int compare(Tree *, Tree *);
int compareBSTTreeNode(Node *, Node *);
Tree * clone(Tree *);
void cloneBSTTree(Node *,Tree*);
void deleteTree(Tree *);
void inOrder(Node *, Data *);
void removeData(Tree *, Data);
void deleteNode(Node *);
void removeLeafNode(Node *);
void shortCircuit(Node *);
void promotion(Node *);
Node * findMaxL(Node *);
Node * findMinR(Node *);
Node * deleteSearch(Tree *, Data);
Node * deleteSearchBSTNode(Node *, Data);
int compareTreeNode(Node*,Node *,int);
void deleteTreeFunction(Node *);
void inorder(Tree *);
void inorderTreeTraversal(Node*);
#endif