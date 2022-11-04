/*#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::RectangleShape jogador(sf::Vector2f(50.0f, 50.0f));
    jogador.setFillColor(sf::Color::Blue);
    jogador.setPosition(50.0f, 50.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) window.close();

            }
        }

        window.clear();
        window.draw(shape);
        window.draw(jogador);
        window.display();
    }

    return 0;
}*/