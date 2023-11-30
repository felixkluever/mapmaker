#include "../include/perlin_noise.h"

#include "math.h"

Perlin_Noise::Vector2::Vector2() {
}

Perlin_Noise::Vector2::Vector2(float x, float y) : x(x), y(y) {
}

Perlin_Noise::Vector2::~Vector2() {
}

Perlin_Noise::Perlin_Noise(int width, int height) : m_height(height), m_width(width), m_map(std::vector<float>(width * height)) {
    calc();
}

Perlin_Noise::~Perlin_Noise(){
}

const std::vector<float>& Perlin_Noise::get_map() {
    return m_map;
}

float Perlin_Noise::get_value(int x, int y) {
    return m_map[y*m_width + x];
}

void Perlin_Noise::calc() {
    for (int x = 0; x < m_width; x++)
    {
        for (size_t y = 0; y < m_height; y++)
        {            
            m_map[y*m_width+x] = (perlin((float)x, (float) y));   
        }
        
    }
    
}

// ------------------------
//    noise calculations
// ------------------------

//calculates the noise level for a given point
float Perlin_Noise::perlin(float x, float y) {
    //finds the corners of this cell
    int x0 = (int) floor(x);
    int x1 = x0 + 1;
    int y0 = (int) floor(y);
    int y1 = y0 + 1;

    //interpolation weights
    float sx = x - (float)x0;
    float sy = y - (float)y0;

    //interpolates between the gradiants of the 4 corners
    float n0, n1, ix0, ix1, value;
    n0 = dotGridGradient(x0, y0, x ,y); //top left
    n1 = dotGridGradient(x1, y0, x, y); //top right
    ix0 = interpolate(n0, n1, sx);
    n0 = dotGridGradient(x0, y1, x, y); //bottom left
    n1 = dotGridGradient(x1, y1, x, y); //bottom right
    ix1 = interpolate(n0, n1, sx);
    return interpolate (n0, n1, sx); //noise level of the cell
}

// scalar product between the gradient vector and distance vector
float Perlin_Noise::dotGridGradient(int ix, int iy, float x, float y) {
    //random gradient 
    Vector2 gradient = randomGradient(ix, iy);

    //distance vector
    float dx = x - (float) ix;
    float dy = y - (float) iy;

    return dx * gradient.x + dy * gradient.y; // scalar product
}

// creates a random direction vector
Perlin_Noise::Vector2 Perlin_Noise::randomGradient(int ix, int iy) {
    // custom random function?
    // TODO test with stock random function
    const unsigned w = 8 * sizeof(unsigned);
    const unsigned s = w / 2;
    unsigned a = ix, b = iy;
    a *= 3284157443; 
    b ^= a << s | a >> (w - s);
    b *= 1911520717;
    a ^= b << s | b >> (w - s);
    a *= 2048419325;
    float random = a * (3.14159265 / ~(~0u >> 1)); //random number between 0 and 2*PI
    return Perlin_Noise::Vector2(sin(random), cos(random));    
}

//interpolates linearly between a0 and a1
float Perlin_Noise::interpolate(float a0, float a1, float x) {
    if (x < 0.0) return a0;
    if (x > 1.0) return a1;
    return (a1-a0) * x + a0;
}