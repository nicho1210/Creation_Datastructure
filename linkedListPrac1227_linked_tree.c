#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
struct node
{
    int data; 
    treePointer rightchild; // right child
    treePointer leftchild;  // left child
};

treePointer new_node(int data)	//create new_node in tree
{
    treePointer p; // node
    p =(treePointer)malloc(sizeof(struct node)); 
    p->data = data; 
    p->leftchild = NULL; 
    p->rightchild = NULL;

    return(p); 
}

void preorder(treePointer ptr){
    if(ptr){
        printf("%d,",ptr->data);
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
}

void inorder(treePointer ptr){	
    if(ptr){
        inorder(ptr->leftchild);
        printf("%d,",ptr->data);
        inorder(ptr->rightchild);
    }
}

void postorder(treePointer ptr){ 
    if(ptr){
        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        printf("%d,",ptr->data);
    }
}

int main()
{
    treePointer root; //new structure
    root = new_node(1); // making a new node
    
	/*
     ____
    |  1 |
    |____|
    
    */
    
	root->leftchild = new_node(3); //left child of root
    
	/*
             ____
            |  1 |
           /|____|
     ____ /       
    |  3 |        
    |____|        

    */
    
	root->rightchild = new_node(5); //right child of root

    /*
             ____
            |  1 |
           /|____|\
     ____ /       _\___
    |  3 |        |  5 |
    |____|        |____|

    */
    
	root->leftchild->leftchild = new_node(7); 

    /*
                     ____
                    |  1 |
                   /|____|\
             ____ /       _\___
            |  3 |        |  5 |
           /|____|        |____|
      ____/       
     |  7 |      
     |____|      

    */
    
    root->leftchild->rightchild = new_node(9); 

        /*
                     ____
                    |  1 |
                   /|____|\
             ____ /       _\___
            |  3 |        |  5 |
           /|____|\       |____|
      ____/       _\___
     |  7 |      |   9 |
     |____|      |_____|

    */
    printf("using recursion:\n\n");
    printf("mid->left->right:\n");
    preorder(root);
    printf("\n");
    printf("left->mid->right:\n");
    inorder(root);
    printf("\n");
    printf("left->right->mid:\n");
    postorder(root);
    printf("\n");
    
    return 0;
}

