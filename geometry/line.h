//
// Created by antoine on 28/03/18.
//

#ifndef INFOGRAPHIE_LINE_H
#define INFOGRAPHIE_LINE_H


#include <cassert>
#include "../tgaimage.h"

template<size_t DIM, typename T>
struct vec {
    vec() { for (size_t i = DIM; i--; data_[i] = T()); }

    T &operator[](const size_t i) {
        assert(i < DIM);
        return data_[i];
    }

    const T &operator[](const size_t i) const {
        assert(i < DIM);
        return data_[i];
    }

private:
    T data_[DIM];
};


template<typename T>
struct vec<2, T> {
    vec() : x(T()), y(T()) {}

    vec(T X, T Y) : x(X), y(Y) {}

    template<class U>
    vec<2, T>(const vec<2, U> &v);

    T &operator[](const size_t i) {
        assert(i < 2);
        return i <= 0 ? x : y;
    }

    const T &operator[](const size_t i) const {
        assert(i < 2);
        return i <= 0 ? x : y;
    }

    T x, y;
};



typedef vec<2, int> Vec2i;

class line {

public:

    line(vec<2, int> p1, vec<2, int> p2, TGAImage &image, TGAColor color);

    static void line1(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void line2(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void line3(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void bresenham(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

    static void bresenhamInteger(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);
};




#endif //INFOGRAPHIE_LINE_H
