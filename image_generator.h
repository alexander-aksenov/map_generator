#ifndef IMAGE_GENERATOR_H
#define IMAGE_GENERATOR_H

#include <vector>
#include <tuple>
#include <utility>
#include <field.h>

using ImgDot = std::tuple<unsigned char, unsigned char, unsigned char>;

class ImageGenerator {
        struct CellBorders {
            unsigned int x_begin;
            unsigned int x_end;
            unsigned int y_begin;
            unsigned int y_end;
        };

        unsigned int width;
        unsigned int height;
        std::vector<std::vector<ImgDot>> img;

        void addVerticalBorders(unsigned int step);
        void addHorizontalBorders(unsigned int step);

        int getCorrection(const Field &f);
        void addCellHeight(const CellBorders &c, unsigned char val);

    public:
        ImageGenerator(unsigned int width, unsigned int height) : width(width), height(height)
        {
            img = std::vector<std::vector<ImgDot>>(width, std::vector<ImgDot>(height, std::make_tuple(255, 255, 255)));
        }

        void addBorders(const Field &field);
        void addHeights(const Field &heights);

        unsigned int getWidth() const { return width; }
        unsigned int getHeight() const { return height; }
        unsigned char getR(unsigned int x, unsigned int y) const { return std::get<0>(img[x][y]); }
        unsigned char getG(unsigned int x, unsigned int y) const { return std::get<1>(img[x][y]); }
        unsigned char getB(unsigned int x, unsigned int y) const { return std::get<2>(img[x][y]); }
};

#endif /* IMAGE_GENERATOR_H */
