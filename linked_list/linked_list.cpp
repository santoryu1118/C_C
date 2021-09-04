#include <linked_list.h>

// function definition

Node* create_node(){
    Node* new_node = (Node*)malloc(sizeof(Node));
    return new_node;
}

void add_node(Node* curr_node){
    Node* new_node = create_node();
    curr_node->next = new_node;
}

void delete_node(Node* curr_node){
    void *address = curr_node;
}

