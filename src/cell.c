#include "../include/cell.h"
#include "../include/state.h"
#include "raylib.h"
#include <stdio.h>

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
bool IsBoardFull(int board[7][7]) {
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      if (board[y][x] == 0)
        return false;
    }
  }
  return true;
}

void DrawCell(int board[7][7], int x, int y, Color color) {
  int cellWidth = GetScreenWidth() / 7;
  int screenX = x * (cellWidth + 1);
  int screenY = y * (cellWidth + 1);
  DrawRectangle(screenX, screenY, cellWidth - 2, cellWidth - 2, color);
  switch (board[y][x]) {
    // Player 1, draw X symbol
  case 1: {
    DrawLineEx((Vector2){screenX + 10, screenY + 10},
               (Vector2){screenX + cellWidth - 10, screenY + cellWidth - 10}, 5,
               RED);
    DrawLineEx((Vector2){screenX + cellWidth - 10, screenY + 10},
               (Vector2){screenX + 10, screenY + cellWidth - 10}, 5, RED);
    break;
  }
  // Player 2, draw O symbol
  case 2: {
    int centerX = screenX + cellWidth / 2;
    int centerY = screenY + cellWidth / 2;
    int innerRadius = cellWidth / 2 - 15;
    int outerRadius = cellWidth / 2 - 10;
    DrawRing((Vector2){centerX, centerY}, innerRadius, outerRadius, 0, 360, 32,
             BLUE);
    break;
  }
  }
}

void DrawWinningCells(int board[7][7], struct ListNode node) {
  while (node.previous != NULL) {
    node = *node.previous;
  }
  while (node.next != NULL) {
    DrawCell(board, node.x, node.y, WHITE);
    node = *node.next;
  }
  DrawCell(board, node.x, node.y, WHITE);
}

struct Position GetHoveredCellPosition() {
  Vector2 mousePosition = GetMousePosition();
  float cellWidth = (float)GetScreenWidth() / 7;
  struct Position cellPosition = {mousePosition.x / cellWidth,
                                  mousePosition.y / cellWidth};
  return cellPosition;
}
