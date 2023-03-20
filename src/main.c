#include "raylib.h"
#include <stdio.h>

int windowHeight = 596;
int windowWidth = 596;
int cellWidth = 596 / 7;

void DrawFrame(int board[7][7]);
void DrawCells(int board[7][7]);
void DrawCell(int board[7][7], int x, int y);
void DisplayMousePosition();
void DisplayCellPosition(Vector2 mousePosition);
void ResetBoard(int[7][7]);
Vector2 GetHoveredCellPosition();

int main() {
  InitWindow(windowWidth, windowHeight, "TicTacToe 7x7");

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

void DrawCell(int board[7][7], int x, int y);

void DrawCells(int board[7][7]) {
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      DrawCell(board, x, y);
    }
  }
}
void DrawCell(int board[7][7], int x, int y) {
  x = x * (cellWidth + 1);
  y = y * (cellWidth + 1);
  DrawRectangle(x, y, cellWidth - 2, cellWidth - 2, WHITE);
}

void ResetBoard(int board[7][7]) {
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      board[y][x] = 0;
    }
  }
}

Vector2 GetHoveredCellPosition() {
  Vector2 mousePosition = GetMousePosition();
  mousePosition.x /= (float)windowWidth / 7;
  mousePosition.y /= (float)windowHeight / 7;
  return mousePosition;
}

void DisplayCellPosition(Vector2 mousePosition) {
  char str[10];
  Vector2 cellPosition = GetHoveredCellPosition();
  sprintf(str, "%d, %d", (int)cellPosition.x, (int)cellPosition.y);
  DrawText(str, 1, 20, 20, BLACK);
}

void DisplayMousePosition() {
  Vector2 mousePosition = GetMousePosition();
  char positionStr[12];
  sprintf(positionStr, "%d, %d", (int)mousePosition.x, (int)mousePosition.y);
  DrawText(positionStr, 1, 1, 20, BLACK);
}
