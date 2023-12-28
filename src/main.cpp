#include <iostream>
#include <random>

#include "../include/image.h"
#include "../include/perlin_noise.h"
#include "../include/map.h"

int main ( int argc, char* argv[]) {
    const int width = 1920;
    const int height = 1080;
    
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