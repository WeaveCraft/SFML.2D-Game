#include "Game.h"
#include <memory>
#include <random>

namespace {
	constexpr unsigned WINDOW_WIDTH = 800;
	constexpr unsigned WINDOW_HEIGHT = 600;
	constexpr float ENEMY_SPAWN_TIMER_MAX = 1000.f;
	constexpr unsigned MAX_ENEMIES = 5;
	constexpr sf::Vector2f ENEMY_SIZE{100.f, 100.f};
	constexpr sf::Vector2f ENEMY_SCALE{0.5f, 0.5f};
	constexpr unsigned FRAME_RATE = 60;
	constexpr float ENEMY_MOVE_SPEED = 5.f;
}

// Constructor / Destructor
Game::Game() {
	initializeVariables();
	initializeWindow();
	initializeEnemyTemplate();
}

Game::~Game() = default;

void Game::initializeVariables() {
	points = 0;
	enemySpawnTimer = ENEMY_SPAWN_TIMER_MAX;
	maxEnemies = MAX_ENEMIES;
}

void Game::initializeWindow() {
	videoMode = sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT);
	window = std::make_unique<sf::RenderWindow>(
		videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(FRAME_RATE);
}

void Game::initializeEnemyTemplate() {
	enemy.setSize(ENEMY_SIZE);
	enemy.setScale(ENEMY_SCALE);
	enemy.setFillColor(sf::Color::Cyan);
	enemy.setOutlineColor(sf::Color::Green);
	enemy.setOutlineThickness(1.f);
	enemy.setPosition(10.f, 10.f);
}

// Game Loop
bool Game::running() const {
	return window && window->isOpen();
}

void Game::update() {
	pollEvents();
	updateMousePositions();
	updateEnemies();
}

void Game::render() {
	window->clear();
	renderEnemies();
	window->display();
}

// Events & Input
void Game::pollEvents() {
	sf::Event event{};
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed ||
		   (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			window->close();
		}
	}
}

void Game::updateMousePositions() {
	mousePosWindow = sf::Mouse::getPosition(*window);
}

// Enemies
void Game::spawnEnemy() {
	auto xPos = static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x));
	enemy.setPosition(xPos, 0.f);
	enemy.setFillColor(sf::Color::Green);
	enemies.push_back(enemy);
}

void Game::updateEnemies() {
	if (enemies.size() < maxEnemies && enemySpawnTimer >= ENEMY_SPAWN_TIMER_MAX) {
		spawnEnemy();
		enemySpawnTimer = 0.f;
	} else {
		enemySpawnTimer += 1.f;
	}

	for (auto& e : enemies) {
		e.move(0.f, ENEMY_MOVE_SPEED);
	}
}

void Game::renderEnemies() {
	for (const auto& e : enemies) {
		window->draw(e);
	}
}
