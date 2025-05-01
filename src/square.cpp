#include "square.h"
#include "raymath.h"

void Square::Update() {
	// Update the circle position
	rotation = 90;
}

void Square::Draw() {
	DrawRectangleV(position - Vector2{ size / 2, size / 2 }, Vector2{ size, size }, color);

	Rectangle r{ position.x, position.y, size, size };
	DrawRectanglePro(r, Vector2{ size / 2, size / 2 }, rotation, color);
}