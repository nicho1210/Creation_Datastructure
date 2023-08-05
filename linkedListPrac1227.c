#include <stdio.h>
#include <stdlib.h>
#define Num 20

int i;
int data[Num]={0};
int Tree[Num]={0};

void CreateBinaryTree(int data[], int n) {   
    int node=0, temp;
    for (i=0; i<Num; i++) {Tree[i]=0;}  
    for (i=0; i<n; i++) {
        Tree[node]=data[i];
        node=node + 1;
        }
    }

void postorder(int ptr) {   //?->?->? 
    if (Tree[ptr]) {
        postorder(2*ptr+1);    
        postorder(2*ptr+2);  
        printf("%2d ",Tree[ptr]); 
   }
}

void inorder(int ptr) {   //?->?->? 
    if (Tree[ptr]) {
        inorder(2*ptr+1); 
		printf("%2d ",Tree[ptr]);   
        inorder(2*ptr+2);   
   }
}

void preorder(int ptr) {  //?->?->? 
    if (Tree[ptr]) {
    	printf("%2d ",Tree[ptr]);
        preorder(2*ptr+1);    
        preorder(2*ptr+2);   
   }
}

int main() {
    int n;
    printf("Input Num of Nodes:");
    scanf("%d", &n);
    printf("Input %d nodes' content, enter after you finish one:\n", n);
    for (i=0; i<n; i++) {
       scanf(" %d", &data[i]);
       }
    CreateBinaryTree(data, n); 
    
    printf("--------------------------------");
    printf("\nuse array:\n\n");
    printf("mid->left->right:\n");
    preorder(0);   
    printf("\n");
    printf("left>mid->right:\n");
    inorder(0);   
    printf("\n");
    printf("left->right->mid:\n");
    postorder(0);   
    
    return 0;
}
