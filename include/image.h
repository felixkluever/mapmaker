#include <vector>

//color struct
//represents a single pixel / color
struct Color {
    float r, g, b;

    Color();
    Color(float r, float g, float b);
    ~Color();
};

//image class
//represents the whole image
class Image
{
public:
    Image (int width, int height);
    ~Image();

    Color getColor(int x, int y) const;
    void SetColor(const Color& color, int x, int y);

    void Export (const char* path) const;

private:
    int m_width;
    int m_height;
    std::vector<Color> m_colors;
};