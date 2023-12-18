#include <iostream>

#include "../include/image.h"
#include "../include/perlin_noise.h"
#include "../include/map.h"

int main ( int argc, char* argv[]) {
    const int width = 1920;
    const int height = 1080;
    
    Image perlinnoise = Image(width, height);
    Map map = Map(width, height, 84765);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {                        
            perlinnoise.SetColor(map.getValue(x, y), x, y);
        }
    }

    perlinnoise.Export("noise.bmp");
}