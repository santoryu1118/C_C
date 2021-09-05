// 이진 탐색 트리 Binary Search Tree
// 이진탐색과 linked list를 결합한 자료구조
// 이진탐색 탐색 O(log n), 입력 삭제 불가능
// linked list 입력 삭제 O(1), 탐색은 O(n)
// 이진 트리는 inorder 방식으로 순회

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *left, *right;
} Node;

void addnode(Node** root, int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    if (*root == NULL){
        *root = newnode;
        return;
    }
    Node* ptr = *root; 
    while (ptr != NULL){
        if (value < ptr->data){
            ptr = ptr->left;
        }
        else if (value > ptr->data){
            ptr = ptr->right;
        }
        else
            return;
    } 
    ptr = newnode;
}

void print_inorder(Node* root){
    if (root == NULL)
        return;
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

int main(){ 
    Node * root = NULL;
    addnode(&root, 3);
    addnode(&root, 6);
    print_inorder(root);
    return 0;
}