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
}

//Constructors / Deconstructors

Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
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

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear(sf::Color(255, 0, 0, 255));

	//Draw game objects
	this->window->display();
}
