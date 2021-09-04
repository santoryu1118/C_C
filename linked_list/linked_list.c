#include <linked_list.h>

// function definition

Node* create_node(int value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
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
void insert_node(Node* head, int value, unsigned pos){
    Node* new_node = create_node(value);
    Node* p = head;
    for (unsigned idx = 0; idx != pos && p->next != NULL; idx++, p = p->next);
    new_node->next = p->next;
    p->next = new_node;
}

// delete 할 시에는 포인터 두개잡고 prev node도 들고 있어야됨 
void delete_node(Node* head, int value){
    Node* prev_node = NULL;
    Node* curr_node;
    for (Node* curr_node = head; curr_node->data != value && curr_node!= NULL;){
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    if (curr_node != NULL){
        if (curr_node == head)
            head = head->next;
        else
            prev_node->next = curr_node->next;

        free(curr_node);
    }
}

void delete_all(Node* head){
    //base case
    if (head == NULL)
        return
    delete_all (head->next);
    free(head);
}

void print(Node* head){
    Node* p = head;
    while (p != NULL){
        printf(p->data);
    }
}

