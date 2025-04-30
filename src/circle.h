#pragma once
#include "shape.h"

class Circle : public Shape {
public:
	Circle() = default;
	Circle(const Vector2& pos, float s = 20, const Color& c = WHITE) :
		Shape(pos, s, c)
	{
	}
	void Update() override;
	void Draw() override;
	Type GetType() override {
		return Type::CIRCLE;
	}

};
