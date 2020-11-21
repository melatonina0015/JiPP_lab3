#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "matrixclass.hpp"

using namespace std;

matrix::matrix(int n, int m)
{
    r = n;
    c = m;
    matrixTab = new int *[n];
    for(int i = 0; i < n; i++)
    {
        matrixTab[i] = new int [m]; 
        for(int j = 0; j < m; j++)
        {
            matrixTab[i][j] = 0;
        }    
    }
}

matrix::matrix(int n)
{
    r = n;
    c = n;
    matrixTab = new int *[n];
    for(int i = 0; i < n; i++)
    {
        matrixTab[i] = new int [n];
        for(int j = 0; j < n; j++)
        {
            matrixTab[i][j] = 0;
        }
    }
}

matrix::matrix(std::string filename)
{
    ifstream file(filename);
    file >> r >> c;
    matrixTab = new int *[r];
    for(int i = 0; i < r; i++)
    {
        matrixTab[i] = new int [c]; 
        for(int j = 0; j < c; j++)
        {
            file >> matrixTab[i][j];
        }    
    }
}

void matrix::set(int n, int m, int val)
{
    matrixTab[n-1][m-1] = val;
}

int matrix::get(int n, int m)
{
    return matrixTab[n-1][m-1];
}

void matrix::add(matrix m2)
{
    matrix product(rows(), cols());

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            product.matrixTab[i][j] = matrixTab[i][j] + m2.matrixTab[i][j];
        }
    }
    product.print();
}

void matrix::multiply(matrix m2)
{
    matrix product(rows(), m2.cols());
    int s;
    for(int i = 0; i < rows(); i++)
    for(int j = 0; j < m2.cols(); j++)
    {
      s = 0;
      for(int k = 0; k < cols(); k++)
      {
        s += matrixTab[i][k] * m2.matrixTab[k][j];
      }
      product.matrixTab[i][j] = s;
    }
    product.print();
}

void matrix::subtract(matrix m2)
{
    matrix product(rows(), cols());

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            product.matrixTab[i][j] = matrixTab[i][j] - m2.matrixTab[i][j];
        }
    }
    product.print();
}

int matrix::cols()
{
    return c;
}

int matrix::rows()
{
    return r;
}

void matrix::print()
{   
    //cout << "--YOUR MATRIX--\n";
    cout.width(4);
    cout << "";
    for(int i = 0; i < c; i++)
    {
        cout.width(2);
        cout << i + 1 << " ";
        
    }
    cout << endl;

    for(int i = 0; i < r; i++)
    {
        cout.width(2);
        cout << i + 1 << "  ";
        for(int j = 0; j < c; j++)
        {
            cout.width(2);
            cout << matrixTab[i][j] << " ";
        }
        cout << endl;
    }   
    
}

void matrix::store(std::string filename, std::string path)
{
    path = path + "\\" + filename; 
    ofstream file(path);
    file << r << ' ' << c << endl;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            int a = matrixTab[i][j];
            file << a << " ";
        }
        file << endl;
    }
}

void matrix::store(std::string filename)
{ 
    ofstream file(filename);
    file << r << ' ' << c << endl;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            int a = matrixTab[i][j];
            file << a << " ";
        }
        file << endl;
    }
}