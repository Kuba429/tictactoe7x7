#ifndef LIST_NODE
#define LIST_NODE
struct ListNode {
  int x;
  int y;
  struct ListNode *previous;
  struct ListNode *next;
};

struct ListNode *Push(struct ListNode *node, int x, int y);
void FreeList(struct ListNode *node);
struct ListNode *MergeLists(struct ListNode *head1, struct ListNode *head2);
#endif
