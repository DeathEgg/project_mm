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
	/*
	 * Create Window
	 */
	int ScreenWidth = 1920;
	int ScreenHeight = 1080;
	VideoMode vm(ScreenWidth, ScreenHeight);
	RenderWindow window(vm, "Shiver me Timbers", Style::Default);
	
	/*
	 * Create Sprites
	 */
	// Background Sprite
	Texture txBackground;
	txBackground.loadFromFile("graphics/background.png");
	Sprite spBackground;
	spBackground.setTexture(txBackground);
	spBackground.setPosition(0, 0);

	// Tree Sprite
	Texture teTree;
	teTree.loadFromFile("graphics/tree.png");
	Sprite spTree;
	spTree.setTexture(teTree);
	spTree.setPosition(810, 0);

	// Bee Sprite
	Texture txBee;
	txBee.loadFromFile("graphics/bee.png");
	Sprite spBee;
	spBee.setTexture(txBee);
	spBee.setPosition(0, 800);

	// Cloud Sprites
	Texture txCloud;
	txCloud.loadFromFile("graphics/cloud.png");
	Sprite spCloud1;
	Sprite spCloud2;
	Sprite spCloud3;
	spCloud1.setTexture(txCloud);
	spCloud2.setTexture(txCloud);
	spCloud3.setTexture(txCloud);

	/*
	 * Bee variables
	 */
	bool beeActive = false;
	float beeSpeed = 0.0f;

	/*
	 * Cloud variables
	 */
	 // Position the clouds off screen
	spCloud1.setPosition(0, 0);
	spCloud2.setPosition(0, 250);
	spCloud3.setPosition(0, 500);
	// Are the clouds currently on screen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	// How fast is each cloud?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	while (window.isOpen()) {
		// Handle input
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Update the scene

		// Draw the scene
		window.clear();

		// Draw Background
		window.draw(spBackground);
		// Draw the clouds
		window.draw(spCloud1);
		window.draw(spCloud2);
		window.draw(spCloud3);
		// Draw the tree
		window.draw(spTree);
		// Draw the insect
		window.draw(spBee);

		window.display();
	}

	return 0;
}