#include "cell.c"
#include "dev_help.c"
#include "raylib.h"
#include <stdio.h>

void DrawFrame(int board[7][7]);
void ResetBoard(int[7][7]);

int main() {
  InitWindow(596, 596, "TicTacToe 7x7");

  int board[7][7];
  ResetBoard(board);

  while (!WindowShouldClose()) {
    DrawFrame(board);
  }
  return 0;
}

void DrawFrame(int board[7][7]) {
  BeginDrawing();

  ClearBackground(BLACK);
  DrawCells(board);
  DisplayMousePosition();
  DisplayCellPosition(GetMousePosition());

  EndDrawing();
}

void ResetBoard(int board[7][7]) {
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      board[y][x] = 0;
    }
  }
}
