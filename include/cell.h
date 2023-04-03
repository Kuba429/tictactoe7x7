#include "list.h"
#include "raylib.h"

void DrawCells(int board[7][7]);
bool IsBoardFull(int board[7][7]);
void DrawCell(int board[7][7], int x, int y, Color color);
void DrawWinningCells(int board[7][7], struct ListNode winner);
struct Position GetHoveredCellPosition();
