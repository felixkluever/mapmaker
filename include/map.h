#ifndef _map_
#define _map_

#include "image.h"
#include <vector>

class Map {
public:
    Map(int width, int height, int seed);
    std::vector<Color> getMap();
    Color getValue(int x, int y);

private:
    int width, height, seed;
    std::vector<Color> map;

    //functions
    Color colorPixel(double val);
    void generateMap();

    //terrain
    double sea_level;
    double snow_level;

    //colours
    const Color sea_colour = Color(0.0f, 0.0f, 1.0f);
    const Color snow_colour = Color(1.0f, 1.0f, 1.0f);
    const Color grass_colour = Color(0.0f, 0.8f, 0.0f);
    const Color stone_colour = Color(0.5f, 0.5f, 0.5f);
    const Color dirt_colour = Color(0.5f, 0.25f, 0.0f);

};

#endif