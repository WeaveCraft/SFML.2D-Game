#include "Game.h"

//Private functions
void Game::initializeVariables()
{
	this->window = nullptr;
}

void Game::initializeWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f)); // sets the size 0.5f of setSize.
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

//Constructors / Deconstructors

Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}


//Functions
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateMousePositions()
{
	/*
		@return void

		Updates the mouse positions:
			- Mouse position relative to window (Vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::update()
{
	this->pollEvents();

	this->updateMousePositions();
}

void Game::render()
{
	this->window->clear(sf::Color(0, 0, 0, 255));

	//Draw game objects
	this->window->draw(this->enemy);

	this->window->display();
}
