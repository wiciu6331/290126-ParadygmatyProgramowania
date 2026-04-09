#include <iostream>
#include <string>

using namespace std;

void dodajOsobe(string *TabNazwiska, string nazwisko)
{
    for (int i=0; i<10; i++){
        if (TabNazwiska[i]=="")
        {
            TabNazwiska[i]=nazwisko;
            cout << "Ustawiono nazwisko\n";
            return;
        }
    }
}

void ustawObecnosc(string *TabNazwiska, bool *TabObecnosc, string nazwisko, bool obecnosc)
{
    for (int i=0; i<10; i++){
        if (TabNazwiska[i]==nazwisko)
        {
            TabObecnosc[i]=obecnosc;
            cout << "Ustawiono obecnosc\n";
            return;
        }
    }
}

void zmienNazwisko(string *TabNazwiska, string nazwisko, string nowenazwisko)
{
    for (int i=0; i<10; i++){
        if (TabNazwiska[i]==nazwisko)
        {
            TabNazwiska[i]=nowenazwisko;
            cout << "Zmieniono Nazwisko\n";
            return;
        }
    }
}

void UsunOsobe(string *TabNazwiska, string nazwisko, bool *TabObecnosc, string *TabImie, int *TabIndex)
{
    for (int i=0; i<10; i++){
        if (TabNazwiska[i]==nazwisko)
        {
            for (int j=i+1; j<10; j++)
            {
                TabNazwiska[j-1]=TabNazwiska[j];
                TabImie[j-1]=TabImie[j];
                TabIndex[j-1]=TabIndex[j];
                TabObecnosc[j-1]=TabObecnosc[j];
            }
            return;
        }
    }
}

void ustawIndex(string *TabNazwiska, int *TabIndex, string nazwisko, int Index)
{
    for (int i=0; i<10; i++){
        if (TabNazwiska[i]==nazwisko)
        {
            TabIndex[i]=Index;
            cout << "Ustawiono Index\n";
            return;
        }
    }
}

void ustawImie(string *TabNazwiska, string *TabImie, string nazwisko, string imie)
{
    for (int i=0; i<10; i++){
        if (TabNazwiska[i]==nazwisko)
        {
            TabImie[i]=imie;
            cout << "Ustawiono Imie\n";
            return;
        }
    }
}

void wyswietlliste (string *TabNazwiska, bool *TabObecnosc, string *TabImie, int *TabIndex)
{
    for (int i=0; i<10; i++){
        if (TabNazwiska[i]!="")
        {
            cout << TabIndex[i] << " " << TabImie[i] << " " << TabNazwiska[i] << " " << TabObecnosc[i] << "\n";
        }
    }
    return;
}
int main() {


    string TabNazwiska[10];
    bool TabObecnosc[10];
    int TabIndex[10];
    string TabImie[10];
    while (true)
    {
        cout << "MENU (Wybierz 1,2,3)\n";
        cout << "1. Dodaj osobe\n2. Ustaw Obecnosc\n3. Pokaz liste\n4. Ustaw index\n5. Ustaw imie\n6. Zmien nazwisko\n7. Usun osobe\n";
        int wybor;
        cin >> wybor;
        string nazwisko, nowenazwisko;
        bool obecnosc;
        int index;
        string imie;
        switch (wybor)
        {
        case 1:
            cout << "Podaj Nazwisko: ";
            cin >> nazwisko;
            dodajOsobe(TabNazwiska, nazwisko);
            break;
        case 2:
            cout << "Podaj Nazwisko i Obecnosc (0,1): ";
            cin >> nazwisko >> obecnosc;
            ustawObecnosc(TabNazwiska, TabObecnosc, nazwisko, obecnosc);
            break;
        case 3:
            wyswietlliste(TabNazwiska, TabObecnosc, TabImie, TabIndex);
            break;
        case 4:
            cout << "Podaj Nazwisko i Index: ";
            cin >> nazwisko >> index;
            ustawIndex(TabNazwiska, TabIndex, nazwisko, index);
            break;
        case 5:
            cout << "Podaj Nazwisko i Imie: ";
            cin >> nazwisko >> imie;
            ustawImie(TabNazwiska, TabImie, nazwisko, imie);
            break;
        case 6:
            cout << "Podaj Nazwisko: ";
            cin >> nazwisko >> nowenazwisko;
            zmienNazwisko(TabNazwiska, nazwisko, nowenazwisko);
            break;
        case 7:
            cout << "Podaj Nazwisko: ";
            cin >> nazwisko;
            UsunOsobe(TabNazwiska, nazwisko, TabObecnosc, TabImie, TabIndex);
        default:
            break;
        }
    }
    return 0;
}
