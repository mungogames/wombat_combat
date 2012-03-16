#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <string>

using namespace std;

int main (int argc, const char * argv[])
{
  
  string gameName = "Wombat Combat";
  

  bool fullscreen = false;
  
  // Create the main window
  sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode(); 
  sf::RenderWindow window(sf::VideoMode(DesktopMode.width/2, DesktopMode.height/2), gameName);

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

  	// Clear screen
  	window.clear();
  	
    // Update the window
  	window.display();
  }

	return EXIT_SUCCESS;
}
