#include <iostream>

#include "../include/image.h"
#include "../include/perlin_noise.h"

int main ( int argc, char* argv[]) {
    const int width = 640;
    const int height = 480;

    Image image = Image(width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image.SetColor(Color((float)x / (float)width, 1.0f - ((float)x / (float)width), (float)y / (float)height), x, y);
        }
    }

    image.Export("image.bmp");

    Perlin_Noise noise = Perlin_Noise(width, height);
    Image perlinnoise = Image(width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Color color = Color(noise.get_value(x, y), noise.get_value(x, y), noise.get_value(x, y));
            perlinnoise.SetColor(color, x, y);
        }
        
    }

    perlinnoise.Export("noise.bmp");
}