#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int data;
    struct node * left,*right;
}a;

a * create (){
    a* newnode=(a *)malloc(sizeof(a));
    printf("enter the data to insert (inset -1 for move out) : \n");
    int x;
    scanf("%d",&x);
    if (x==-1){
        return 0;
    }
    newnode->data=x;
    printf("enter the left data of %d \n",x);
    newnode->left=create();
    printf("enter the right data of %d \n",x);
    newnode->right=create();
    return newnode;
}
void preorder(a * root){
    if (root ==NULL){
        return ;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(a * root){
    if (root ==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void Inorder(a * root){
    if (root ==NULL){
        return ;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
int main(){
    a * root = NULL;
    root = create();
    printf("Preorder---->");
    preorder(root);
    printf("\nPostorder---->");
    postorder(root);
    printf("\nInorder---->");
    Inorder(root);
    printf("\n");
    return 0;
}