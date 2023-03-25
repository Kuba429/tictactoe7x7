#include "../include/result.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode *GetWinner(int board[7][7]) {
  //
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      if (board[y][x] == 0)
        continue;
      struct ListNode *winner = CheckCell(board, x, y);
      if (winner != NULL) {
        return winner;
      }
    }
  }
  return NULL;
}
struct ListNode *CheckCell(int board[7][7], int x, int y) {
  struct ListNode *horizontal = CheckHorizontal(board, x, y);
  return horizontal;
}
struct ListNode *CheckHorizontal(int board[7][7], int x, int y) {
  int original = board[y][x];
  int largestX = x;
  int smallestX = x;
  // go right untill first occurence of different value
  while (largestX + 1 < 7 && board[y][largestX + 1] == original) {
    largestX++;
  }
  // then go left
  while (smallestX - 1 >= 0 && board[y][smallestX - 1] == original) {
    smallestX--;
  }
  // return null if not enough cells with the same value were next to each other
  if (largestX <= smallestX || largestX - smallestX + 1 < 4) {
    return NULL;
  }
  struct ListNode *head = NewList();
  for (int x = smallestX; x <= largestX; x++) {
    Push(head, x, y);
  }
  return head;
}
