#include "../include/map.h"

#include "../include/perlin_noise.h"

#include <iostream>

Map::Map(int width, int height, int seed) : height(height), width(width), seed(seed) {
    map = std::vector<Color>(width * height);
    generateMap();
}

void Map::generateMap() {
    //the foundation terrain noise
    Perlin_Noise terrain_noise = Perlin_Noise(seed);
    Perlin_Noise terrain_noise2 = Perlin_Noise(seed * -1);

    //draw the terrain
    for (int i = 0; i < width; i++)
    {
        double x = (double)i / ((double) width);
        for (int j = 0; j < height; j++)
        {
            double y = (double)j / ((double) height);

            //function to play around with
            // factor in front >1 makes harder lines
            // factor in front <1 controlls brightness
            // factor in front of X / Y controls amplitudes
            // "normal" values are 10*x, 10*y

            double terrain = terrain_noise.noise(15*x, 10*y, 0.8) + terrain_noise2.noise(x, y, 0.8) / 10;            
            double val = terrain; // add other noises as required;

            //std::cout << val << " ";

            map[j * width + i] = colorTerrain(val);
            // map [j * width + i] = Color(val, val, val);
        }   
        //std::cout << std::endl;
    }

    // generate structures
    drawCities();
}

Color Map::colorTerrain(double val) {
    if (val < 0.5)
        return sea_colour;
    else if (val < 0.54)
        return sand_colour;
    else if (val < 0.7)
        return grass_colour;
    else if (val < 0.8)
        return dirt_colour;
    else if (val < 0.9)
        return stone_colour;
    else
        return snow_colour;
    
}

std::vector<Color> Map::getMap() {
    return map;
}

Color Map::getValue(int x, int y) {    
    return map[y* width + x];
}

// draw cities ontop of terrain
void Map::drawCities() {
    Perlin_Noise cities_noise = Perlin_Noise(seed + 2);
    int cities_ctr = 0;
    for (int i = 0; i < width; i++)
    {
        double x = (double)i / ((double) width);    
        for (int j = 0; j < height; j++)
        {
            double y = (double)j / ((double) height);

            double cities = cities_noise.noise(100 * x, 100 * y, 0.8);            
            
            if (cities > 0.9f && sameColor(map[j * width + i], grass_colour)) {
                map[j * width + i] = Color (1, 0 ,0);
                cities_ctr ++;
            }
        }
    }
    std::cout << "cities generated: " << cities_ctr << std::endl;
}

void Map::drawCity(int const x, int const y) {
    
}
