#pragma once
#include "shape.h"
#include <vector>
#include <array>

class Editor {
public:
    Editor();
    ~Editor();

    void Update();
    void Draw();
    void DrawTextures();
    void LoadTextures();
    void UnloadTextures();
    void CycleTexture();

private:
    Shape* Create(Shape::Type type);
    void ClearAll();

private:
    float size = 20;
    Shape::Type type = Shape::Type::CIRCLE;
    const std::array<Color, 8> colors = { WHITE, RED, GREEN, BLUE, PURPLE, SKYBLUE, MAGENTA, ORANGE };
    int colorIndex = 0;

    // Textures for image shapes
    static const int MAX_TEXTURES = 3;
    Texture2D m_textures[MAX_TEXTURES];
    int m_textureIndex = 0;
    bool texturesLoaded = false;

    Shape* shape = nullptr;
    std::vector<Shape*> shapes;
    std::vector<Texture*> textures;
};
