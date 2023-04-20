#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
	double x;
	double y;
}Point;

double distance(Point p1, Point p2){
    double xDist = p1.x - p2.x;
    double yDist = p1.y - p2.y;
    double totalDist = sqrt((xDist * xDist) + (yDist * yDist));
    return totalDist;
}

int main(int argc, char* argv[]){
    FILE* file = fopen(argv[1], "rb");
    int num1, num2;
    Point point1, point2, originalPoint;
    double length = 0;
    fread(&num1, sizeof(int), 1, file);
    fread(&num1, sizeof(int), 1, file);
    fread(&num2, sizeof(int), 1, file);
    point1.x = (double) num1;
    point1.y = (double) num2;
    originalPoint = point1;
    while(!feof(file)){
        point2 = point1;
        fread(&num1, sizeof(int), 1, file);
        fread(&num2, sizeof(int), 1, file);
        point1.x = (double) num1;
        point1.y = (double) num2;
        length += distance(point1, point2);
    }
    length += distance(originalPoint, point1);
    printf("The perimeter is %.2lf\n", length);
    return 0;
}
