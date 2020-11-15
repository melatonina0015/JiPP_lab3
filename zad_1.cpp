#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "matrixclass.cpp"

using namespace std;

int main()
{
    /*int n, m, choice1 = -1;
    cout << "Teraz stworze macierz; Kwadratowa (1) czy Wybrane wymiary (2)? "; 
    cin >> choice1;
    while(true)
    {
        switch(choice1)
        {
            case 1:
                system("cls");
                cout << "Podaj wymiar macierzy kwadratowej: ";
                cin >> n;
                matrix myObj(n);
                break;
            
            case 2:
                system("cls");
                cout << "Podaj wymiary macierzy: ";
                cin >> n >> m;
                matrix myObj(n, m);
                break;

            default:
                system("cls");
                cout << "Wprowadz poprawne dane\n";
                Sleep(2);
                break;
        } 
    }

    /*while(true)
    {
        cout << "Program przedstawiajacy dzialanie na macierzach przy pomocy klas\n";
        int choice2 = -1;
        cout << "Pokaz macierz na ekranie (9)\n";
        cin >> choice2;

        switch(choice2)
        {
            continue;
        }
    }*/
    
    matrix myObj(4, 5);
    myObj.print();
    myObj.set(2, 3, 5);
    myObj.print();
    cout << myObj.get(3, 3);
    cout << myObj.cols();
    cout << myObj.rows();
    cout << endl;
    matrix m2(4, 5);
    m2.set(3, 3, 5);
    m2.set(1, 3, 10);
    m2.set(4, 2, 7);
    myObj.add(m2);
    m2.set(1, 1, 4);
    m2.set(4, 3, 6);
    m2.set(2, 2, 1);
    myObj.subtract(m2);
    matrix m3(5, 6);
    m3.set(1, 1, 4);
    m3.set(4, 6, 6);
    m3.set(2, 2, 1);
    myObj.multiply(m3);
    
    
    
    return 0;
}