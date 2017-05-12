#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

sf::Font font;
sf::Text invText;
sf::CircleShape circ(50);
void init() {
  if (!font.loadFromFile("res/SourceCodePro-Black.ttf")) {
    cout << "Font Load Error\n";
  }
}
void initCirc() {
  circ.setFillColor(sf::Color(100, 250, 50));
}
void displayInv() {
  invText.setFont(font);
  invText.setString("Hello World");
  invText.setCharacterSize(24);
  invText.setColor(sf::Color::Red);
  invText.setStyle(sf::Text::Bold);

  bool showInv = true;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
  }
}

int main(int argc, char* argv[]) {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(800, 600), "My window",
                          sf::Style::Default, settings);

  init();
  initCirc();
  displayInv();

  sf::CircleShape encirc(50);

  encirc.setFillColor(sf::Color(100, 0, 50));
  encirc.setPosition(300, 400);
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
      circ.move(-1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
      circ.move(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
      circ.move(0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
      circ.move(0, 1);
    }
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

    // draw everything here...
    window.draw(encirc);
    auto encircBounding = encirc.getGlobalBounds();
    window.draw(invText);
    window.draw(circ);
    auto circBound = circ.getGlobalBounds();
    // end the current frame
    window.display();
    if (circBound.intersects(encircBounding)) {
      window.close();
    }
  }

  return 0;
}
