#include <vector>

class Perlin_Noise 
{
public:
    // constructurs
    Perlin_Noise(int width, int height);
    ~Perlin_Noise();

    // functions
    const std::vector<float>& get_map();
    float get_value(int x, int y);

    //datatypes

    struct Vector2 {
        float x, y;

        Vector2();
        Vector2(float x, float y);
        ~Vector2();
    };

    /*typedef struct vector2
    {
        float x, y;
    };*/
    
private:
    //functions
    void calc();
    float interpolate(float a0, float a1, float x);
    Vector2 randomGradient(int ix, int iy);
    float dotGridGradient(int ix, int iy, float x, float y);
    float perlin(float x, float y);

    // members
    int m_width;
    int m_height;
    std::vector<float> m_map;
};