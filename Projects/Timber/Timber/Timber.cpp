/******************************************************************************
Filename: Timber.cpp

Purpose:  Runs the Timber game

******************************************************************************/
#include "pch.h" // Must run first
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char * argv[])
{
	int ScreenWidth = 1280;
	int ScreenHeight = 720;
	
	// Create a texture
	Texture txBackground;
	txBackground.loadFromFile("graphics/background.png");

	// Create a sprite from the texture
	Sprite spBackground;
	spBackground.setTexture(txBackground);
	spBackground.setPosition(0, 0);

	// Create a window
	VideoMode vm(ScreenWidth, ScreenHeight);
	RenderWindow window(vm, "Shiver me Timbers", Style::Default);

	while (window.isOpen()) {
		// Handle input
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Update the scene

		// Draw the scene
		window.clear();
		window.draw(spBackground);

		window.display();
	}

	return 0;
}