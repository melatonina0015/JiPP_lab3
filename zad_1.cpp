#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <string>
#include "matrixclass.cpp"

using namespace std;

int main()
{
    int n, m, k, choice = -1;
    string path;
    bool p = true;
    cout << "Inicjalizuje program pokazujacy dzialanie na macierzach...\n";
    Sleep(2000);
    system("cls");
    //while(true)
    //{
        /*cout << "--NAJPIERW UTWORZ MACIERZ--\n";
        do 
        {
            system("cls");
            cout << "Macierz kwadratowa (1), prostokatna (2) lub pobrana z pliku (3)\n";
            cin >> choice;
            switch(choice)
            {
                /*case 1:
                    system("cls");
                    cout << "Podaj wymiar macierzy\n";
                    cin >> n;
                    matrix myObj(n);
                    p = false;
                    break;

                case 2:
                    system("cls");
                    cout << "Podaj wymiary macierzy\n";
                    cin >> m >> k;
                    matrix myObj(m,k);
                    p = false;
                    break;

                case 3:
                    system("cls");
                    cout << "Podaj sciezke do pliku macierzy\n";
                    cin >> path;
                    matrix myObj(path);
                    p = false;
                    break;

                default:
                    cout << "Podaj wlasciwa opcje!\n";
                    break;
            }
        }while(p == true);*/


        //cout << "1. Tworzenie macierzy\n";
        matrix myObj(5);
        matrix m2(myObj.rows(), myObj.cols());
        while(true)
        {   
            system("cls");
            cout << "1. Ustawianie wartosci elementow macierzy\n";
            cout << "2. Pobieranie wartosci elementow macierzy\n";
            cout << "3. Dodawanie macierzy\n";
            cout << "4. Odejmowanie macierzy\n";
            cout << "5. Mnozenie macierzy\n";
            cout << "6. Zwaracanie liczby wierszy macierzy\n";
            cout << "7. Zwaracanie liczby kolumn macierzy\n";
            cout << "8. Zapis macierzy do pliku\n";
            cout << "0. Zakonczenie programu\n\n\n";
            myObj.print();

            cout << "\nWybierz opcje: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Podaj wspolrzedne oraz wartosc elementu: ";
                cin >> n >> m >> k;
                myObj.set(n, m, k);
                break;

            case 2:
                cout << "Podaj wspolrzedne: ";
                cin >> n >> m;
                cout << "Wartosc o wspolrzednych " << n << " i " << m << " jest rowna " << myObj.get(n, m) << endl;
                Sleep(2000);
                break;

            case 3:
                
                p = true;
                while(p == true)
                {
                    system("cls");
                    cout << "Zbuduj druga macierz aby je do siebie dodac\n\n";
                    cout << "1. Ustaw wartosc elementu nowej macierzy\n";
                    cout << "2. Dodaj obie macierze\n";
                    cout << "3. Wyjscie\n";
                    cout << "--Twoja macierz--\n";
                    myObj.print();
                    cout << "--Nowa macierz--\n";
                    m2.print();

                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        cout << "Podaj wspolrzedne oraz wartosc elementu: ";
                        cin >> n >> m >> k;
                        m2.set(n, m, k);
                        break;

                    case 2:
                        cout << "Wynik dodawania macierzy\n";
                        myObj.add(m2);
                        system("pause");
                        p = false;
                        break;

                    case 3:
                        p = false;
                        break;
                    
                    default:
                        break;
                    }
                }
                
                /*cout << "Podaj wspolrzedne: ";
                cin >> n >> m;
                cout << "Wartosc o wspolrzednych " << n << " i " << m << " jest rowna " << myObj.get(n, m) << endl;
                Sleep(2000);*/
            break;

            case 6:
                cout << "Ilosc wierszy jest rowna " << myObj.rows() << endl;
                Sleep(2000);
                break;

            case 7:
                cout << "Ilosc kolumn jest rowna " << myObj.cols() << endl;
                Sleep(2000);
                break;

            case 0:
                cout << "--KONCZENIE PROGRAMU--";
                Sleep(1000);
                return 0;
                
            default:
                cout << "Podaj dobra opcje...";
                Sleep(1000);
                break;
            }



        }

   

        
        /*switch(choice1)
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

    while(true)
    {
        cout << "Program przedstawiajacy dzialanie na macierzach przy pomocy klas\n";
        int choice2 = -1;
        cout << "Pokaz macierz na ekranie (9)\n";
        cin >> choice2;

        switch(choice2)
        {
            continue;
        }
    }
    
    matrix myObj(4, 5);
    myObj.print();
    myObj.set(2, 3, 5);
    myObj.set(1, 1, 10);
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

    //string a = "wynik.txt";
    //string b = "D:\\Studia\\Semestr III\\JiPP";
    //string path = b + "\\" + a;
    //cout << a << "\n" << b << "\n" << path;
    myObj.store("wynik.txt", "D:\\Studia\\Semestr III\\JiPP");
    myObj.store("wynik.txt");

    matrix myObj3("D:\\Studia\\Semestr III\\JiPP\\Lab 3\\dane.txt");    
    myObj3.print();*/
    
    
    return 0;
}