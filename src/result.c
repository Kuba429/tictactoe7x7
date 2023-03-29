#include "../include/result.h"
#include <stdlib.h>

struct ListNode *GetWinningStreak(int board[7][7], int x, int y) {
  struct ListNode *winner = NULL;
  winner = MergeLists(winner, GetHorizontalWinningStreak(board, x, y));
  winner = MergeLists(winner, GetVerticalWinningStreak(board, x, y));
  winner = MergeLists(winner, GetDiagonalTopLeftWinningStreak(board, x, y));
  winner = MergeLists(winner, GetDiagonalTopRightWinningStreak(board, x, y));
  return winner;
}
int GetWinner(int board[7][7], int x, int y) {
  if (GetHorizontalWinner(board, x, y) != -1 ||
      GetVerticalWinner(board, x, y) != -1 ||
      GetDiagonalTopRightWinner(board, x, y) != -1 ||
      GetDiagonalTopLeftWinner(board, x, y) != -1) {
    return board[y][x];
  }
  return -1;
}
// Get*WinningStreak returns linked list of nodes that decided about the result
// Get*Winner only returns the winner (so 1,2 or -1)

int GetHorizontalWinner(int board[7][7], int x, int y) {
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
  // no winner if not enough cells with the same value next to each other
  if (largestX <= smallestX || largestX - smallestX + 1 < 4) {
    return -1;
  }
  return original;
}

struct ListNode *GetHorizontalWinningStreak(int board[7][7], int x, int y) {
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
  for (int newX = smallestX; newX <= largestX; newX++) {
    lastNode = Push(lastNode, newX, y);
  }
  return head;
}

int GetVerticalWinner(int board[7][7], int x, int y) {
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
    return -1;
  }
  return original;
}

struct ListNode *GetVerticalWinningStreak(int board[7][7], int x, int y) {
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
  for (int newY = smallestY; newY <= largestY; newY++) {
    lastNode = Push(lastNode, x, newY);
  }
  return head;
}

int GetDiagonalTopLeftWinner(int board[7][7], int x, int y) {
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
  // then go the other way
  while (smallestY - 1 >= 0 && smallestX - 1 >= 0 &&
         board[smallestY - 1][smallestX - 1] == original) {
    smallestY--;
    smallestX--;
  }
  if (largestY - smallestY + 1 < 4) {
    // Not a win
    return -1;
  }
  return original;
}

struct ListNode *GetDiagonalTopLeftWinningStreak(int board[7][7], int x,
                                                 int y) {
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
  for (int newY = smallestY, newX = smallestX;
       newY <= largestY && newX <= largestX; newY++, newX++) {
    lastNode = Push(lastNode, newX, newY);
  }

  return head;
}

int GetDiagonalTopRightWinner(int board[7][7], int x, int y) {
  int original = board[y][x];
  int largestY = y;
  int largestX = x;
  int smallestY = y;
  int smallestX = x;

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
    return -1;
  }
  return original;
}
struct ListNode *GetDiagonalTopRightWinningStreak(int board[7][7], int x,
                                                  int y) {
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
  for (int newY = smallestY, newX = largestX;
       newY <= largestY && newX >= smallestX; newY++, newX--) {
    lastNode = Push(lastNode, newX, newY);
  }

  return head;
}
