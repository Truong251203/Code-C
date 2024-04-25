#include <stdio.h>
#include<string.h>



typedef struct Node{
int id;
struct Node* leftChild; 
struct Node* rightChild;
}Node;


Node* root;
Node* makeNode (int id){
Node* p = (Node*)malloc(sizeof(Node));
p->id = id;
p->leftChild = NULL; p->rightChild = NULL;
return p; }

Node* find (Node* r, int id) {

if(r == NULL) return NULL; if(r->id == id) return r;
Node* p = find(r-leftChild, id);
if(p != NULL) return p;
return find(r-rightChild, id); 
}

void addLeftChild (int u, int left){
Node* pu = find (root,u);
if(pu == NULL)
printf("Not found %d in", u); return;
if(pu->leftChild != NULL)
printf("Node %d has already leftChildIn",u); return;

pu->leftChild = makeNode(left);}

void addRightChild (int u, int right){
Node* pu = find(root, u);
if(pu == NULL
printf("Not found %dIn", u); return;
}.
if(pu->rightChild != NULL){
printf("Node %d has already rightChildIn", u); return;
}
pu->rightChild = makeNode(right);}

void load(char* filename){
FILE*f= fopen(filename,"r");
root = NULL;
while (1){
int u;
fscanf(f,"%d", &u);
if(u == -2) break; / termination
if(root == NULL) root = makeNode(u);// create the root
int I,r;
fscanf(f,"%d%d", &1,&r);
if(1 > -1) addLeftChild (u,I);
if(r > -1) addRightChild (u,r);
}
flose(f); }


void printTree(Node* r){
if(r== NULL) return;
printf("%d: ",->id);
if(r->leftChild == NULL) printf("leftChild = NULL");
else printf("leftChild = %d",
*, r->leftChild->id);
if(r->rightChild == NULL) printf", rightChild = NULL");
else printf", rightChild = %d", r->rightChild->id);
printf("n");
printTree(r->leftChild);
printTree(r->rightChild);   }

void processLoad {
char filename[256];
scanf("%s",filename);
load (filename);
}
void printChildren (Node* p){
if(p->leftChild == NULL) printf(" Node %d does not has leftChild", p->id);
else printf(", LeftChild = %d", p->leftChild->id);
if(p->rightChild == NULL) printf(" Node %d does not has rightChildin", p->id);
else printf(", RightChild = %dIn",p->rightChild->id);
}

void processFind()
int id;
scanf("%d", &id);
Node* p = find(root,id);
if(p == NULL) printf("Not found %dIn",id);
else {
printf("Found node %d: ",id);
printChildren (P);
}
void processPrint(){
printTree (root); }

void processAddLeftChild(){
int id, u;
scanf("%d%d", &id, &u);
addLeftChild (id,u);}
void processAddRightChild (){
int id, u;
scanf("%d%d",&id, &u);
addRightChild (id, u);
}

int height(Node* p)
if(p == NULL) return 0;
int maxH = 0;
int hl = height(p->leftChild);
if(maxH < hl) maxH = hI;
int hr = height(p->rightChild);
if (maxH < hr) maxH = hr;
return maxH + 1;
}
void processHeight(){
int id;
scanf"%d", &id);
Node* p = find (root, id);
if(p == NULL) printf("Not found %dIn", id);
else printf("Height of %d is %din", height(p)); }


int count(Node* p){
if(p == NULL) return 0; return 1 + count(p->leftChild) + count(p-rightChild);
}
void printLeaves(Node* p){
if(p == NULL) return;
if(p->leftChild == NULL && p->rightChild == NULL)
printf("%d ",p->id);
printLeaves(p->leftChild);
printLeaves(p->rightChild);
}
void processFindLeaves(){
printLeaves (root); printf("In"); }


void processCount l
printf"Number of nodes = %din", count(root));
}
void processStore({
char filename[256];
scanf("%s",filename);
FILE* f = fopen(filename,"W");
printTreeF(root,f);
fprintf(f, "-2");
folose(f);
}
void freeTree (Node* r{
if(r== NULL) return; free Tree(r->leftChild);
free Tree(r->rightChild);
free(r); r = NULL; }

int main(
while (1){
char cmd[256]; // representing the input command
printf("Enter a command: ");
scanf(%s, cmd);
if(stremp(cmd,"Quit") == 0) break;
else if(stromp(cmd, "Load")==0) processLoad();
else if(stromp(cmd,"Print"==0) processPrint();
else if(stremp(cmd, "Find"==0) processFind();
else if(stremp(cmd,"Height"==0) processHeight();
else if(stromp(cmd,"Count"==0) processCount();
else if(stremp(cmd, "FindLeaves"==0) processFindLeaves);
else if(stremp(cmd, "AddLeftChild"==0) processAddLeftChild ();
else if(stremp(cmd, "AddRightChild")==0) processAddRightChild);
else if(stremp(cmd, "Store")==0) processStore(); 
}
free Tree (root); 
return 0;
}
