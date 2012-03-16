#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>

#include <string>

using namespace std;

int main (int argc, const char * argv[])
{
  
  string gameName = "Wombat Combat";
  

  bool fullscreen = false;
  
  // Create the main window
  sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode(); 
  sf::RenderWindow window(sf::VideoMode(DesktopMode.width/2, DesktopMode.height/2), gameName);

  // Generates the World
  b2Vec2 gravity(0, -3); // Gravitation
  b2World* world = new b2World(gravity); // Neue Welt
  
  // Time Step and Iterations for box2d
  float timeStep = 1.0f / 60.0f;
  int velocityIterations = 6; 
  int positionIterations = 2;
  
  // Start the game loop
  while (window.isOpen())
  {
  	// Process events
  	sf::Event event;
  	while (window.pollEvent(event))
  	{
  		// Close window : exit
  		if (event.type == sf::Event::Closed)
  			window.close();
          
  		// Escape pressed : exit
  		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
  			window.close();
      
      //Fullscreen toggle 
      if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::F)) { 
        fullscreen = !fullscreen; 
        if (fullscreen)
          window.create(sf::VideoMode(DesktopMode.width, DesktopMode.height,DesktopMode.bitsPerPixel), gameName, (fullscreen ? sf::Style::Fullscreen : sf::Style::Resize|sf::Style::Close)); 
        else
          window.create(sf::VideoMode(DesktopMode.width/2, DesktopMode.height/2,DesktopMode.bitsPerPixel), gameName); 
        
      } 
      
  	}

    // Here goes the update method
    
    world->Step(timeStep, velocityIterations, positionIterations);
    
  	// Clear screen
  	window.clear();
  	
    // Here goes the render method
    
    // Update the window
  	window.display();
  }

	return EXIT_SUCCESS;
}
