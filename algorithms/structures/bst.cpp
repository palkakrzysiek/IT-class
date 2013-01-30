/* 
 * Binary Search Tree
 *
 *         x
 *       /   \
 *      y     z
 *
 * y <= x AND z > x
 *
 */

#include <iostream>

struct BSTNode{
    int v;
    BSTNode *left;
    BSTNode *right;
};

struct BST{
    BSTNode *root;
}; 
/*
 * methods:
 * - addBST
 * - searchBST
 * - removeBST
 */

void addBSTNode(BSTNode *root, BSTNode *k){
    if(k->v > root->v){
        if(!root->right) root->right = k;
        else addBSTNode(root->right, k);
    }
    else{
        if(!root->left) root->left = k;
        else addBSTNode(root->left, k);
    }
}

void addBST(BST *T, int x){
    BSTNode *k = new BSTNode;
    k -> v = x;
    k -> left = NULL;
    k -> right = NULL;
    if (!T -> root) // if tree is empty - its head is NULL
        T -> root = k;
    else
        addBSTNode(T->root, k);
}

BSTNode* searchBST(BST *T, int x){
    BSTNode *temp = T->root;
    while(temp){
        if(temp->v == x) return temp;
        if(x <= temp->v) temp = temp->left;
        else temp = temp->right;
    }
    return temp;
}



// http://upload.wikimedia.org/wikipedia/en/1/15/Tree_Rotations.gif
// http://pl.wikipedia.org/wiki/Rotacja_drzewa
BSTNode* rotateRight(BSTNode *k){
    BSTNode *temp = k->left;
    k->left = temp->right;
    temp->right = k;
    return temp;
}

void rotateLeft(BSTNode *k){
    BSTNode *temp = k->right;
    k->right = temp->left;
    temp->left = k;
    k = temp;
}

// blance BST - Day–Stout–Warren algorithm
// http://pl.wikipedia.org/wiki/Algorytm_DSW
// Drozdek, A. (2001, pl trans 2004) Ch 6.7.1

// Faza I
// DSW w celu zrównoważenia drzewa najpierw - poprzez wielokrotne rotacje prawe - zamienia je w listę. Takie drzewo
// sprowadzone do postaci listy nazywa się kręgosłupem (backbone).

int createBackbone(BST *tree){
    BSTNode *temp = tree->root;
    int nodecount = 0;
    while(temp){
        ++nodecount;
        if(temp->left)
            rotateRight(temp);
        temp = temp->right;
    }
    return nodecount;
}

void createPerfectTree(BST *tree, int nodecount){
    BSTNode *current;
    int k;
    for(int i = nodecount/2; i>0; i /= 2){
        for(current = tree->root, k = 0; k < i; current = current -> right){
            rotateLeft(current);
        }
    }
}
