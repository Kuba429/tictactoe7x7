#include "../include/main.h"
#include "../include/ai.h"
#include "../include/cell.h"
#include "../include/dev_help.h"
#include "../include/result.h"
#include "../include/state.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int windowSize = 596;
  InitWindow(windowSize, windowSize, "TicTacToe 7x7");
  struct State state = NewState();

  while (!WindowShouldClose()) {
    Update(&state);
    DrawFrame(&state);
  }
  return 0;
}

void Update(struct State *state) {
  struct Position lastInsertedCell = {-1, -1};
  if (state->isGameOver)
    return;
  if (state->isPlayersTurn && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    struct Position cell = GetHoveredCellPosition();
    int *val = &state->board[cell.y][cell.x];
    if (*val == 0) {
      *val = 1;
      lastInsertedCell = cell;
      state->isPlayersTurn = false;
    }
  } else if (state->isThinking) {
    // make the best move
    struct Position bestMove = GetBestMove(state->board);
    if (bestMove.x == -1)
      printf("SOMETHING WENT WRONG\n");
    state->board[bestMove.y][bestMove.x] = 2;
    lastInsertedCell = bestMove;
    state->isThinking = false;
    state->isPlayersTurn = true;
  }
  if (lastInsertedCell.x == -1 || lastInsertedCell.y == -1)
    return;
  // check if the game is over
  struct ListNode *winner =
      GetWinningStreak(state->board, lastInsertedCell.x, lastInsertedCell.y);
  if (winner != NULL) {
    state->isGameOver = true;
    state->winner = winner;
  } else if (!state->isPlayersTurn) {
    // kind of a buffer to let UI update and stuff
    state->isThinking = true;
  }
  // reset lastInsertedCell so looking for winner can be skipped until something
  // changes
  lastInsertedCell.x = -1;
  lastInsertedCell.y = -1;
}

void DrawFrame(struct State *state) {
  BeginDrawing();

  ClearBackground(BLACK);
  DrawCells(state->board);
  //   DisplayMousePosition();
  //   DisplayCellPosition(GetMousePosition());
  if (state->isGameOver) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                  (Color){0, 0, 0, 50});
    DrawWinningCells(state->board, *state->winner);
  }
  // Indicate that the AI is thinking
  if (state->isThinking) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                  (Color){0, 0, 0, 50});
    int fontSize = 70;
    char *text = "I'm thinking...";
    int size = MeasureText(text, fontSize);
    DrawText(text, GetScreenWidth() / 2 - size / 2, GetScreenHeight() / 2,
             fontSize, BLACK);
  }

  EndDrawing();
}
