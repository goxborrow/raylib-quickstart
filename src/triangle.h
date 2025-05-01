#pragma once
#include "shape.h"

class Triangle : public Shape {
public:
    Triangle() = default;
    Triangle(const Vector2& pos, float s = 20, const Color& c = WHITE) :
        Shape(pos, s, c)
    {
    }
    void Update() override;
    void Draw() override;
    Type GetType() override {
        return Type::TRIANGLE;
    }

private:
    float rotation{ 0 };
};
