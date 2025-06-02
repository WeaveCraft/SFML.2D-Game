#include "Game.h"
#include <memory>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
constexpr float ENEMY_SPAWN_TIMER_MAX = 1000.f;
constexpr unsigned MAX_ENEMIES = 5;
constexpr sf::Vector2f ENEMY_SIZE = {100.f, 100.f};
constexpr sf::Vector2f ENEMY_SCALE = {0.5f, 0.5f};

void Game::initializeVariables()
{
	points = 0;
	enemySpawnTimer = ENEMY_SPAWN_TIMER_MAX;
	maxEnemies = MAX_ENEMIES;
}

void Game::initializeWindow()
{
	videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	window = std::make_unique<sf::RenderWindow>(
		videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close
	);
	window->setFramerateLimit(60);
}

void Game::initEnemies()
{
	enemy.setSize(ENEMY_SIZE);
	enemy.setScale(ENEMY_SCALE);
	enemy.setFillColor(sf::Color::Cyan);
	enemy.setOutlineColor(sf::Color::Green);
	enemy.setOutlineThickness(1.f);
	enemy.setPosition(10.f, 10.f);
}

// === Constructors / Destructors ===

Game::Game()
{
	initializeVariables();
	initializeWindow();
	initEnemies();
}

Game::~Game() = default;

// === Accessors ===

bool Game::running() const
{
	return window && window->isOpen();
}

// === Enemy Handling ===

void Game::spawnEnemy()
{
	enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
		0.f
	);
	enemy.setFillColor(sf::Color::Green);

	enemies.push_back(enemy);
}

void Game::updateEnemies()
{
	if (enemies.size() < maxEnemies)
	{
		if (enemySpawnTimer >= ENEMY_SPAWN_TIMER_MAX)
		{
			spawnEnemy();
			enemySpawnTimer = 0.f;
		}
		else
		{
			enemySpawnTimer += 1.f;
		}
	}

	for (auto& e : enemies)
		e.move(0.f, 5.f);
}

void Game::renderEnemies()
{
	for (const auto& e : enemies)
		window->draw(e);
}

// === Input & Update ===

void Game::pollEvents()
{
	sf::Event event{};
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		case sf::Event::KeyPressed:
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		default:
			break;
		}
	}
}

void Game::updateMousePositions()
{
	mousePosWindow = sf::Mouse::getPosition(*window);
}

void Game::update()
{
	pollEvents();
	updateMousePositions();
	updateEnemies();
}

// === Rendering ===

void Game::render()
{
	window->clear();
	renderEnemies();
	window->display();
}
