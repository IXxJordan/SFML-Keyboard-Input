#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	// Create an Untitled Window 1200x600 that allows Resizing and Closing with Frame Rate Cap of 240
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Keyboard Input", sf::Style::Resize | sf::Style::Close);
	window.setFramerateLimit(240);

	// Create a 50x50 Rectangle at (100, 100)
	sf::RectangleShape player(sf::Vector2f(50.0f, 50.f));
	player.setPosition(sf::Vector2f(100, 100));
	player.setFillColor(sf::Color(0, 255, 255, 100));

	// run the program as long as the window is open
	while (window.isOpen()) 
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close(); // "close requested" event: we close the window
				break;
			case sf::Event::Resized:
				printf("Width: %i, Height: %i\n", event.size.width, event.size.height);
				break;

			}

		}
		// clear the window with black color
		window.clear(sf::Color::Black);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) { player.move(0.0f, -1.0f); } // Move Up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) { player.move(-1.0f, 0.0f); } // Move Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) { player.move(0.0f, 1.0f); } // Move Down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) { player.move(1.0f, 0.0f); } // Move Right

		// Draw the Rectangle/Player
		window.draw(player);

		// Display everything
		window.display();
	}
	return 0;
}