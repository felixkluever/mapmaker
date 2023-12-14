#include <iostream>

//#include "../include/image.h"
#include "../include/perlin_noise.h"
#include "../include/map.h"

int main ( int argc, char* argv[]) {
    const int width = 1920;
    const int height = 1080;

    Perlin_Noise noise = Perlin_Noise(5686597);
    Perlin_Noise noise2 = Perlin_Noise(5789);
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
            // factor in front of X / Y controls amplitudes
            // "normal" values are 10*x, 10*y

            double n = noise.noise(20*X, 40*Y, 0.8) + noise2.noise(10*X, 10*Y, 0.8) * 5;

            Color color = Color(n, n, n);
            perlinnoise.SetColor(color, x, y);
        }
        
    }

    perlinnoise.Export("noise.bmp");
}