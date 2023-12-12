// translation of the reference implementation by Ken Perlin
// with help of https://solarianprogrammer.com/2012/07/18/perlin-noise-cpp-11/

#include <vector>

class Perlin_Noise {
    std::vector<int> permutation;
public:
    //initilize with the reference vector  
    Perlin_Noise();
    //generates a new permutation vector based on the value of the seed
    Perlin_Noise(unsigned int seed);
    //get value from given coordinates
    double noise(double x, double y, double z);
private:
    double fade (double t);
    double lerp (double t, double a, double b);
    double grad (int hash, double x, double y, double z);
};