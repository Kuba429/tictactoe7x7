#include "../include/ai.h"
#include "../include/result.h"
#include "../include/state.h"
#include <stdlib.h>

int weights[7][7] = {{1, 1, 1, 1, 1, 1, 1}, {1, 2, 2, 2, 2, 2, 1},
                     {1, 2, 3, 3, 3, 2, 1}, {1, 2, 3, 4, 3, 2, 1},
                     {1, 2, 3, 3, 3, 2, 1}, {1, 2, 2, 2, 2, 2, 1},
                     {1, 1, 1, 1, 1, 1, 1}};

struct Position GetBestMove(int board[7][7]) {
  struct Position bestMove = {-1, -1};
  int bestScore = -10000;
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      if (board[y][x] != 0)
        continue;
      board[y][x] = 2;
      int score =
          Minimax(board, (struct Position){x, y}, 2, false, 5, -10000, 10000);
      board[y][x] = 0;
      // this is the best move if:
      // it's score is higher than the current highest
      // or it has the same score but is closer to the center
      if (score > bestScore ||
          (score == bestScore &&
           weights[y][x] > weights[bestMove.y][bestMove.x])) {
        bestMove.x = x;
        bestMove.y = y;
        bestScore = score;
      }
    }
  }
  return bestMove;
};

int Minimax(int board[7][7], struct Position lastCell, int turn,
            bool maximizing, int depth, int alpha, int beta) {
  int winner = GetWinner(board, lastCell.x, lastCell.y);
  if (winner != -1) {
    if (winner == 1)
      return -1 * (depth + 1);
    if (winner == 2)
      return 1 * (depth + 1);
  }
  if (depth < 1)
    return 0;
  if (maximizing) {
    int bestScore = -10000;
    for (int y = 0; y < 7; y++) {
      for (int x = 0; x < 7; x++) {
        if (board[y][x] != 0)
          continue;
        board[y][x] = 2;
        int newScore = Minimax(board, (struct Position){x, y}, 1, false,
                               depth - 1, alpha, beta);
        board[y][x] = 0;
        if (newScore > bestScore)
          bestScore = newScore;
        if (newScore > alpha)
          alpha = newScore;

        if (beta <= alpha)
          break;
      }
      if (beta <= alpha)
        break;
    }
    return bestScore;
  } else {
    int bestScore = 10000;
    for (int x = 0; x < 7; x++) {
      for (int y = 0; y < 7; y++) {
        if (board[y][x] != 0)
          continue;
        board[y][x] = 1;
        int newScore = Minimax(board, (struct Position){x, y}, 2, true,
                               depth - 1, alpha, beta);
        board[y][x] = 0;
        if (newScore < bestScore)
          bestScore = newScore;
        if (newScore < beta)
          beta = newScore;
        if (beta <= alpha)
          break;
      }
      if (beta <= alpha)
        break;
    }
    return bestScore;
  }
}
