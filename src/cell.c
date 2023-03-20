#include "raylib.h"

#ifndef CELL
#define CELL

void DrawCells(int board[7][7]);
void DrawCell(int board[7][7], int x, int y);
Vector2 GetHoveredCellPosition();

void DrawCells(int board[7][7]) {
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      DrawCell(board, x, y);
    }
  }
}

void DrawCell(int board[7][7], int x, int y) {
  int cellWidth = GetScreenWidth() / 7;
  x = x * (cellWidth + 1);
  y = y * (cellWidth + 1);
  DrawRectangle(x, y, cellWidth - 2, cellWidth - 2, WHITE);
}

Vector2 GetHoveredCellPosition() {
  Vector2 position = GetMousePosition();
  float cellWidth = (float)GetScreenWidth() / 7;
  position.x /= cellWidth;
  position.y /= cellWidth;
  return position;
}

#endif