#include "triangle.h"
#include "raymath.h"

void Triangle::Update() {
	// Update the circle position
 rotation = 90;
}

void Triangle::Draw() {
	DrawTriangle({ position + Vector2{ -size / 2, size / 2 } },
		{ position + Vector2{ size / 2, size / 2 } },
		{ position + Vector2{ 0, -size / 2 } },
		color);

	//Triangle t{ position - Vector2{ size / 2, size / 2 }, size, color };

	//Rectangle r{ position.x, position.y, size, size };
	//DrawRectanglePro(r, Vector2{ size / 2, size / 2 }, rotation, color);
}