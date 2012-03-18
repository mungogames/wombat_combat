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
  window->setVerticalSyncEnabled(true);
  
  sf::Clock frameTimer;
  sf::Time deltaTime;
  
  
  
  // Generates the World
  b2Vec2 gravity(0, -9.8);
  b2World* world = new b2World(gravity);

  ContactListener contactListener;
  world->SetContactListener(&contactListener);

  GameContainer* gc = new GameContainer(window, world);

  // Create the main window
  //gc->getWindow()->setFramerateLimit(500);

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
    
    float currentFPS =  1000 / (gc->getDelta().asMicroseconds() / 1000.0f);    
    
    // Update everything
    baseGame->update();    
    gc->getWorld()->Step(1/currentFPS, 8, 3);
    
  	// Clear screen
  	gc->getWindow()->clear();

    // Render everything
    baseGame->render();
    gc->getWindow()->setView(gc->view);

    // Update the window
  	gc->getWindow()->display();
    
    gc->setDelta(frameTimer.restart());
    
  }

	return EXIT_SUCCESS;
}
