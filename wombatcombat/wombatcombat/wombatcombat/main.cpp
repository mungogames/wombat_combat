#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include "BaseGame.h"
#include "ControlHandler.h"
#include "GameContainer.h"
#include "ContactListener.h"
#include <string>


int main (int argc, const char * argv[])
{

  string gameName = "Wombat Combat";

  bool fullscreen;

  // Generates the window and reads the window mode for resolution and colordepth
  sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(DesktopMode.width/2, DesktopMode.height/2,DesktopMode.bitsPerPixel), gameName);

  // Generates the World
  b2Vec2 gravity(0, -3);
  b2World* world = new b2World(gravity);

  ContactListener contactListener;
  world->SetContactListener(&contactListener);

  // Time Step and Iterations for box2d
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 8;
  int32 positionIterations = 4;

  GameContainer* gc = new GameContainer(window, world);

  // Create the main window

  BaseGame* baseGame = new BaseGame(gc);

  while (gc->getWindow()->isOpen())
  {
  	// Process events
  	sf::Event event;
  	while (gc->getWindow()->pollEvent(event))
  	{
  		// Close window : exit
  		if (event.type == sf::Event::Closed)
  			gc->getWindow()->close();

  		// Escape pressed : exit
  		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        gc->getWindow()->close();

      //Fullscreen toggle
      if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F)) {
        fullscreen = !fullscreen;
        if (fullscreen)
          gc->getWindow()->create(sf::VideoMode(DesktopMode.width, DesktopMode.height,DesktopMode.bitsPerPixel), gameName, (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize|sf::Style::Close));
        else
          gc->getWindow()->create(sf::VideoMode(DesktopMode.width/2, DesktopMode.height/2,DesktopMode.bitsPerPixel), gameName);

      }
      //
  	}

    gc->getWorld()->Step(timeStep, velocityIterations, positionIterations);

    // Update everything
    baseGame->update();

  	// Clear screen
  	gc->getWindow()->clear();

    // Render everything
    baseGame->render();
    gc->getWindow()->setView(gc->view);

    // Update the window
  	gc->getWindow()->display();
  }

	return EXIT_SUCCESS;
}
