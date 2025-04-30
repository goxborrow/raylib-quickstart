/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "circle.h"
#include "square.h"
#include "raylib.h"
#include "raymath.h"	// math functions
#include "editor.h"		// editor class

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include <vector>

int main()
{
	const int screenWidth = 2500;
	const int screenHeight = 1500;

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	Texture wabbit = LoadTexture("wabbit_alpha.png");

	Shape* shape = new Square(Vector2{ 400, 400 }, 50, RED);
	//Shape* shape2 = new Circle(Vector2{ 400, 400 }, 50, RED);
	std::vector<Shape*> shapes;
	std::vector<Texture*> textures;


	//added two new textures
	//Texture pearto = LoadTexture("pearto.png");
	//Texture mizuki = LoadTexture("mizuki-akiyama-mizuki.gif");

	Editor editor;

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// Update the shape position
		editor.Update();

		//// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// Changed what the text says
		// draw some text using the default font
		//DrawText("Go my mizulings", 200, 200, 50, WHITE);

		// USE THIS FOR THE ASSIGNMENT FROM FRIDAY
		// changes settings for how the texture is drawn, in a sine wave pattern
		// draw our texture to the screen
		//for (int i = 0; i < screenWidth; i += 40)
		//{
		//	int y = screenHeight / 2 + (sinf((GetTime() * 3) + i / 100.f) * 400);
		//	//float scale = 0.5f + (sinf((GetTime() * 4) + (i / 10.f)) / 5);
		//	//DrawTexture(pearto, i, y, WHITE);
		//	DrawTextureEx(mizuki, (Vector2) { i, y }, 0.0f, .2f, WHITE);
		//}
		//DrawTexture(wabbit, 0, 0, WHITE);

		editor.Draw();

			//for (auto s : shapes) {
			//	s->Draw();
			//}
			//shape->Draw();
			// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
