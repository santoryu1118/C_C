#include "rbtree.h"

#include <stdlib.h>
#include<stdio.h>

void print_tree(node_t* t){
  if (t){
    print_tree(t->left);
    printf("%d(%d)", t->key, t->color);
    print_tree(t->right);
  }
}

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(sizeof(rbtree), 1);
  return p;
}

// helper function for delete_rbtree
void helper_delete_rbtree(node_t* p){
  if (p == NULL)
    return;
  helper_delete_rbtree(p->left);
  helper_delete_rbtree(p->right);
  free(p);
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  helper_delete_rbtree(t->root);
  free(t);
}

// rotate 함수에는 항상 윗 노드가 들어감
// helper function for insertion_fixup
void left_rotate(rbtree *t, node_t* z){
  /*
        z              child  
         \      ->    /
          child      z 
  해줘야 할 거 list
  1. z의 오른쪽에 child 의 왼쪽 연결
  2. child의 왼쪽의 부모를 z로 설정
  3. z 부모가 root인지 확인
  4. z부모의 왼쪽이나 오른쪽에 child연결
  5. child의 부모를 z의 부모로 설정
  6. z의 부모를 child로 설정
  7. child의 왼쪽을 z로 설정
  */
  node_t* child = z->right;

  z->right = child->left;
  if (child->left)
    child->left->parent = z;
  
  if (!z->parent)
    t->root = child;
  else if (z == z->parent->left)
    z->parent->left = child;
  else if (z == z->parent->right)
    z->parent->right = child;

  child->parent = z->parent;
  z->parent = child;
  child->left = z;
}

// helper function for insertion_fixup
void right_rotate(rbtree *t, node_t* z){
  /*     z         child  
       /      ->       \
      child             z
  */
  node_t* child = z->left;
  z->left = child->right;
  if (child->right)
    child->right->parent = z;
  
  if (!z->parent)
    t->root = child;
  else if (z == z->parent->left)
    z->parent->left = child;
  else if (z == z->parent->right)
    z->parent->right = child;
  
  child->parent = z->parent;
  z->parent = child;
  child->right = z;
} 

// helper function for rbtree_insert
void insertion_fixup(rbtree* t, node_t* z){

  // 검은색이 될때까지 도는거임
  while (z!= t->root && z->parent->color == RBTREE_RED){
    node_t* parents = z->parent;
    node_t* grandparents = parents->parent;

    //parent가 왼쪽 자식이면
    if (parents == grandparents->left){
      node_t* uncle = grandparents->right;

      //case1: uncle이 없거나 uncle이 검은색일 때
      if (!uncle || uncle->color == RBTREE_BLACK){
        // 2-1. 내가 부모의 오른쪽 자식일 때
        if(z == parents->right){
          z = parents;
          left_rotate(t, z);
          // left rotate 후에 z는 또 다시 child node가 됨
        }
        // case3: (2-2). 내가 부모의 왼쪽 자식일 때 
        z->parent->color = RBTREE_BLACK;
        grandparents->color = RBTREE_RED;
        right_rotate(t, grandparents);
      }

      //case2: parent, uncle 둘다 빨간색일 때
      //이때는  z = grandparents 또 double red 가능성 있기 때문에 while문 한번 더 체크
      else if (uncle->color == RBTREE_RED){
        parents->color = uncle->color = RBTREE_BLACK;
        grandparents->color = (grandparents == t->root) ? RBTREE_BLACK : RBTREE_RED ;
        z = grandparents;
      }
    }

    else if (parents == grandparents->right){
      node_t* uncle = grandparents->left;

      //case1: uncle이 검은색일 때
      if (!uncle || uncle->color == RBTREE_BLACK){
        // 부모의 왼쪽 자식일 때
        if(z == parents->left){
          z= z->parent;
          right_rotate(t,z);
        }
        // 부모의 오른쪽 자식일 때
        z->parent->color = RBTREE_BLACK;
        grandparents->color = RBTREE_RED;
        left_rotate(t, grandparents);
      }
      //case2: parent, uncle둘다 빨간색일 때
      else if (uncle->color == RBTREE_RED){
        parents->color = uncle->color = RBTREE_BLACK;
        grandparents->color = (grandparents == t->root) ? RBTREE_BLACK : RBTREE_RED ;
        z = grandparents;
      }
    }
  }
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t* newnode = (node_t*)calloc(1, sizeof(node_t));
  newnode->color = RBTREE_RED;
  newnode->key = key;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->parent = NULL;

  if (t->root == NULL){
    newnode->color = RBTREE_BLACK;
    t->root = newnode;
    return t->root;
  }
  node_t* parent = NULL;
  node_t* current = t->root;
  while (current){
    parent = current;
    if (current->key > key)
      current = current ->left;
    else if (current->key < key)
      current = current ->right;
    // key값이 이미 있을 때  
    else
      return t->root;
  }
  // 새로운 값의 부모 update
  newnode->parent = parent;
  // 부모 값의 left || right update
  if (parent->key > key)
    parent->left = newnode;
  else
    parent->right = newnode;

  insertion_fixup(t, newnode);

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase

  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}