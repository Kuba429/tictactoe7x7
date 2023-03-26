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
// returns head of the merged list (head of the first argument)
struct ListNode *MergeLists(struct ListNode *head1, struct ListNode *head2) {
  if (head1 == NULL)
    return head2;
  if (head2 == NULL)
    return head1;
  struct ListNode *lastOfList1 = head1;
  struct ListNode *firstOfList2 = head2;
  while (lastOfList1->next != NULL) {
    lastOfList1 = lastOfList1->next;
  }

  while (firstOfList2->previous != NULL) {
    firstOfList2 = firstOfList2->previous;
  }
  lastOfList1->next = firstOfList2;
  while (head1->previous != NULL)
    head1 = head1->previous;
  return head1;
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
