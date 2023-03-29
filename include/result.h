#include "list.h"
struct ListNode *GetHorizontalWinningStreak(int board[7][7], int x, int y);
struct ListNode *GetVerticalWinningStreak(int board[7][7], int x, int y);
struct ListNode *GetWinningStreak(int board[7][7], int x, int y);
struct ListNode *GetDiagonalTopRightWinningStreak(int board[7][7], int x,
                                                  int y);
struct ListNode *GetDiagonalTopLeftWinningStreak(int board[7][7], int x, int y);
