#ifndef FIELD_H
#define FIELD_H

#include <vector>

class Field {
    std::vector<std::vector<int>> f;

    Field(unsigned int c, unsigned int r)
    {
        f = std::vector<std::vector<int>>(c, std::vector<int>(r, 0));
    }

    public:
        static Field createEmptyField(unsigned int cols, unsigned int rows);

        std::vector<int> operator[](int idx) const { return f[idx]; }
        std::vector<int>& operator[](int idx) { return f[idx]; }

        unsigned int getWidth() const { return f.size(); }
        unsigned int getHeight() const { return f[0].size(); }
};

#endif /* FIELD_H */
