#include "editor.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"
#include "image.h"

Editor::Editor()
{
    // Initialize textures
    LoadTextures();

    shape = Create(Shape::Type::CIRCLE);
}

Editor::~Editor()
{
    ClearAll();
    UnloadTextures();
}

void Editor::LoadTextures()
{
    if (!texturesLoaded) {
        // Load textures from files - adjust paths as needed
        m_textures[0] = LoadTexture("wabbit_alpha.png");
        m_textures[1] = LoadTexture("resources/wabbit_alpha.png"); // Alternate path if first fails

        // Try to load other textures if available
        if (FileExists("pearto.png")) {
            m_textures[1] = LoadTexture("pearto.png");
        }

        if (FileExists("mizuki-akiyama-mizuki.gif")) {
            m_textures[2] = LoadTexture("mizuki-akiyama-mizuki.gif");
        }

        m_textureIndex = 0;
        texturesLoaded = true;
    }
}

void Editor::UnloadTextures()
{
    if (texturesLoaded) {
        for (int i = 0; i < MAX_TEXTURES; i++) {
            UnloadTexture(m_textures[i]);
        }
        texturesLoaded = false;
    }
}

void Editor::CycleTexture()
{
    m_textureIndex = (m_textureIndex + 1) % MAX_TEXTURES;
}

void Editor::Update()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
    }

    // place mizuki on the screen
    if (IsKeyPressed(KEY_M)) {
        Texture mizuki = LoadTexture("mizuki-akiyama-mizuki.gif");
        DrawTexture(mizuki, GetMouseX(), GetMouseY(), WHITE);
        textures.push_back(&mizuki);
    }

    // scale shape
    if (IsKeyDown(KEY_UP)) {
        size += 1.5f;
        size = std::min(size, 200.0f);
    }
    if (IsKeyDown(KEY_DOWN)) {
        size -= 1.5f;
        size = std::max(size, 1.0f);
        if (size < 0)  size = 1.0f;
    }

    shape->SetSize(size);

    // change color
    if (IsKeyPressed(KEY_SPACE)) {
        colorIndex = ++colorIndex % colors.size();
        shape->SetColor(colors[colorIndex]);
    }

    // Cycle texture (new feature)
    if (IsKeyPressed(KEY_T)) {
        CycleTexture();
        if (type == Shape::Type::IMAGE) {
            // Recreate the image shape with new texture
            delete shape;
            shape = Create(type);
        }
    }

    // shape select
    if (IsKeyPressed(KEY_TAB)) {
        type = static_cast<Shape::Type>(((static_cast<int>(type)) + 1) % static_cast<int>(Shape::Type::NumShapes));
        delete shape;
        shape = Create(type);
    }

    // undo last action
    if (IsKeyDown(KEY_LEFT_CONTROL) && (IsKeyPressed(KEY_Z))) {
            if (!shapes.empty()) {
                delete shapes.back();
                shapes.pop_back();
            
        }
    }

	// change shape color
	if (IsKeyPressed(KEY_C)) {
		colorIndex = ++colorIndex % colors.size();
		shape->SetColor(colors[colorIndex]);
		
		
	}

    // display all usable actions
    if (IsKeyDown(KEY_H)) {
        DrawText("Press SPACE to change color", 10, 10, 30, WHITE);
        DrawText("Press TAB to change shape", 10, 40, 30, WHITE);
        DrawText("Press UP/DOWN to scale shape", 10, 70, 30, WHITE);
        DrawText("Press ESCAPE to exit", 10, 100, 30, WHITE);
        DrawText("Press DELETE to clear all shapes", 10, 130, 30, WHITE);
        DrawText("Press CTRL+Z to undo last action", 10, 160, 30, WHITE);
        DrawText("Press T to cycle textures (for image shapes)", 10, 190, 30, WHITE);

        // Display current shape type
        const char* shapeNames[] = { "Circle", "Square", "Triangle", "Image" };
        DrawText(TextFormat("Current Shape: %s", shapeNames[static_cast<int>(type)]), 10, 220, 30, WHITE);
    }

    // clear all shapes
    if (IsKeyPressed(KEY_DELETE)) {
        ClearAll();
    }

    // place shape
    if (IsMouseButtonPressed(0) || IsKeyDown(KEY_LEFT_CONTROL) && (IsMouseButtonDown(0))) {
        // add current shape
        shapes.push_back(shape);
        // create a new shape
        shape = Create(type);
    }

    shape->SetPosition(GetMousePosition());

    for (auto shape : shapes) {
        shape->Update();
    }
    shape->Update();
}

void Editor::Draw()
{
    // draw editor shapes
    for (auto shape : shapes) {
        shape->Draw();
    }
    // draw current shape
    shape->Draw();
}

void Editor::ClearAll()
{
    for (auto shape : shapes) {
        delete shape;
    }
    shapes.clear();
}

Shape* Editor::Create(Shape::Type type)
{
    Shape* shape = nullptr;

    switch (type) {
    case Shape::Type::CIRCLE:
        shape = new Circle(GetMousePosition(), size, colors[colorIndex]);
        break;
    case Shape::Type::SQUARE:
        shape = new Square(GetMousePosition(), size, colors[colorIndex]);
        break;
    case Shape::Type::TRIANGLE:
        shape = new Triangle(GetMousePosition(), size, colors[colorIndex]);
        break;
    case Shape::Type::IMAGE:
        shape = new ImageShape(m_textures[m_textureIndex], GetMousePosition(), size, colors[colorIndex]);
        break;
    default:
        break;
    }

    return shape;
}