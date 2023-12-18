#include <iostream>

#include "../include/image.h"
#include "../include/perlin_noise.h"
#include "../include/map.h"

int main ( int argc, char* argv[]) {
    const int width = 500;
    const int height = 250;
    
    Image perlinnoise = Image(width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {            
            Map map = Map(width, height, 84765);            
            perlinnoise.SetColor(map.getValue(x, y), x, y);
        }
    }

    perlinnoise.Export("noise.bmp");
}