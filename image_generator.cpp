#include <image_generator.h>

void
ImageGenerator::addVerticalBorders(unsigned int step)
{
    unsigned int cur = step;
    while (cur < width) {
        for (unsigned int y = 0; y < height; y++) {
            img[cur][y] = std::make_tuple(0, 0, 0);
        }
        cur += step;
    }
}

void
ImageGenerator::addHorizontalBorders(unsigned int step)
{
    unsigned int cur = step;
    while (cur < height) {
        for (unsigned int x = 0; x < width; x++) {
            img[x][cur] = std::make_tuple(0, 0, 0);
        }
        cur += step;
    }
}

void
ImageGenerator::addBorders(const Field &field)
{
    if (field.getWidth() > 1) {
        addVerticalBorders(width / (field.getWidth() - 1));
    }

    if (field.getHeight() > 1) {
        addHorizontalBorders(height / (field.getHeight() - 1));
    }
}
