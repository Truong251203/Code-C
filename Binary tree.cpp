#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _node
{
	int data;
	struct _node *lf;
	struct _node *rf;
}Node;


Node *MakeNode(int data){
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=data;
	p->lf=NULL;
	p->rf=NULL;
	return p;
}

void PreOrder (Node *p){
	if(p==NULL) return;
	printf("%d ",p->data);
	PreOrder(p->lf);
	PreOrder(p->rf);
	
}

void PostOrder(Node *p){
	if(p==NULL) return;
	PostOrder(p->lf);
	PostOrder(p->rf);
	printf("%d ",p->data);
}

void InOrder(Node *p){
	if(p==NULL) return;
	InOrder(p->lf);
	printf("%d ",p->data);
	InOrder (p->rf);
}

Node *Find(Node *p, int r){
	if (p==NULL) return NULL;
	if(p->data==r) return p;
	Node *g=p;
Node *h =Find(g->lf,r);
if(h!=NULL) return h;
return Find(g->rf,r);
	
}

int main(){
	Node *root=NULL;
	char c[100];
	while(strcmp(c,"*")!=0)
	{  scanf("%s",c);
		if(strcmp(c,"MakeRoot")==0){
			int d;
			scanf("%d",&d);
			root=MakeNode(d);
		}
		
		if(strcmp(c,"AddLeft")==0){
			int c,e;
			scanf("%d%d",&c,&e);
			Node *r=root;
			Node*m=Find(r,e);
			if(m==NULL||m->lf!=NULL) continue;
			m->lf=MakeNode(c);
		}
		
		if(strcmp(c,"AddRight")==0){
			int c,e;
			scanf("%d%d",&c,&e);
			Node *r=root;
			Node*m=Find(r,e);
			if(m==NULL||m->rf!=NULL) continue;
			m->rf=MakeNode(c);
		}
		
		if(strcmp(c,"PreOrder")==0){
			PreOrder(root);
			printf("\n");
		}
		
		if(strcmp(c,"InOrder")==0){
			InOrder(root);
			printf("\n");
		}
		
		if (strcmp(c,"PostOrder")==0){
			PostOrder(root);
			printf("\n");
		}
		
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
}



















































