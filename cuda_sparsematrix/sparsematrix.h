#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <regex>
#include <fstream>
#include <vector>

typedef std::unordered_map<size_t,double> IndexValue;
typedef std::unordered_map<std::size_t,IndexValue> Matrix;

struct SparseMatrix
{

    SparseMatrix(const std::string &A,const std::string &B)
    {
        std::ifstream in(A);
        std::string line;
        std::getline(in,line);//считали шапку
        in>>m_nrows;
        m_ncols = m_nrows+1;
        std::getline(in,line);//считали значение
        std::getline(in,line);//считали шапку-2
        while(in)
        {
            std::size_t i,j;
            double val;
            in>>i>>j>>val;
            m_matrix[i][j] = val;
        }
        in.close();
        in.open(B);
        std::getline(in,line);
        std::getline(in,line);
        std::getline(in,line);
        while(in)
        {
            std::size_t i;
            double val;
            in>>i>>val;
            m_matrix[i][m_nrows] = val;
        }
        std::cout<<m_matrix.size()<<'\n';
    }

    SparseMatrix(const Matrix &matrix,std::size_t s1,std::size_t s2)
    {
        m_matrix = matrix;
        m_nrows = s1;
        m_ncols = s2;
    }

    void print()
    {
        for(std::size_t i = 0; i<m_nrows; i++)
        {
            for(std::size_t j = 0; j<m_ncols; j++)
                std::cout<<m_matrix[i][j]<<' ';
            std::cout<<'\n';
        }
    }

    double get(std::size_t i,std::size_t j)
    {
        return m_matrix[i][j];
    }

    std::vector<double> get_column(std::size_t j)
    {
        std::vector<double> R(m_nrows);
        for(std::size_t i = 0; i<m_nrows; i++)
        {
            R[i] = m_matrix[i][j];
        }
        return R;
    }

    void set(double val,std::size_t i,std::size_t j)
    {
        m_matrix[i][j] = val;
    }

    std::size_t m_nrows;
    std::size_t m_ncols;

private:
    Matrix   m_matrix;
};


