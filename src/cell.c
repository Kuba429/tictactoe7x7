#include "../include/cell.h"
#include "../include/state.h"
#include "raylib.h"

#define HOVER_COLOR                                                            \
  (Color) { 0, 0, 0, 30 }

void DrawCells(int board[7][7]) {
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      DrawCell(board, x, y, WHITE);
    }
  }
  // highlight hovered cell
  struct Position cell = GetHoveredCellPosition();
  DrawCell(board, cell.x, cell.y, HOVER_COLOR);
}

void DrawCell(int board[7][7], int x, int y, Color color) {
  int cellWidth = GetScreenWidth() / 7;
  int screenX = x * (cellWidth + 1);
  int screenY = y * (cellWidth + 1);
  DrawRectangle(screenX, screenY, cellWidth - 2, cellWidth - 2, color);
  switch (board[y][x]) {
    // colors for now, will be shapes in the future
  case 1:
    DrawRectangle(screenX, screenY, cellWidth - 2, cellWidth - 2, RED);
    break;
  case 2:
    DrawRectangle(screenX, screenY, cellWidth - 2, cellWidth - 2, BLUE);
    break;
  }
}

struct Position GetHoveredCellPosition() {
  Vector2 mousePosition = GetMousePosition();
  float cellWidth = (float)GetScreenWidth() / 7;
  struct Position cellPosition = {mousePosition.x / cellWidth,
                                  mousePosition.y / cellWidth};
  return cellPosition;
}
