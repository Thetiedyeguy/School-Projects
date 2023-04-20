#ifndef DRAW
#define DRAW

void horizontalLine(int row, int startCol, int endCol, Matrix canvas);
void verticalLine(int col, int startRow, int endRow, Matrix canvas);
void diagonalLine(int startRow, int endRow, int startCol, int endCol, Matrix canvas);

#endif
