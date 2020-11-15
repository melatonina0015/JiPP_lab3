#include <iostream>
#include "matrixclass.hpp"

using namespace std;

/*class matrix{

    int **matrixTab;
    int c, r;
    public:
    matrix(int n, int m)
    {
        c = n;
        r = m;
        matrixTab = new int *[m];
        for(int i = 0; i < m; i++)
        {
            matrixTab[i] = new int [n]; 
            for(int j = 0; j < n; j++)
            {
                matrixTab[i][j] = 0;
            }    
        }
    }
    matrix(int n)
    {
        c = n;
        r = n;
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

    void print()
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cout << matrixTab[i][j] << " ";
            }
            cout << endl;
        }
    }
};*/

matrix::matrix(int n, int m)
{
    r = n;
    c = m;
    matrixTab = new int *[m];
    for(int i = 0; i < r; i++)
    {
        matrixTab[i] = new int [n]; 
        for(int j = 0; j < c; j++)
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
    cout << "--PRINTING MATRIX--\n";
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
