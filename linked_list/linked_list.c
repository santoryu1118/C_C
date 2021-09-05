#include "linked_list.h"

// function definition

Node* create_node(int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// 필요한가?
Node* find_node(Node* head, int value){
    for (Node* p = head; p!= NULL; p = p->next){
        if (p->data ==value){
            return p;
        }
    }
    return NULL;
}

// 해당 position에 새로운 node insert
void insert_node(Node** head_ptr, int value, unsigned pos){
    Node* new_node = create_node(value);

    // head_ptr은 head의 주소값을 가지는 pointer의 pointer
    // 맨 앞에 연결해 주어야할떄
     if (pos == 0){
        new_node->next = *head_ptr;
        *head_ptr = new_node;
        return;
    }
   
    // p는 head의 주소값을 받는거임
    Node* p = *head_ptr;
    for (int idx = 0; idx < pos -1 && p->next != NULL; idx++, p = p->next);
    // for loop에서 가져온 p 뒤에 연결해주면 됨 
    new_node->next = p->next;
    p->next = new_node;
}

// delete 할 시에는 포인터 두개잡고 prev node도 들고 있어야됨 
void delete_node(Node** head_ptr, int value){
    Node* prev_node = NULL;
    Node* curr_node = *head_ptr;
    for (curr_node; curr_node->data != value && curr_node!= NULL;){
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (curr_node != NULL){
        if (curr_node == *head_ptr)
            *head_ptr = (*head_ptr)->next;
        else
            prev_node->next = curr_node->next;

        free(curr_node);
    }
}

// 싹다 지워주는 함수
void delete_all(Node** head){
    //base case
    if (*head == NULL)
        return;
    delete_all(&((*head)->next));
    // printf("%d", head->data);
    free(*head);
    *head = NULL;
}

// Head 부터 출력해주는 함수
void print(Node* head){
    Node* p = head;
    while (p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
