#include <iostream>
#include <random>

#include "../include/image.h"
#include "../include/perlin_noise.h"
#include "../include/map.h"

#include <SFML/Graphics.hpp>

void drawmap(int const width, int const height){
    int seed = 1;
    //creates a random seed
    srand((unsigned) time(NULL));
    seed = rand();
    Image perlinnoise = Image(width, height);
    Map map = Map(width, height, seed);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {                        
            perlinnoise.SetColor(map.getValue(x, y), x, y);
        }
    }

    perlinnoise.Export("map.bmp");
}

int main ( int argc, char* argv[]) {
    const int width = 1920;
    const int height = 1080;
    
    drawmap(width, height);
    // window setup
    sf::RenderWindow window(sf::VideoMode(width, height), "mapmaker");    
    
    //window loop
    while (window.isOpen()){
        //events
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
        }
        drawmap(width, height);

        sf::Texture map;
        if (!map.loadFromFile("map.bmp"))
        {
            return EXIT_FAILURE;
        }
        sf::Sprite sprite (map);

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return EXIT_SUCCESS;
} 