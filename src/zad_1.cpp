#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <string>
#include <matrixclass.hpp>
#include <typeinfo>

using namespace std;

class menuChoice: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception accured";
  }
};

int main()
{
    int n, m, k, choice = -1;
    string path;
    bool p = true;
    cout << "Inicjalizuje program pokazujacy dzialanie na macierzach...\n";
    Sleep(2000);
    system("cls");
    while(true)
    {
        cout << "--NAJPIERW UTWORZ MACIERZ--\n";
        do 
        {
            system("cls");
            cout << "Macierz kwadratowa (1), prostokatna (2) lub pobrana z pliku (3)\n";
            try
            {
                cin >> choice;
                if(choice < 1 || choice > 3) throw(choice);
            }
            catch(const exception& e)
            {
                std::cerr << e.what() << '\n';
                Sleep(3000);
            }
            
            
            switch(choice)
            {
                case 1:
                {
                    system("cls");
                    cout << "Podaj wymiar macierzy\n";
                    try
                    {
                        cin >> n;
                        if(typeid(n) != typeid(int)) throw n;
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                    
                    matrix myObj(n);
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
                        try
                        {
                            cin >> choice;
                            if(choice < 0 || choice > 8) throw(choice);
                        }
                        catch(const exception& e)
                        {
                            std::cerr << e.what() << '\n';
                            Sleep(3000);
                        }

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
                        {
                            matrix m2(myObj.rows(), myObj.cols());
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
                        break;
                        }

                        case 4:
                        {
                            matrix m2(myObj.rows(), myObj.cols());
                            p = true;
                            while(p == true)
                            {
                                system("cls");
                                cout << "Zbuduj druga macierz aby odjac ja\n\n";
                                cout << "1. Ustaw wartosc elementu nowej macierzy\n";
                                cout << "2. Odejmij obie macierze\n";
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
                                    cout << "Wynik odejmowania macierzy\n";
                                    myObj.subtract(m2);
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
                        break;
                        }

                        case 5:
                        {
                            int x;
                            cout << "Podaj ilosc kolumn nowej macierzy ";
                            cin >> x;
                            matrix m2(myObj.cols(), x);
                            p = true;
                            while(p == true)
                            {
                                system("cls");
                                cout << "Zbuduj druga macierz aby je pomnozyc\n\n";
                                cout << "1. Ustaw wartosc elementu nowej macierzy\n";
                                cout << "2. POmnoz obie macierze\n";
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
                                    cout << "Wynik mnozenia macierzy\n";
                                    myObj.multiply(m2);
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
                        break;
                        }

                        case 6:
                            cout << "Ilosc wierszy jest rowna " << myObj.rows() << endl;
                            Sleep(2000);
                            break;

                        case 7:
                            cout << "Ilosc kolumn jest rowna " << myObj.cols() << endl;
                            Sleep(2000);
                            break;

                        case 8:
                        {
                            string filename2store;
                            cout << "Podaj nazwe pliku ";
                            cin >> filename2store;
                            myObj.store(filename2store);
                            break;
                        }

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
                p = false;
                } 
                break;

                case 2:
                {
                    system("cls");
                    cout << "Podaj wymiary macierzy\n";
                    cin >> m >> k;
                    matrix myObj(m,k);
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
                        try
                        {
                            cin >> choice;
                            if(choice < 0 || choice > 8) throw(choice);
                        }
                        catch(const exception& e)
                        {
                            std::cerr << e.what() << '\n';
                            Sleep(3000);
                        }
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
                        {
                            matrix m2(myObj.rows(), myObj.cols());
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
                        break;
                        }

                        case 4:
                        {
                            matrix m2(myObj.rows(), myObj.cols());
                            p = true;
                            while(p == true)
                            {
                                system("cls");
                                cout << "Zbuduj druga macierz aby odjac ja\n\n";
                                cout << "1. Ustaw wartosc elementu nowej macierzy\n";
                                cout << "2. Odejmij obie macierze\n";
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
                                    cout << "Wynik odejmowania macierzy\n";
                                    myObj.subtract(m2);
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
                        break;
                        }

                        case 5:
                        {
                            int x;
                            cout << "Podaj ilosc kolumn nowej macierzy ";
                            cin >> x;
                            matrix m2(myObj.cols(), x);
                            p = true;
                            while(p == true)
                            {
                                system("cls");
                                cout << "Zbuduj druga macierz aby je pomnozyc\n\n";
                                cout << "1. Ustaw wartosc elementu nowej macierzy\n";
                                cout << "2. POmnoz obie macierze\n";
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
                                    cout << "Wynik mnozenia macierzy\n";
                                    myObj.multiply(m2);
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
                        break;
                        }

                        case 6:
                            cout << "Ilosc wierszy jest rowna " << myObj.rows() << endl;
                            Sleep(2000);
                            break;

                        case 7:
                            cout << "Ilosc kolumn jest rowna " << myObj.cols() << endl;
                            Sleep(2000);
                            break;

                        case 8:
                        {
                            string filename2store;
                            cout << "Podaj nazwe pliku ";
                            cin >> filename2store;
                            myObj.store(filename2store);
                            break;
                        }

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
                }
                p = false;
                break;

                case 3:
                {
                    system("cls");
                    cout << "Podaj sciezke do pliku macierzy\n";
                    cin >> path;
                    matrix myObj(path);
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
                        try
                        {
                            cin >> choice;
                            if(choice < 0 || choice > 8) throw(choice);
                        }
                        catch(const exception& e)
                        {
                            std::cerr << e.what() << '\n';
                            Sleep(3000);
                        }
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
                        {
                            matrix m2(myObj.rows(), myObj.cols());
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
                        break;
                        }

                        case 4:
                        {
                            matrix m2(myObj.rows(), myObj.cols());
                            p = true;
                            while(p == true)
                            {
                                system("cls");
                                cout << "Zbuduj druga macierz aby odjac ja\n\n";
                                cout << "1. Ustaw wartosc elementu nowej macierzy\n";
                                cout << "2. Odejmij obie macierze\n";
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
                                    cout << "Wynik odejmowania macierzy\n";
                                    myObj.subtract(m2);
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
                        break;
                        }

                        case 5:
                        {
                            int x;
                            cout << "Podaj ilosc kolumn nowej macierzy ";
                            cin >> x;
                            matrix m2(myObj.cols(), x);
                            p = true;
                            while(p == true)
                            {
                                system("cls");
                                cout << "Zbuduj druga macierz aby je pomnozyc\n\n";
                                cout << "1. Ustaw wartosc elementu nowej macierzy\n";
                                cout << "2. POmnoz obie macierze\n";
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
                                    cout << "Wynik mnozenia macierzy\n";
                                    myObj.multiply(m2);
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
                        break;
                        }

                        case 6:
                            cout << "Ilosc wierszy jest rowna " << myObj.rows() << endl;
                            Sleep(2000);
                            break;

                        case 7:
                            cout << "Ilosc kolumn jest rowna " << myObj.cols() << endl;
                            Sleep(2000);
                            break;

                        case 8:
                        {
                            string filename2store;
                            cout << "Podaj nazwe pliku ";
                            cin >> filename2store;
                            myObj.store(filename2store);
                            break;
                        }
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
                p = false;    
                break;
                }
                
                default:
                {
                    cout << "Podaj wlasciwa opcje!\n";
                    Sleep(2000);
                    break;  
                }
            }

        }while(p == true);
    }       
    return 0;
}