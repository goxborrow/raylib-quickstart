#pragma once
#include "shape.h"

class ImageShape : public Shape {
public:
    ImageShape() = default;
    ImageShape(const Texture2D& texture, const Vector2& pos, float s = 1.0f, const Color& c = WHITE) :
        Shape(pos, s, c), m_texture(texture) {
    }

    void Update() override;
    void Draw() override;

    Type GetType() override {
        return Type::IMAGE;
    }

protected:
    Texture2D m_texture;
};