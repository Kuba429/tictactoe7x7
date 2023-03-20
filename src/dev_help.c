#include "cell.c"
#include "raylib.h"
#include <stdio.h>

void DisplayMousePosition();
void DisplayCellPosition(Vector2 mousePosition);

void DisplayCellPosition(Vector2 mousePosition) {
  char str[10];
  Vector2 cellPosition = GetHoveredCellPosition();
  sprintf(str, "%d, %d", (int)cellPosition.x, (int)cellPosition.y);
  DrawText(str, 1, 20, 20, BLACK);
}

void DisplayMousePosition() {
  Vector2 mousePosition = GetMousePosition();
  char str[12];
  sprintf(str, "%d, %d", (int)mousePosition.x, (int)mousePosition.y);
  DrawText(str, 1, 1, 20, BLACK);
}
