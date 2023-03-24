#include "../include/ai.h"
#include "../include/state.h"

struct Position GetBestMove(int board[7][7]) {
  struct Position p = {0, 0};
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      if (board[y][x] == 0) {
        p.x = x;
        p.y = y;
        return p;
      }
    }
  }
  return p;
};
