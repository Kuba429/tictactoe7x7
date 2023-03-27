#include "../include/result.h"
#include <stdlib.h>

struct ListNode *CheckCell(int board[7][7], int x, int y) {
  struct ListNode *winner = NULL;
  winner = MergeLists(winner, CheckHorizontal(board, x, y));
  winner = MergeLists(winner, CheckVertical(board, x, y));
  winner = MergeLists(winner, CheckDiagonalTopLeft(board, x, y));
  winner = MergeLists(winner, CheckDiagonalTopRight(board, x, y));
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

struct ListNode *CheckDiagonalTopLeft(int board[7][7], int x, int y) {
  int original = board[y][x];
  int largestY = y;
  int largestX = x;
  int smallestY = y;
  int smallestX = x;

  // Check diagonal from top-left to bottom-right
  while (largestY + 1 < 7 && largestX + 1 < 7 &&
         board[largestY + 1][largestX + 1] == original) {
    largestY++;
    largestX++;
  }
  while (smallestY - 1 >= 0 && smallestX - 1 >= 0 &&
         board[smallestY - 1][smallestX - 1] == original) {
    smallestY--;
    smallestX--;
  }
  if (largestY - smallestY + 1 < 4) {
    // Not a win
    return NULL;
  }

  struct ListNode *head = Push(NULL, x, y);
  struct ListNode *lastNode = head;
  for (int i = smallestY, j = smallestX; i <= largestY && j <= largestX;
       i++, j++) {
    lastNode = Push(lastNode, j, i);
  }

  return head;
}

struct ListNode *CheckDiagonalTopRight(int board[7][7], int x, int y) {
  int original = board[y][x];
  int largestY = y;
  int largestX = x;
  int smallestY = y;
  int smallestX = x;

  // Check diagonal from top-right to bottom-left
  while (largestY + 1 < 7 && smallestX - 1 >= 0 &&
         board[largestY + 1][smallestX - 1] == original) {
    largestY++;
    smallestX--;
  }
  while (smallestY - 1 >= 0 && largestX + 1 < 7 &&
         board[smallestY - 1][largestX + 1] == original) {
    smallestY--;
    largestX++;
  }
  if (largestY - smallestY + 1 < 4) {
    // Not a win
    return NULL;
  }

  struct ListNode *head = Push(NULL, x, y);
  struct ListNode *lastNode = head;
  for (int i = smallestY, j = largestX; i <= largestY && j >= smallestX;
       i++, j--) {
    lastNode = Push(lastNode, j, i);
  }

  return head;
}
