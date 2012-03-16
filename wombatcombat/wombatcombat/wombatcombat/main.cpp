#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main (int argc, const char * argv[])
{
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

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
  	}

  	// Clear screen
  	window.clear();
  	
    // Update the window
  	window.display();
  }

	return EXIT_SUCCESS;
}
