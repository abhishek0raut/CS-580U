#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indx=0;

Node * newNode(Data data, Node * n)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->data = data;
    return node;
}

Tree * newTree()
{
    Tree * tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->insert=insert;
    tree->sort=sort;
    tree->search=search;
    tree->clone=clone;
    tree->compare=compare;
    tree->delete=deleteTree;
    tree->removeData=removeData;
    return tree;
}

// Operation to insert into the tree

Data * insert(Tree *tree, Data data)
{
    Node * current = NULL;
    if(tree->root == NULL)
    {
        tree->root = newNode(data,NULL);
        current = tree->root;
    }
    else
    {
        current = insertBSTNode(tree->root,data);
    }
    if(current != NULL)
    {
        return &(current->data);
    }
    else
    {
        return NULL;
    }
}

Node * insertBSTNode(Node * node, Data data)
{
    Node * current = NULL;
    if(data.value < node->data.value)
    {
        if(node->left == NULL)
        {
            current = newNode(data,node);
            node->left = current;
            current->parent = node;
            return current;
        }
        else
        {
            current = insertBSTNode(node->left, data);
        }
    }
    else if(data.value > node->data.value)
    {
        if(node->right == NULL)
        {
            current = newNode(data,node);
            node->right = current;
            current->parent = node;
            return current;
        }
        else
        {
            current = insertBSTNode(node->right, data);
        }
    }
    else
    {
        return current;
    }
}

void sort(Tree *tree, Data *data)
{
    if(tree->root != NULL)
    {
        inOrder(tree->root,data);
    }
}

void inorder(Tree * tree) 
{
    if(tree->root!=NULL)
    {
        inorderTreeTraversal(tree->root);
    }
}

void inorderTreeTraversal(Node* node)
{
    if(node!=NULL)
     {
        inorderTreeTraversal(node->left);
        printf(" %d ",node->data.value);
        inorderTreeTraversal(node->right);
    }
}

void inOrder(Node * node, Data *data)
{
    if (node != NULL)
    {
        inOrder(node->left,data);
        data[indx] = node->data;
        indx++;
        inOrder(node->right,data);
    }
}

// Operation to  searche for a value in the tree

Data * search(Tree *tree, Data data)
{
    Node * current = NULL;
    if(tree->root != NULL)
    {
        current = searchNode(tree->root,data);
    }
    if(current != NULL)
    {
        return &(current->data);
    }    
    return NULL;
}

Node * searchNode(Node * node, Data d)
{
    if (node == NULL || node->data.value == d.value)
    {
        return node;
    }        
    if (node->data.value < d.value)
    {
        return searchNode(node->right, d);
    }    
    else
    {
        return searchNode(node->left, d);
    }
}

Tree * clone(Tree *tree)
{
    Tree * newTreeClone = NULL;
    if(tree->root != NULL)
    {
        newTreeClone = newTree();
        cloneBSTTree(tree->root,newTreeClone);
    }
    return newTreeClone;
}

void cloneBSTTree(Node *node, Tree * tree)
{
    if(node!=NULL)
    {
        insert(tree,node->data);
        cloneBSTTree(node->left,tree);
        cloneBSTTree(node->right,tree);
    }
}

int compare(Tree *fTree, Tree *sTree)
{
    int cVal = 0;
    if(fTree!=NULL && sTree!=NULL)
    {
        cVal = compareBSTTreeNode(fTree->root,sTree->root);
    }
    return cVal;
}

int compareBSTTreeNode(Node * first, Node * second)
{
    int rVal =0;
    if (first!=NULL && second!=NULL)
    {
        if(first->data.value == second->data.value)
        {
            rVal = 1;
        }       
        compareBSTTreeNode(first->left, second->left);
        compareBSTTreeNode(first->right, second->right);
    }
    return rVal;
}

void deleteTree(Tree * tree) 
{
    if(tree->root!=NULL) 
    {
        deleteTreeFunction(tree->root);
    }
    free(tree);
}

