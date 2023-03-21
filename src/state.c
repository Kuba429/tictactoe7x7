struct State {
  int board[7][7];
};

void ResetBoard(int[7][7]);

struct State NewState() {
  struct State state = {};
  ResetBoard(state.board);
  return state;
}

void ResetBoard(int board[7][7]) {
  for (int y = 0; y < 7; y++) {
    for (int x = 0; x < 7; x++) {
      board[y][x] = 0;
    }
  }
}
