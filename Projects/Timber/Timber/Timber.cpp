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

	// Variables to control time itself
	Clock clock;

	while (window.isOpen()) {
		/*
		 * Handle input
		 */
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		/*
		 * Update the scene
		 */
		// Measure time
		//	 Restart the clock to start counting from 0 again
		//   Return the amount of time that has passed since the last frame
		Time dt = clock.restart();

		// Setup the bee
		if (!beeActive) {
			// How fast is the bee
			srand((int) time(0)); // Seed rand
			beeSpeed = (rand() % 200) + 200;
			// How high is the bee
			srand((int) time(0) * 10); // Reseed rand
			float height = (rand() % 500) + 500;
			spBee.setPosition(2000, height);
			beeActive = true;
		} 
		else {
			// Move the bee
			spBee.setPosition(spBee.getPosition().x - (beeSpeed * dt.asSeconds()), spBee.getPosition().y);
			// Has the bee reached the right hand edge of the screen?
			if (spBee.getPosition().x < -100) {
				// Set it up ready to be a whole new cloud next frame
				beeActive = false;
			}
		}

		// Manage the clouds
		// Cloud 1
		if (!cloud1Active) {
			// How fast is the cloud
			srand((int)time(0) * 10);
			cloud1Speed = (rand() % 200);
			// How high is the cloud
			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spCloud1.setPosition(-200, height);
			cloud1Active = true;
		}
		else {
			spCloud1.setPosition(spCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spCloud1.getPosition().y);
			// Has the cloud reached the right hand edge of the screen?
			if (spCloud1.getPosition().x > 1920) {
				// Set it up ready to be a whole new cloud next frame
				cloud1Active = false;
			}
		}
		// Cloud 2
		if (!cloud2Active) {
			// How fast is the cloud
			srand((int)time(0) * 20);
			cloud2Speed = (rand() % 200);
			// How high is the cloud
			srand((int)time(0) * 20);
			float height = (rand() % 300) - 150;
			spCloud2.setPosition(-200, height);
			cloud2Active = true;
		}
		else {
			spCloud2.setPosition(spCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spCloud2.getPosition().y);
			// Has the cloud reached the right hand edge of the screen?
			if (spCloud2.getPosition().x > 1920) {
				// Set it up ready to be a whole new cloud next frame
				cloud2Active = false;
			}
		}
		// Cloud 3
		if (!cloud3Active) {
			// How fast is the cloud
			srand((int)time(0) * 30);
			cloud3Speed = (rand() % 200);
			// How high is the cloud
			srand((int)time(0) * 30);
			float height = (rand() % 450) - 150;
			spCloud3.setPosition(-200, height);
			cloud3Active = true;
		}
		else {
			spCloud3.setPosition(spCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spCloud3.getPosition().y);
			// Has the cloud reached the right hand edge of the screen?
			if (spCloud3.getPosition().x > 1920) {
				// Set it up ready to be a whole new cloud next frame
				cloud3Active = false;
			}
		}

		/*
		 * Draw the scene
		 */
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

		/*
		 * Display frame buffer
		 */
		window.display();
	}

	return 0;
}
