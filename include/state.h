#include <stdbool.h>

#ifndef STATE_H
#define STATE_H
struct Position {
  int x;
  int y;
};

struct State {
  bool isThinking;
  bool isPlayersTurn;
  bool isGameOver;
  struct ListNode *winner;
  int board[7][7];
};

struct State NewState();
void ResetBoard(int[7][7]);
#endif
