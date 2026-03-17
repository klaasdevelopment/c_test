#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raylib.h"

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
	// Initialize window
	InitWindow(800, 600, "raylib - Point Demo");
	SetTargetFPS(60);
	
	// Create a point
	Point *p = malloc(sizeof(Point));
	p->x = 400;
	p->y = 300;
	p->z = 0;
	
	printPoint(p);
	
	// Main loop
	while (!WindowShouldClose()) {
		// Update
		if (IsKeyPressed(KEY_RIGHT)) p->x += 10;
		if (IsKeyPressed(KEY_LEFT)) p->x -= 10;
		if (IsKeyPressed(KEY_UP)) p->y -= 10;
		if (IsKeyPressed(KEY_DOWN)) p->y += 10;
		
		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		// Draw point as a circle
		DrawCircle(p->x, p->y, 10, BLUE);
		DrawText("Use arrow keys to move", 10, 10, 20, DARKGRAY);
		
		EndDrawing();
	}
	
	CloseWindow();
	free(p);
	
	return 0;
}
