#include "raylib.h"
#include <stdio.h>

int windowHeight = 600;
int windowWidth = 600;

void DrawFrame();
void DrawMousePosition();
void GetCellPosition(Vector2 mousePosition);

int main() {
  InitWindow(windowWidth, windowHeight, "TicTacToe 7x7");
  while (!WindowShouldClose()) {
    DrawFrame();
  }
  return 0;
}

void DrawFrame() {
  BeginDrawing();

  ClearBackground(WHITE);
  //  for (int i = 1; i < 7; i++) {
  //    //                                  👇 make sure lines are included
  //    int step = (windowHeight / 7) * i + (i - 1) * 2;
  //    DrawLineEx((Vector2){0, step}, (Vector2){windowWidth, step}, 2.0,
  //    BLACK); DrawLineEx((Vector2){step, 0}, (Vector2){step,
  //    windowHeight}, 2.0, BLACK);
  //  }
  DrawMousePosition();
  GetCellPosition(GetMousePosition());

  EndDrawing();
}

void GetCellPosition(Vector2 mousePosition) {
  char str[10];
  int x = mousePosition.x / ((float)windowWidth / 7);
  sprintf(str, "%d", (int)x);
  DrawText(str, 1, 20, 20, BLACK);
}

void DrawMousePosition() {
  Vector2 mousePosition = GetMousePosition();
  char positionStr[11];
  sprintf(positionStr, "%d,%d", (int)mousePosition.x, (int)mousePosition.y);
  DrawText(positionStr, 1, 1, 20, BLACK);
}
