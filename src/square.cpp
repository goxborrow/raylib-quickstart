#include "square.h"
#include "raymath.h"

void Square::Update() {
	// Update the circle position
}

void Square::Draw() {
	DrawRectangleV(position - Vector2{size/2, size/2}, Vector2{size, size}, color);
}