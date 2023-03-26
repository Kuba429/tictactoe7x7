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
  struct ListNode *winner = NULL;
  winner = MergeLists(winner, CheckHorizontal(board, x, y));
  winner = MergeLists(winner, CheckVertical(board, x, y));
  return winner;
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
  struct ListNode *head = Push(NULL, x, y);
  // avoid looping to the end of the list every time while still returning the
  // head
  struct ListNode *lastNode = head;
  for (int x = smallestX; x <= largestX; x++) {
    lastNode = Push(lastNode, x, y);
  }
  return head;
}

struct ListNode *CheckVertical(int board[7][7], int x, int y) {
  int original = board[y][x];
  int largestY = y;
  int smallestY = y;
  while (largestY + 1 < 7 && board[largestY + 1][x] == original) {
    largestY++;
  }
  while (smallestY - 1 >= 0 && board[smallestY - 1][x] == original) {
    smallestY--;
  }
  if (largestY <= smallestY || largestY - smallestY + 1 < 4) {
    return NULL;
  }
  struct ListNode *head = Push(NULL, x, y);
  struct ListNode *lastNode = head;
  for (int y = smallestY; y <= largestY; y++) {
    lastNode = Push(lastNode, x, y);
  }
  return head;
}
