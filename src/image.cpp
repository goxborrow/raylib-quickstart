#include "image.h"

void ImageShape::Update()
{
    // Update logic if needed
}

void ImageShape::Draw()
{
    DrawTextureEx(m_texture, position, 0.0f, size, color);
}