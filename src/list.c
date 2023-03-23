#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>

void Push(struct ListNode *node, int x, int y) {
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
