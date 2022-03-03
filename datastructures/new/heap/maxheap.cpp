

/* Online algorithm for building max heap. */
 
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
 
struct  node{
    int key;
    int height;
    int size;
    node *left;
    node *right;
};
 
void swap(int *a, int *b)
{
    int t = *a; *a = *b; *b = t;
}
 
int max(int a, int b){
    return (a>b)?a:b;
}
 
node* createNode(int val)
{
    node *temp = new node();
    temp->key=val;
    temp->size=1;
    temp->height=0;
    temp->left=NULL;
    temp->right=NULL;
}
 
int Size(node *t)
{
    if(t==NULL)
        return 0;
    else
        return t->size;
}
 
int Height(node *t)
{
    if(t==NULL)
        return -1;
    else
        return t->height;
}
 
void updateHeightSize(node *t)
{
    t->height = max(Height(t->left),
                        Height(t->right))+1;
    t->size = Size(t->left) + Size(t->right)+1;
}
 
node* insert(node *n, int key)
{
    if(n==NULL){
        n = createNode(key);
        return n;
    }
    if(n->left==NULL ||
           Size(n->left)< int(pow(2, Height(n->left)+1))-1 ||
           Size(n->right)==Size(n->left)) 
        n->left = insert(n->left, key);
    else
        n->right = insert(n->right,key);
 
    if((n->left!=NULL && n->left->key > n->key) ||
            (n->right!=NULL && n->right->key>n->key)){
        if(n->left==NULL){
            swap(n->key, n->right->key);
        }
        else if(n->right==NULL)
            swap(n->key, n->left->key);
        else{
            if(n->left->key > n->right->key)
                swap(n->key, n->left->key);
            else
                swap(n->key, n->right->key);
        }
    }
 
    updateHeightSize(n);
    return n;
}
 
int top(node *root){
    return root->key;
}
 
void heapify(node *n)
{
    if(!n)
        return;
    while((n->left!=NULL && n->left->key>n->key) ||
              (n->right!=NULL && n->right->key>n->key)){
        if(n->left==NULL){
            swap(n->key, n->right->key);
            n = n->right;
        }
        else if(n->right==NULL){
            swap(n->key, n->left->key);
            n = n->left;
        }
        else{
            if(n->left->key > n->right->key){
                swap(n->key, n->left->key);
                n = n->left;
            }
            else{
                swap(n->key, n->right->key);
                n = n->right;
            }
        }
    }
}
 
node* remove(node *n, node *root)
{
    if(n==NULL)
        return NULL;
    if(n->left==NULL && n->right==NULL){
        swap(root->key, n->key);
        delete n;
        return NULL;
    }
    else if(Size(n->left) > Size(n->right))
        n->left = remove(n->left, root);
    else
        n->right = remove(n->right, root);
 
    updateHeightSize(n);
}
 
void pop(node **heap)
{
    *heap = remove(*heap, *heap);
    heapify(*heap);
}
/* 
void display(node *x)
{
    if(!x)
        return;
    display(x->left);
    cout<<key<<endl;    display(x->right);
}
*/
 
int main()
{
    node *heap=NULL;
    int x;
    do{
        cout<<"Enter values to insert in heap. 0 to stop ";       cin>>x;
        if(x!=0){
            heap = insert(heap, x);
            cout<<"Top --> "<<top(heap)<<endl;
        }
    }while(x!=0);
 
    cout<<"\n----- Heap Sort ------\n";
    while(heap){
        cout<<top(heap)<<endl;
        pop(&heap);
    }
    cout<<endl;
    return 0;
}
