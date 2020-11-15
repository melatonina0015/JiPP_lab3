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

matrix::matrix(int n)
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

void matrix::print()
{
    for(int i = 0; i < r; i++)
       {
           cout << r - i - 1 << "  ";
        for(int j = 0; j < c; j++)
        {
            cout << matrixTab[i][j] << " ";
        }
        cout << endl;
    }
    cout << "   ";
    for(int i = 0; i < c; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

void matrix::set(int n, int m, int val)
{
    matrixTab[n][m] = val;
}

int matrix::get(int n, int m)
{
    return matrixTab[n][m];
}

int matrix::cols()
{
    return c;
}

int matrix::rows()
{
    return r;
}