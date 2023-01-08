#ifndef HEIGHTS_GENERATOR_H
#define HEIGHTS_GENERATOR_H

#include <field.h>

class HeightsGenerator {
        static void setBorders(Field &field, int val);
    public:
        static Field generateHeightsField(unsigned int width, unsigned int height, int min, int max);
};

#endif /* HEIGHTS_GENERATOR_H */