void deleteTreeFunction(Node * node) 
{
    if(node!=NULL)
    {
        deleteTreeFunction(node->left);
        deleteTreeFunction(node->right);
        removeLeafNode(node);
    }
}

void removeData(Tree * tree, Data data)
{
    Node * nodeDelete = deleteSearch(tree,data);
    if(nodeDelete!=NULL)
    {
        if(nodeDelete->left==NULL && nodeDelete->right==NULL)
        {
            if(nodeDelete==tree->root) 
            {
                free(tree->root);
                tree->root=NULL;
            } 
            else
            {
                removeLeafNode(nodeDelete);
            }    
        }
        else if(nodeDelete->left==NULL || nodeDelete->right==NULL) 
        {
            if(nodeDelete==tree->root)
            {
                if(nodeDelete->left==NULL)
                {
                    tree->root=nodeDelete->right;
                    nodeDelete->right=NULL;
                }
                else if(nodeDelete->right==NULL)
                {
                    tree->root=nodeDelete->left;
                    nodeDelete->left=NULL;
                }
                free(nodeDelete);
                nodeDelete=NULL;
            } 
            else
            {
                shortCircuit(nodeDelete);
            }
        }
        else
        {
            promotion(nodeDelete);
        }
    }
}

void removeLeafNode(Node * node)
{
    if(node->parent==NULL)
    {
        free(node);
        node=NULL;
    }
    else
    {
        if(node==node->parent->left)
        {
            node->parent->left=NULL;
        }
        else
        {
            node->parent->right=NULL;
        }
        free(node);
        node=NULL;
    }
}

void shortCircuit(Node *node)
{
    if(node->parent==NULL)
    {
        if(node->left==NULL)
        {
            node->right=NULL;
        }
        else if(node->right==NULL)
        {
            node->left=NULL;
        }
        free(node);
        node=NULL;
    }
    else
    {
        if(node == node->parent->left)
        {
            if(node->right==NULL)
            {
                node->parent->left=node->left;
                node->left->parent=node->parent;
            }
            else if(node->left==NULL)
            {
                node->parent->left=node->right;
                node->right->parent=node->parent;
            }
        }
        else if(node== node->parent->right)
        {
            if(node->left==NULL)
            {
                node->parent->right=node->right;
                node->right->parent=node->parent;
            }
            else if(node->right==NULL)
            {
                node->parent->right=node->left;
                node->left->parent=node->parent;
            }
        }
        free(node);
        node=NULL;
    }
}

void promotion(Node * node)
{
    Node *n1 = findMinR(node);
    node->data=n1->data;
    if(n1->right==NULL)
    {
        removeLeafNode(n1);
    }
    else
    {
        shortCircuit(n1);
    }
}

Node * findMaxL(Node * node) 
{
    if(node->left==NULL)
    {
        return node;
    }
    else
    {
        node=node->left;
        while(node->right!=NULL)
        {
            node=node->right;
        }
    }
    return node;
}

Node * findMinR(Node * node)
{
    if(node->right==NULL)
    {
        return node;
    }
    else
    {
        node=node->right;
        while(node->left!=NULL)
        {
            node=node->left;
        }
    }
    return node;
}

Node * deleteSearch(Tree * tree, Data data)
{
    if(tree->root==NULL)
    {
        return NULL;
    }
    else
    {
        return deleteSearchBSTNode(tree->root,data);
    }
}

Node * deleteSearchBSTNode(Node * node, Data data)
{
    if(node==NULL)
    {
        return NULL;
    }
    else 
    {
        if(node->data.value == data.value)
        {
            return node;
        }    
        else if(node->data.value > data.value)
        {
            searchNode(node->left,data);
        }
        else if(node->data.value < data.value)
        {
            searchNode(node->right,data);
        }
        else
        {
            return NULL;
        }
    }
}