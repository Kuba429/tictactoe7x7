#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>

void Push(struct ListNode *node, int x, int y) {
  // if this is an "empty" node freshly created with NewList function, assign
  // given values to the head(the only node)
  if (node->x == -1 && node->y == -1) {
    node->x = x;
    node->y = y;
    node->previous = NULL;
    node->next = NULL;
    return;
  }
  struct ListNode *oldLast = node;
  while (oldLast->next != NULL) {
    oldLast = oldLast->next;
  }
  struct ListNode *newLast = malloc(sizeof(struct ListNode));
  newLast->next = NULL;
  newLast->previous = oldLast;
  newLast->x = x;
  newLast->y = y;

  oldLast->next = newLast;
}

void FreeList(struct ListNode *node) {
  struct ListNode *current = node->next;
  // go forward (next)
  while (current != NULL) {
    struct ListNode *toDelete = current;
    current = current->next;
    free(toDelete);
  }
  // go back (previous)
  current = node->previous;
  while (current != NULL) {
    struct ListNode *toDelete = current;
    current = current->previous;
    free(toDelete);
  }
  free(node);
}

struct ListNode *NewList() {
  struct ListNode *node = malloc(sizeof(struct ListNode));
  node->x = -1;
  node->y = -1;
  node->previous = NULL;
  node->next = NULL;
  return node;
}
