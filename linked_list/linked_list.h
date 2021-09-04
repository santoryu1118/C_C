#include <stdio.h>
#include <stdlib.h>  //malloc 헤더 파일

typedef struct _Node{  //구조체 이름 _Node
    int data;
    Node* next;
} Node;  // 구조체 별칭 Node

// function declaration
// Node* create_node();
// void add_node(Node* curr_node);
// void delete_node();

