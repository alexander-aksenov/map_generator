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

int
ImageGenerator::getCorrection(const Field &f)
{
    return f.getMin() * (-1);
}

void
ImageGenerator::addCellHeight(const CellBorders &c, unsigned char val)
{
    for (unsigned int i = c.x_begin; i < c.x_end; i++) {
        for (unsigned int j = c.y_begin; j < c.y_end; j++) {
            img[i][j] = std::make_tuple(val, val, val);
        }
    }
}

void
ImageGenerator::addBorders(const Field &field)
{
    if (field.getWidth() > 1) {
        addVerticalBorders(width / field.getWidth());
    }

    if (field.getHeight() > 1) {
        addHorizontalBorders(height / field.getHeight());
    }
}

void
ImageGenerator::addHeights(const Field &heights)
{
    unsigned int stepX = width / heights.getWidth();
    unsigned int stepY = height / heights.getHeight();
    int correction = getCorrection(heights);

    for (unsigned int i = 0; i < heights.getWidth(); i++) {
        for (unsigned int j = 0; j < heights.getHeight(); j++) {
            CellBorders c = {
                .x_begin = i * stepX,
                .x_end = (i * stepX + stepX) > width ? width : (i * stepX + stepX),
                .y_begin = j * stepY,
                .y_end = (j * stepY + stepY) > height ? height : (j * stepY + stepY),
            };
            unsigned char val = (heights[i][j] + getCorrection(heights)) % 255;

            addCellHeight(c, val);
        }
    }
}
