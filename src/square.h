#pragma once
#include "shape.h"

class Square : public Shape {
public:
	Square() = default;
	Square(const Vector2& pos, float s = 20, const Color& c = WHITE) :
		Shape(pos, s, c)
	{
	}
	void Update() override;
	void Draw() override;
	Type GetType() override {
		return Type::SQUARE;
	}

private:
	float rotation{ 0 };

};
