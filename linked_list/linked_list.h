#include <stdio.h>
#include <stdlib.h>  //malloc 헤더 파일

typedef struct _Node{  //구조체 이름 _Node
    int data;
    struct _Node* next;
} Node;  // 구조체 별칭 Node

// function declaration

Node* create_node(int);
Node* find_node(Node*, int);
void insert_node(Node**, int, unsigned);
void delete_node(Node**, int);
void delete_all(Node**);
void print(Node*);
