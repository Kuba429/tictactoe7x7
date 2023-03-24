#include "../include/main.h"
#include "../include/ai.h"
#include "../include/cell.h"
#include "../include/dev_help.h"
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
  if (state->isPlayersTurn && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    struct Position cell = GetHoveredCellPosition();
    int *val = &state->board[cell.y][cell.x];
    if (*val == 0) {
      *val = 1;
      state->isPlayersTurn = false;
    }
  } else if (!state->isPlayersTurn && !state->isThinking) {
    // make the best move
    state->isThinking = true;
    struct Position bestMove = GetBestMove(state->board);
    state->board[bestMove.y][bestMove.x] = 2;
    state->isThinking = false;
    state->isPlayersTurn = true;
  }
}

void DrawFrame(struct State *state) {
  BeginDrawing();

  ClearBackground(BLACK);
  DrawCells(state->board);
  DisplayMousePosition();
  DisplayCellPosition(GetMousePosition());

  EndDrawing();
}
