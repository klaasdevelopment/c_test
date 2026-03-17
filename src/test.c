#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Point {
	unsigned int x;
	unsigned int y;
	unsigned int z;
} Point;


void printPoint(Point *p) {
	printf("Point x:%d y:%d z:%d.\n", p->x, p->y, p->z);
}

int main(int argc, char const *argv[])
{
	    
	Point *p = malloc(sizeof(Point));
	p->x=3;
	p->y=9;
	p->z=2;
	
	printPoint(p);

	return 0;
}
