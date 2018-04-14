
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
    malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
 }
/* 
Node * searchLeftMax(Node * n, Node * o)
{
    if(n==o) n=n->left;
    if( n->right == NULL)
        return n;
    else
        return searchLeftMax(n->right,o);
}

Node * searchRightMin(Node * n)
{
    n=n-> right;
    while( n->left != NULL)
        n=n->left;
    return n;
}
*/
/*
void promote(Node * n)
{
    Node * to_promote = findRightMin(n);
    n->data = to_promote -> data;
    if(to_promote -> left == NULL && to_promote->right == NULL)
    {
        deleteLeaf(to_promote);
    }
    else
    {
        shortCircuit(to_promote);
    }
    
}

*/

void traverseDFS(struct Node * n)
{
if(n!=NULL)
{
//printf("preorder :%d\n",n->data);
traverseDFS(n->left);
printf("inorder :%d\n",n->data);
traverseDFS(n->right);
//printf("postorder :%d\n",n->data);


}

return;

}


int main(void)
{
    struct Node *NewRoot=NULL;
    struct Node *root = newNode(5);
    root->left        = newNode(3);
    root->right       = newNode(8);
    root->left->left  = newNode(2);
    root->left->right = newNode(4);
    root->left->left->left = newNode(1);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
    root->right->left->right = newNode(7);
   traverseDFS(root);
   return 0;
}

