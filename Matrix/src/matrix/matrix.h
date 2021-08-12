#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

class Matrix
{
private:
    uint32_t nrows;
    uint32_t ncols;
    double **data;
public:
    Matrix (const uint32_t nrows, const uint32_t ncols);
    Matrix (const char filename[]);
    ~Matrix ();
    Matrix transpose ();
    void randomize ();
    void print ();
    friend Matrix operator +(Matrix const &, Matrix const &);
    friend Matrix operator +(Matrix const &, const double);
    friend Matrix operator -(Matrix const &, Matrix const &);
    friend Matrix operator -(Matrix const &, const double);
    friend Matrix operator *(Matrix const &, Matrix const &);
    friend Matrix operator *(Matrix const &, const double);
    friend bool operator ==(Matrix const &, Matrix const &);
};

#endif