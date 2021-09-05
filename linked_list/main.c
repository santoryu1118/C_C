#include "linked_list.h"
// gcc linked_list.c main.c -o main
int main(){

    // head는 첫번째 node를 가리키는 struct pointer임
    Node* head = create_node(0);
    insert_node(&head, 1, 1);
    insert_node(&head, 1, 3);
    printf("%d: ", 1); print(head);

    delete_node(&head, 0);
    printf("%d: ", 2); print(head);
    
    insert_node(&head, 5, 2);
    insert_node(&head, 7, 0);
    delete_node(&head, 5);
    printf("%d: ", 3); print(head);
    
    delete_all(&head);
    printf("%d: ", 4);
    print(head);
    return 0;
}