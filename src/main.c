#include "../include/main.h"
#include "../include/ai.h"
#include "../include/cell.h"
#include "../include/dev_help.h"
#include "../include/state.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  InitWindow(596, 596, "TicTacToe 7x7");
  struct State state = NewState();

  while (!WindowShouldClose()) {
    if (state.isPlayersTurn && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      Vector2 cell = GetHoveredCellPosition();
      int *val = &state.board[(int)cell.y][(int)cell.x];
      if (*val == 0) {
        *val = 1;
        state.isPlayersTurn = false;
      }
    } else if (!state.isPlayersTurn && !state.isThinking) {
      // make the best move
      struct Position bestMove = GetBestMove(state.board);
      state.board[bestMove.y][bestMove.x] = 2;
      state.isPlayersTurn = true;
    }
    DrawFrame(&state);
  }
  return 0;
}

void DrawFrame(struct State *state) {
  BeginDrawing();

  ClearBackground(BLACK);
  DrawCells(state->board);
  DisplayMousePosition();
  DisplayCellPosition(GetMousePosition());

  EndDrawing();
}
