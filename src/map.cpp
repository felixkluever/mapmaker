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
    Perlin_Noise terrain_noise2 = Perlin_Noise(seed * seed / 84576);

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

            double terrain = terrain_noise.noise(10*x, 10*y, 0.8) + terrain_noise2.noise(10*x, 10*y, 0.8) / 10;            
            double val = terrain; // add other noises as required;

            //std::cout << val << " ";

            map[j * width + i] = colorPixel(val);
            // map [j * width + i] = Color(val, val, val);
        }   
        //std::cout << std::endl;
    }
}

Color Map::colorPixel(double val) {
    if (val < 0.5)
        return sea_colour;
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