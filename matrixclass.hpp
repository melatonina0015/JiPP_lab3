#ifndef matrixclass_hpp
#define matrixclass_hpp

class matrix{

    private:

    int **matrixTab;
    int c, r;

    public:

    matrix(int n, int m);
    matrix(int n);
    void print();
    void set(int n, int m, int val);
    int get(int n, int m);
    int cols();
    int rows();

};

#endif