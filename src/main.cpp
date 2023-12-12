#include <iostream>

#include "../include/image.h"
#include "../include/perlin_noise.h"

int main ( int argc, char* argv[]) {
    const int width = 1920;
    const int height = 1080;

    Perlin_Noise noise = Perlin_Noise(5686597);
    Image perlinnoise = Image(width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {            
            double X = (double)x/((double)width);
			double Y = (double)y/((double)height);

            //function to play around with
            // factor in front >1 makes harder lines
            // factor in front <1 controlls brightness

            double n = noise.noise(10*X, 10*Y, 0.8);

            Color color = Color(n, n, n);
            perlinnoise.SetColor(color, x, y);
        }
        
    }

    perlinnoise.Export("noise.bmp");
}