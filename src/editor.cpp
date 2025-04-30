#include "editor.h"
#include "square.h"
#include "circle.h"

Editor::Editor()
{
	shape = Create(Shape::Type::CIRCLE);

}

Editor::~Editor()
{
	ClearAll();
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

	//scale shape
	if (IsKeyDown(KEY_RIGHT)) {
		size += 1.5f;
		size = std::min(size, 200.0f);
	}
	if (IsKeyDown(KEY_LEFT)) {
		size -= 1.5f;
		size = std::max(size, 1.0f);
		if (size < 0)  size = 1.0f;
	}

	shape->SetSize(size);

	//change color
	if (IsKeyPressed(KEY_DOWN)) {
		colorIndex = ++colorIndex % colors.size();
		shape->SetColor(colors[colorIndex]);
	}

	//shape select
	if (IsKeyPressed(KEY_TAB)) {
		type = static_cast<Shape::Type>(((static_cast<int>(type)) + 1) % static_cast<int>(Shape::Type::NumShapes));
		delete shape;
		shape = Create(type);
	}

	//clear all shapes
	if (IsKeyPressed(KEY_DELETE)) {
		ClearAll();
	}
	
	//play shape
	if (IsMouseButtonPressed(0) || (IsMouseButtonDown(0) && IsKeyDown(KEY_LEFT_CONTROL))) {
		//add current shape
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
		

//void Editor::Draw()
//{
//	// draw editor shapes
//	for (auto shape : shapes) {
//		shape->Draw();
//	}
//	// draw current shape
//	shape->Draw();
//}

void Editor::Draw() {
	// draw textures
	for (auto texture : textures) {
		DrawTexture(*texture, 0, 0, WHITE);
	}
	// draw the shape
	for (auto shape : shapes) {
		shape->Draw();
	}
	// draw the current shape
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
	default:
		break;


		return shape;

	}
}
