#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int data;
    struct node*leftchild;
    struct node*rightchild;
};
typedef struct node node;
node *makenode(int x){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;
    return newnode;
}
//tao 1 nut v cho vao 
node *Insert(node *root,int u){
    if(root==NULL){
        root=makenode(u);
    }
    if(root->data > u){
        root->leftchild=Insert(root->leftchild,u);
    }
    else if(root->data < u){
        root->rightchild=Insert(root->rightchild,u);
    }
    return root;
}
void preorder(node *root){
	if(root == NULL) return;
	printf("%d ",root->data);
	preorder(root->leftchild);
	preorder(root->rightchild);
}

int main(){
    node *root=NULL;
    char s[20];
    while(scanf("%s",s) && strcmp(s,"#") != 0){
        if(strcmp(s,"insert")==0){
            int u;
            scanf("%d",&u);
            root =Insert(root,u);
        }
    }
    preorder(root);
    return 0;
}
