#include <SFML/Graphics.hpp>

int main()
{
//############ crea una ventana y un punto circle al medio
/*
    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dibujando un Círculo");

    //agregar image de fondo
    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("Images/fondoo.png")){
        return EXIT_FAILURE;
}
    sf::Sprite backgroundSprite(backgroundTexture);
    //Escalar el sprite para que coincida con las dimensiones de la ventana
    float scaleX = static_cast<float>(window.getSize().x) / backgroundSprite.getLocalBounds().width;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundSprite.getLocalBounds().height;
    backgroundSprite.setScale(scaleX, scaleY);


    // Bucle principal del juego
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Crear un círculo
        sf::CircleShape circle(50.f);
        circle.setPosition(375.f, 275.f);
        circle.setFillColor(sf::Color::Red);

        // Dibujar el círculo en la ventana
        window.draw(backgroundSprite);
        window.draw(circle);

        // Mostrar lo dibujado en la ventana
        window.display();
    }
*/
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Projectile Example");

    sf::RectangleShape player(sf::Vector2f(50, 50));
    player.setFillColor(sf::Color::Green);
    player.setPosition(375, 525);

    sf::RectangleShape projectile(sf::Vector2f(10, 10));
    projectile.setFillColor(sf::Color::Red);
    bool projectileActive = false;

    sf::Clock clock;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time deltaTime = clock.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !projectileActive) {
            projectileActive = true;
            projectile.setPosition(player.getPosition().x + 20, player.getPosition().y);
        }

        if (projectileActive) {
            projectile.move(0, -300 * deltaTime.asSeconds());

            if (projectile.getPosition().y < 0) {
                projectileActive = false;
            }
        }

        window.clear();
        window.draw(player);
        
        if (projectileActive) {
            window.draw(projectile);
        }

        window.display();
    }

    return 0;
}