#include <SFML/Graphics.hpp>

int main() {
    // Pencere olu�turma
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Hareket �rne�i");

    // Dikd�rtgen olu�turma
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(350.f, 275.f);

    // Hareket h�z�
    float speed = 200.f;

    // Ana d�ng�
    sf::Clock clock;
    while (window.isOpen()) {
        // Zaman hesaplama
        sf::Time deltaTime = clock.restart();

        // Olaylar� i�leme
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Klavye girdisini kontrol etme
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rectangle.move(0, -speed * deltaTime.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rectangle.move(0, speed * deltaTime.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            rectangle.move(-speed * deltaTime.asSeconds(), 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            rectangle.move(speed * deltaTime.asSeconds(), 0);
        }

        // Pencereyi temizleme
        window.clear(sf::Color::Black);

        // Dikd�rtgeni �izme
        window.draw(rectangle);

        // Pencereyi g�ncelleme
        window.display();
    }

    return 0;
}
