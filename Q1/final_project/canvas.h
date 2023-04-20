#ifndef CANVAS
#define CANVAS

typedef struct Matrix{
	int rows;
	int cols;
    char** values;
}Matrix;

void freeCanvas(Matrix canvas);
char** create_canvas(int rows, int cols);
int print_canvas(char** canvas, int rows, int cols);

#endif
