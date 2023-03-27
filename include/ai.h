#include "state.h"

struct Position GetBestMove(int board[7][7]);
int Minimax(int board[7][7], struct Position lastCell, int turn,
            bool maximizing, int depth, int alpha, int beta);
