#include <SFML/Graphics.hpp>

int main() {
    // Pencere oluþturma
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Hareket Örneði");

    // Dikdörtgen oluþturma
    sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(350.f, 275.f);

    // Hareket hýzý
    float speed = 200.f;

    // Ana döngü
    sf::Clock clock;
    while (window.isOpen()) {
        // Zaman hesaplama
        sf::Time deltaTime = clock.restart();

        // Olaylarý iþleme
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

        // Dikdörtgeni çizme
        window.draw(rectangle);

        // Pencereyi güncelleme
        window.display();
    }

    return 0;
}
