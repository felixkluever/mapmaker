#include "../include/perlin_noise.h"

#include "math.h"
#include <numeric>
#include <random>
#include <algorithm>

//initialize with reference values
Perlin_Noise::Perlin_Noise() {
    // Initialize the permutation vector with the reference values todo fix 
    //permutation = {151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,190,6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,48,27,166,77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,102,143,54,65,25,63,161,1,216,80,73,209,76,132,187,208,89,18,169,200,196,135,130,116,188,159,86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,221,153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,113,224,232,178,185,112,104,218,246,97,228,251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,49,192,214,31,181,199,106,157,184,84,204,176,115,121,50,45,127,4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180};
    // Duplicate the permutation vector
	permutation.insert(permutation.end(), permutation.begin(), permutation.end());
}

// generates a new permutation vector based on seed
Perlin_Noise::Perlin_Noise(unsigned int seed) {
    permutation.resize(256);

    //fill permutation with values from 0-255
    std::iota(permutation.begin(), permutation.end(), 0);

    //initialize a random engine with seed
    std::default_random_engine engine(seed);

    //shuffle using a the aboe random engine
    std::shuffle(permutation.begin(), permutation.end(), engine);

    // duplicate the permutation vector
    permutation.insert(permutation.end(), permutation.begin(), permutation.end());
}

double Perlin_Noise::noise(double x, double y, double z) {
    //find the cube that contains the point    
    int X = (int) floor(x) & 255;
    int Y = (int) floor(y) & 255;
    int Z = (int) floor(z) & 255;

    //find relative x, y, z of point in cube
    x -= floor(x);
    y -= floor(y);
    z -= floor(z);

    //compute fade curves for each x, y, z
    double u = fade(x);
    double v = fade(y); 
    double w = fade(z);

    // Hash coordinates of the 8 cube corners
	int A = permutation[X] + Y;
	int AA = permutation[A] + Z;
	int AB = permutation[A + 1] + Z;
	int B = permutation[X + 1] + Y;
	int BA = permutation[B] + Z;
	int BB = permutation[B + 1] + Z;

	// Add blended results from 8 corners of cube
	double res = lerp(w, lerp(v, lerp(u, grad(permutation[AA], x, y, z), grad(permutation[BA], x-1, y, z)), lerp(u, grad(permutation[AB], x, y-1, z), grad(permutation[BB], x-1, y-1, z))),	lerp(v, lerp(u, grad(permutation[AA+1], x, y, z-1), grad(permutation[BA+1], x-1, y, z-1)), lerp(u, grad(permutation[AB+1], x, y-1, z-1), grad(permutation[BB+1], x-1, y-1, z-1))));
	return (res + 1.0)/2.0;
}

double Perlin_Noise::fade(double t) {
    return t*t*t*(t*(t*6-15)+10);
}

double Perlin_Noise::lerp(double t, double a, double b) {
    return a + t * (b-a);
}

double Perlin_Noise::grad(int hash, double x, double y, double z) {
    int h = hash & 15;

    //convert lower 4 bits of hash into 12 gradient directions
    double u = h < 8 ? x : y, 
        v = h < 4 ? y : h == 12 || h == 14 ? x : z;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}