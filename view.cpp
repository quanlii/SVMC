//view.h
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class View
{
public:
	View();
	~View();
	void InitText();
	void run(sf::RenderWindow* window);
	void updateGUI(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
	void update(sf::RenderWindow* window);
	void updateMouse(sf::RenderWindow* window);
//	void updateTextIfMouseIn(sf::Text& text);
	const bool isMenuClose() const;
	const bool isMenuClose() const;

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	sf::Text viewText;
	sf::Font font;

	float sizeText;
	bool viewStart;
	bool viewClose;
};


////////////////////////////////////////////
//view.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "View.h"

void View::InitText()
{
	this->sizeText = 50.f;

	this->font.loadFromFile("font/RubikMonoOne-Regular.ttf");
	this->viewText.setFont(this->font);
	this->viewText.setCharacterSize(this->sizeText);
	this->viewText.setFillColor(sf::Color::White);
	this->viewText.setString("OOOOOOOOOOOOOOO");

}


View::View()
{
	this->textureBackground.loadFromFile("Textures/Back.png");
	this->spriteBackground.setTexture(this->textureBackground);
	this->spriteBackground.setScale(16 / 12.f, 16 / 12.f);

	this->viewStart = false;
	this->viewClose = false;

	this->InitText();
}

View::~View(){}

void View::run(sf::RenderWindow* window)
{
	if (this->isMenuClose() == false) 
	{
		this->update(window);
		this->render(window);
	}
}

const bool View::isMenuClose() const
{
	return this->viewClose;
}

const bool View::viewStart() const
{
	return this->viewStart;
}

void View::updateMouse(sf::RenderWindow* window)
{
	this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}

//void View::updateTextIfMouseIn(sf::Text& text)
//{
//	if (text.getGlobalBounds().contains(this->mousePosView))
//	{
//		if( text.getFillColor() != sf::Color::Red)
//		{
//			this->singleClick.setPlayingOffset(sf::seconds(0.11));
//			this->singleClick.play();
//
//			text.setFillColor(sf::Color::Red);
//		}
//
//	}
//	else
//		text.setFillColor(sf::Color::White);
//}


void View::updateGUI(sf::RenderWindow* window)
{
	//set color if mouse in text
	this->updateTextIfMouseIn(this->startText);
	this->updateTextIfMouseIn(this->informationText);
	this->updateTextIfMouseIn(this->standingsText);
	this->updateTextIfMouseIn(this->quitText);

	//mouse click text
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->startText.getGlobalBounds().contains(this->mousePosView))
	{
		this->gameStart = true;
		this->menuClose = true;
		this->backgroundMusic.pause();
		this->click.setPlayingOffset(sf::seconds(0.2));
		this->click.play();
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->informationText.getGlobalBounds().contains(this->mousePosView))
	{
		this->click.setPlayingOffset(sf::seconds(0.2));
		this->click.play();

		this->showInformation = true;
		this->menuClose = true;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->standingsText.getGlobalBounds().contains(this->mousePosView))
	{
		this->click.setPlayingOffset(sf::seconds(0.2));
		this->click.play();

		this->showStandings = true;
		this->menuClose = true;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->quitText.getGlobalBounds().contains(this->mousePosView))
	{
		this->click.setPlayingOffset(sf::seconds(0.2));
		this->click.play();
		window->close();
	}
}
