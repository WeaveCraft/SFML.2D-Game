#pragma once

#include<iostream>
#include<vector>
#include<ctime>

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
	std::vector<sf::RectangleShape> enemies;
	sf::Vector2i mousePosWindow;

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

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
	void spawnEnemy();

	void pollEvents();

	void updateMousePositions();
	void updateEnemies();
	void update();

	void renderEnemies();
	void render();
};