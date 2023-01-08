#include <heights_generator.h>

void
HeightsGenerator::setBorders(Field &field, int val)
{
    for (unsigned int i = 0; i < field.getHeight(); i++) {
        field[0][i] = val;
        field[field.getWidth() - 1][i] = val;
    }

    for (unsigned int i = 0; i < field.getWidth(); i++) {
        field[i][0] = val;
        field[i][field.getHeight() - 1] = val;
    }
}


Field
HeightsGenerator::generateHeightsField(unsigned int width, unsigned int height, int min, int max)
{
    Field f = Field::createEmptyField(width, height, min, max);
    setBorders(f, 100);

    return f;
}
