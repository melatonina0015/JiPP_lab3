#include <iostream>
#include <cstdlib>

class matrix{

    public:
    int **matrixTab;
    matrix(int n, int m)
    {
        matrixTab = new int *[n];
        for(int i = 0; i < n; i++)
        {
            matrixTab[i] = new int [m];
        }
    }
    matrix(int n)
    {
        matrixTab = new int *[n];
        for(int i = 0; i < n; i++)
        {
            matrixTab[i] = new int [n];
        }
    }


};

int main()
{
    matrix myObj(5);
    return 0;
}