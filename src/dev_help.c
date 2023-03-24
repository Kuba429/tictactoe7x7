#include "../include/dev_help.h"
#include "../include/cell.h"
#include "../include/state.h"
#include "raylib.h"
#include <stdio.h>

void DisplayCellPosition(Vector2 mousePosition) {
  char str[10];
  struct Position cellPosition = GetHoveredCellPosition();
  sprintf(str, "%d, %d", (int)cellPosition.x, (int)cellPosition.y);
  DrawText(str, 1, 20, 20, BLACK);
}

void DisplayMousePosition() {
  Vector2 mousePosition = GetMousePosition();
  char str[12];
  sprintf(str, "%d, %d", (int)mousePosition.x, (int)mousePosition.y);
  DrawText(str, 1, 1, 20, BLACK);
}
