#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>

#include "GameContainer.h"
#include "Terrain.h"

#include <string>

using namespace std;

int main (int argc, const char * argv[])
{
  
  string gameName = "Wombat Combat";
  

  bool fullscreen = false;
  
  // Create the main window
  sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode(); 
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(DesktopMode.width/2, DesktopMode.height/2), gameName);

  // Generates the World
  b2Vec2 gravity(0, -3); // Gravitation
  b2World* world = new b2World(gravity); // Neue Welt
  
  
  GameContainer* gc = new GameContainer(window, world);
  
  /*klassisches Koordinatensystem
   * linke Haelfte 196 Einheiten breit, obere haelfte 355 Einheiten hoch
   * rechte Haelfte 204 Einheiten breit, unter haelfte 350 Einheiten hoch   *
   */

  Terrain* terrain = new Terrain(gc, 8, 0, 0);
  terrain->addPoint(0,	-196,	-300);
  terrain->addPoint(1,	-100,	-300);
  terrain->addPoint(2,	-50,	-200);
  terrain->addPoint(3,	50,		-200);
  terrain->addPoint(4,	50,		-320);
  terrain->addPoint(5,	150,	-320);
  terrain->addPoint(6,	190,	-100);
  terrain->addPoint(7,	204,	355);
  
  float windowRatio = (float)gc->getWindow()->getSize().x / (float)gc->getWindow()->getSize().y;
  gc->getWindow()->setView(sf::View(sf::Vector2f(4, -3), sf::Vector2f(400,400*windowRatio)));
  
  
  // Time Step and Iterations for box2d
  float timeStep = 1.0f / 60.0f;
  int velocityIterations = 6; 
  int positionIterations = 2;
  
  // Start the game loop
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
      
  	}

    // Here goes the update method
    
    world->Step(timeStep, velocityIterations, positionIterations);
    
  	// Clear screen
  	gc->getWindow()->clear();
  	
    // Here goes the render method
    
    terrain->render(gc);
    
    // Update the window
  	gc->getWindow()->display();
  }

	return EXIT_SUCCESS;
}
