// 이진 탐색 트리 Binary Search Tree
// 이진탐색과 linked list를 결합한 자료구조
// 이진탐색 탐색 O(log n), 입력 삭제 불가능
// linked list 입력 삭제 O(1), 탐색은 O(n)
// 이진 트리는 inorder 방식으로 순회

#include <stdio.h>
#include <stdlib.h>
#define True 1

typedef struct _Node{
    int data;
    struct _Node *parent, *left, *right;
} Node;

void addnode(Node**, int);
void delete_node(Node**, int);
void print_inorder(Node*);

int main(){ 
    Node * root = NULL;
    addnode(&root, 3);
    addnode(&root, 6);
    addnode(&root, 1);
    addnode(&root, 2);
    addnode(&root, 10);
    print_inorder(root); printf("\n");
    delete_node(&root, 4);
    delete_node(&root, 10);
    delete_node(&root, 3);
    addnode(&root, 20);
    addnode(&root, 2);
    addnode(&root, 10);
    print_inorder(root); printf("\n");
    return 0;
}


void addnode(Node** root, int value){
    // 새로운 노드 생성
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = value;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;

    // root 가 empty면
    if (! *root){
        *root = newnode;
        return;
    }

    Node* ptr = *root; 
    while (ptr){
        // newnode의 parent 업데이트
        newnode->parent = ptr;

        // left node로 가야될 때
        if (value < ptr->data){
            ptr = ptr->left;
        }
        // right node로 가야될 때
        else if (value > ptr->data){
            ptr = ptr->right;
        } 
        // 값이 이미 있을때 (중복값은 안넣어줌)
        else{
            free(newnode);
            return;
        }
    } 
    //부모의 left or right 업데이트
    Node *parents = newnode->parent; 
    if (parents->data < value){
        parents->right = newnode;
    } 
    else{
        parents->left = newnode;
    }
}

// child node가 없으면 그냥 지우면 됨
// 한개 있으면 parent node랑 child node랑 연결시키고 지우면 됨
// 두개 있으면 left subtree의 max값이나 right subtree의 min값이랑 swap 하고 지우면 됨
void delete_node(Node** root, int value){
    Node* current = *root;

    while (current && current->data != value){
        if (current->data < value){
            current = current->right;
        }
        else if (current->data > value){
            current = current->left;
        }
    }
    // 지울려는 value가 없으면
    if (! current)
        return;
    
    Node* parents = current->parent;

    // 1. 자식이 두개 있으면
    if(current->left && current->right){
        Node* swap = current->right;

        // swap값 왼쪽으로 쭈욱 탐색
        for(swap; swap->left; swap = swap->left);
        // current 값 swap값으로 바꾸기
        current->data = swap->data;
        // current 가 root node 일 경우
        if (! parents){
            *root = current;
            swap->parent->right = NULL;
        }
        else
            swap->parent->left = NULL;
        
        // 나중에 free current 위해서
        current = swap;
    }
    // 2. 지울려는 node의 자식이 없으면
    else if (! current->left  && ! current->right){
        // 지울려는 node가 head node면
        if (!parents) //(current == *root)
            *root = NULL;
        else{
            if (parents->left == current)
                parents->left = NULL;
            else
                parents->right = NULL;
        }
    }
    // 3. 자식이 하나 밖에 없는데 왼쪽 자식이면
    else if(current->left){
        if (!parents)
            *root = current->left;
        else{
            if (parents->right == current)
                parents->right = current->left;
            else
                parents->left = current->left;
        }
        current->left->parent = parents;
    }
    // 4. 자식이 하나 밖에 없는데 오른쪽 자식이면
    else if(current->right){
        if (!parents)
            *root = current->right;
        else{
            if (parents->right == current)
                parents->right = current->right;
            else
                parents->left = current->right;
        }
        current->right->parent = parents;
    }

    free(current);
}

void print_inorder(Node* root){
    if (! root)
        return;
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
}

