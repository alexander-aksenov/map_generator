#include <field.h>

Field
Field::createEmptyField(unsigned int cols, unsigned int rows, int min, int max)
{
    return Field(cols, rows, min, max);
}
