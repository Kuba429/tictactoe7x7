#include "../include/main.h"
#include "../include/ai.h"
#include "../include/cell.h"
#include "../include/dev_help.h"
#include "../include/result.h"
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
  struct Position lastInsertedCell = {-1, -1};
  if (IsKeyDown(KEY_R)) {
    *state = NewState();
  }
  if (state->isGameOver)
    return;
  if (state->isPlayersTurn && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    struct Position cell = GetHoveredCellPosition();
    int *val = &state->board[cell.y][cell.x];
    if (*val == 0) {
      *val = 1;
      lastInsertedCell = cell;
      state->isPlayersTurn = false;
    }
  } else if (state->isThinking) {
    // make the best move
    struct Position bestMove = GetBestMove(state->board);
    if (bestMove.x == -1)
      printf("SOMETHING WENT WRONG\n");
    state->board[bestMove.y][bestMove.x] = 2;
    lastInsertedCell = bestMove;
    state->isThinking = false;
    state->isPlayersTurn = true;
  }
  if (lastInsertedCell.x == -1 || lastInsertedCell.y == -1)
    return;
  // check if the game is over
  struct ListNode *winner =
      GetWinningStreak(state->board, lastInsertedCell.x, lastInsertedCell.y);
  if (winner != NULL) {
    state->isGameOver = true;
    state->winner = winner;
  } else {
    state->isGameOver = IsBoardFull(state->board);
  }
  if (!state->isPlayersTurn) {
    // kind of a buffer to let UI update and stuff
    state->isThinking = true;
  }
  // reset lastInsertedCell so looking for winner can be skipped until something
  // changes
  lastInsertedCell.x = -1;
  lastInsertedCell.y = -1;
}

void DrawFrame(struct State *state) {
  BeginDrawing();

  ClearBackground(BLACK);
  DrawCells(state->board);
  //   DisplayMousePosition();
  //   DisplayCellPosition(GetMousePosition());
  if (state->isGameOver) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                  (Color){0, 0, 0, 50});
    int fontSize = 70;
    char *text = "It's a draw!";
    if (state->winner != NULL) {
      // someone won
      DrawWinningCells(state->board, *state->winner);
      text = "Someone won!";
      int winner = state->board[state->winner->y][state->winner->x];
      if (winner == 1)
        text = "You won!";
      else
        text = "You lost";
    } else {
      // it's a draw
      text = "It's a draw!";
    }
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, GetScreenWidth() / 2 - textWidth / 2,
             GetScreenHeight() / 2 - fontSize / 2, fontSize, BLACK);
  }
  // Indicate that the AI is thinking
  if (state->isThinking && !state->isGameOver) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                  (Color){0, 0, 0, 50});
    int fontSize = 70;
    char *text = "I'm thinking...";
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, GetScreenWidth() / 2 - textWidth / 2,
             GetScreenHeight() / 2 - fontSize / 2, fontSize, BLACK);
  }

  EndDrawing();
}
