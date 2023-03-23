#include "cell.c"
#include "dev_help.c"
#include "raylib.h"
#include "state.c"

void DrawFrame(struct State *state);

int main() {
  InitWindow(596, 596, "TicTacToe 7x7");
  struct State state = NewState();

  while (!WindowShouldClose()) {
    if (state.isPlayersTurn && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      Vector2 cell = GetHoveredCellPosition();
      int *val = &state.board[(int)cell.y][(int)cell.x];
      if (*val == 0)
        *val = 1;
      state.isPlayersTurn = false;
    } else if (!state.isPlayersTurn && !state.isThinking) {
      // make the best move
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
