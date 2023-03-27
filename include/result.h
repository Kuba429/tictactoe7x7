#include "list.h"
struct ListNode *CheckHorizontal(int board[7][7], int x, int y);
struct ListNode *CheckVertical(int board[7][7], int x, int y);
struct ListNode *CheckCell(int board[7][7], int x, int y);
struct ListNode *CheckDiagonalTopRight(int board[7][7], int x, int y);
struct ListNode *CheckDiagonalTopLeft(int board[7][7], int x, int y);
