#pragma once

#include<iostream>
#include<vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
	Class that acts as the game eninge.
	Wrapper Class.
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Mouse positions
	sf::Vector2i mousePosWindow;

	//Game Objects
	sf::RectangleShape enemy;

	//private functions
	void initializeVariables();
	void initializeWindow();
	void initEnemies();
public:
	//Constructors / Desctructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void updateMousePositions();
	void update();
	void render();
};