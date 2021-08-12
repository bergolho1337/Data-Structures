#include "matrix.h"

Matrix operator +(Matrix const &m1, Matrix const &m2)
{
    assert(m1.nrows == m2.ncols && m1.ncols == m2.ncols);
    Matrix out(m1.nrows,m1.ncols);
    for (uint32_t i = 0; i < m1.nrows; i++)
        for (uint32_t j = 0; j < m1.ncols; j++)
            out.data[i][j] = m1.data[i][j] + m2.data[i][j];
    return out;
}

Matrix operator +(Matrix const &m1, const double value)
{
    Matrix out(m1.nrows,m1.ncols);
    for (uint32_t i = 0; i < m1.nrows; i++)
        for (uint32_t j = 0; j < m1.ncols; j++)
            out.data[i][j] = m1.data[i][j] + value;
    return out;
}

Matrix operator -(Matrix const &m1, Matrix const &m2)
{
    assert(m1.nrows == m2.ncols && m1.ncols == m2.ncols);
    Matrix out(m1.nrows,m1.ncols);
    for (uint32_t i = 0; i < m1.nrows; i++)
        for (uint32_t j = 0; j < m1.ncols; j++)
            out.data[i][j] = m1.data[i][j] - m2.data[i][j];
    return out;
}

Matrix operator -(Matrix const &m1, const double value)
{
    Matrix out(m1.nrows,m1.ncols);
    for (uint32_t i = 0; i < m1.nrows; i++)
        for (uint32_t j = 0; j < m1.ncols; j++)
            out.data[i][j] = m1.data[i][j] - value;
    return out;
}

Matrix operator *(Matrix const &m1, Matrix const &m2)
{
    assert(m2.ncols == m1.nrows);
    Matrix out(m1.nrows,m2.ncols);
    for (uint32_t i = 0; i < m1.nrows; i++)
        for (uint32_t j = 0; j < m2.ncols; j++)
            for (uint32_t k = 0; k < m2.nrows; k++)
                out.data[i][j] += m1.data[i][k] * m2.data[k][j];
    return out;
}

Matrix operator *(Matrix const &m1, const double value)
{
    Matrix out(m1.nrows,m1.ncols);
    for (uint32_t i = 0; i < m1.nrows; i++)
        for (uint32_t j = 0; j < m1.ncols; j++)
            out.data[i][j] = m1.data[i][j] * value;
    return out;
}

bool operator ==(Matrix const &m1, Matrix const &m2)
{
    if (!(m1.nrows == m2.nrows && m1.ncols == m2.ncols)) return false;
    for (uint32_t i = 0; i < m1.nrows; i++)
        for (uint32_t j = 0; j < m1.ncols; j++)
            if (m1.data[i][j] != m2.data[i][j]) return false;
    return true;
}

Matrix::Matrix (const uint32_t nrows, const uint32_t ncols)
{
    this->nrows = nrows;
    this->ncols = ncols;
    this->data = new double*[nrows];
    this->data[0] = new double[nrows*ncols]();
    for (uint32_t i = 0; i < nrows; i++)
        this->data[i] = this->data[0] + (i*ncols);
}

Matrix::Matrix (const char filename[])
{
    FILE *file = fopen(filename,"r");
    if (!file)
    {
        fprintf(stderr,"[-] ERROR! Cannot read file '%s'\n",filename);
        exit(EXIT_FAILURE);
    }
    fscanf(file,"%u %u",&this->nrows,&this->ncols);
    this->data = new double*[nrows];
    this->data[0] = new double[nrows*ncols]();
    for (uint32_t i = 0; i < nrows; i++)
        this->data[i] = this->data[0] + (i*ncols);
    for (uint32_t i = 0; i < nrows; i++)
        for (uint32_t j = 0; j < ncols; j++)
            fscanf(file,"%lf",&this->data[i][j]);
    fclose(file);
}

Matrix::~Matrix ()
{
    delete [] this->data[0];
    delete [] this->data;
}

Matrix Matrix::transpose ()
{
    Matrix out(this->ncols,this->nrows);
    for (uint32_t i = 0; i < this->nrows; i++)
        for (uint32_t j = 0; j < this->ncols; j++)
            out.data[j][i] = this->data[i][j];
    return out;
}

void Matrix::randomize ()
{
    for (uint32_t i = 0; i < this->nrows; i++)
        for (uint32_t j = 0; j < this->ncols; j++)
            this->data[i][j] = rand() % 5;
}

void Matrix::print ()
{
    for (uint32_t i = 0; i < this->nrows; i++)
    {
        for (uint32_t j = 0; j < this->ncols; j++)
            printf("%5g ",this->data[i][j]);
        printf("\n");
    }
    printf("\n");
}