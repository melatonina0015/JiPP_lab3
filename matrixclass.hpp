#ifndef matrixclass_hpp
#define matrixclass_hpp

class matrix
{

    private:

    int **matrixTab;
    int c, r;

    public:

    matrix(int n, int m);
    matrix(int n);
    void set(int n, int m, int val);
    int get(int n, int m);
    void add(matrix m2);
    void multiply(matrix m2);
    void subtract(matrix m2);
    int cols();
    int rows();
    void print();
};

#endif