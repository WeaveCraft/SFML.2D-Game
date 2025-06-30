#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>
#include <ctime>

/*
    Game Engine Wrapper Class
*/
class Game
{
private:
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    // Mouse positions
    sf::Vector2i mousePosWindow;

    // Game logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

    // Game objects
    sf::RectangleShape enemyPrototype;
    std::vector<sf::RectangleShape> enemies;

    // Initialization
    void initializeVariables();
    void initializeWindow();
    void initializeEnemies();

public:
    // Constructor / Destructor
    Game();
    virtual ~Game();

    // Accessors
    bool running() const;

    // Game logic functions
    void spawnEnemy();
    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();

    // Render functions
    void renderEnemies();
    void render();
};
