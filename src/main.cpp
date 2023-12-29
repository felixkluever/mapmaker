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
    
    /*Image perlinnoise = Image(width, height);
    Map map = Map(width, height, seed);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {                        
            perlinnoise.SetColor(map.getValue(x, y), x, y);
        }
    }

    perlinnoise.Export("map.bmp");*/
    
    //noise tester
    
    Image perlinnoise2 = Image(width, height);
    
    Perlin_Noise noise = Perlin_Noise(seed);


    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double Y = (double)y / ((double) height);
            double X = (double)x / ((double) width);
            double n = 
                noise.noise(X * 20, Y * 20, 0.8f) + 
                noise.noise(X*3, Y*3, 0.6f) + 
                noise.noise(X*10, Y*20, 0.5f) -
                noise.noise(X*100, Y*100, 0.4f) -
                noise.noise(X*5, Y*5, 0.3f) -
                noise.noise(X*0.5, Y*0.5, 0.2f)
                ;

            /*if (n >= 0.95f)
                perlinnoise2.SetColor(Color(1,1,1), x, y);
            else
                perlinnoise2.SetColor(Color(0,0,0), x, y);*/
                
            perlinnoise2.SetColor(Color(n,n,n), x, y);
        }
    }

    perlinnoise2.Export("test.bmp");
} 