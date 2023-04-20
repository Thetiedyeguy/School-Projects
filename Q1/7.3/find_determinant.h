#ifndef FIND_DETERMINANT
#define FIND_DETERMINANT

typedef struct Matrix{
	int rows;
	int cols;
    double** values;
}Matrix;

double** makeEmpty2dArray(int rows, int cols);
double determinant(Matrix originalMatrix);

#endif
