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

private:

	Shape* Create(Shape::Type type);
	void ClearAll();

private:
	float size = 20;
	Shape::Type type = Shape::Type::CIRCLE;
	const std::array<Color, 7> colors = { WHITE, RED, GREEN, BLUE, PURPLE, SKYBLUE, MAGENTA };
	int colorIndex = 0;

	Shape* shape = nullptr;
	std::vector<Shape*> shapes;
	std::vector<Texture*> textures;


};