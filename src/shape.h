#pragma once
#include "raylib.h"

class Shape {
public:
	// Update in shape.h
	enum class Type {
		CIRCLE,
		SQUARE,
		TRIANGLE,
		IMAGE,
		NumShapes
	};

public:
	Shape() = default;
	Shape(const Vector2& pos, float s = 20, const Color& c = WHITE) : position(pos), size(s), color(c) {
	
	}

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual Type GetType()  = 0;

	const Vector2& GetPosition() const {
		return position;
	}
	void SetPosition(const Vector2& pos) {
		position = pos;
	}

	float GetSize() const {
		return size;
	}
	void SetSize(float s) {
		size = s;
	}
	const Color& GetColor() const {
		return color;
	}
	void SetColor(const Color& c) {
		color = c;
	}

protected:
	// position of the shape
	Vector2 position = { 0, 0 };
	float size = 20;
	Color color = WHITE;

};
