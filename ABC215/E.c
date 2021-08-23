#include<stdio.h>

typedef struct node {
  const int num;
  int depth;
  struct node* child;
  struct node* next;
} node_t;

void append(const int num, node_t *parent, node_t *node){
  node->num = num;
  node->depth = 0;
  node->child = NULL;
  node->next = NULL;
  if (parent == NULL) return;
  node->depth = parent->depth + 1;
  if (parent->child == NULL)
  {
    parent->child = node;
  }
  else
  {
    node_t* last = parent->child;
    while (last->next != NULL)
    {
      last = last->next;
    }
    last->next = node;
  }
}