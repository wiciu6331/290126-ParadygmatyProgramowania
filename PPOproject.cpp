#include <iostream>
#include <string>

using namespace std;

class Osoba{
    private:
        int TabIndex;
        string TabImie;
        string TabNazwiska;
    public:
        void setImie(string imie);
        string getImie();
        void setNazwisko(string nazwisko);
        string getNazwisko();
        void setIndex(int index);
        int getIndex();
};
void Osoba::setImie(string imie){
    if(imie.length()>1)
    {
        TabImie=imie;
        cout << "Ustawiono Imie\n";
    }
    else
    {
        cout << "Niepoprawne imie\n";
    }
}
string Osoba::getImie(){
    return TabImie;
}
void Osoba::setNazwisko(string nazwisko){
    if(nazwisko.length()>1)
    {
        TabNazwiska=nazwisko;
        cout << "Ustawiono nazwisko\n";
    }
    else
    {
        cout << "Niepoprawne nazwisko\n";
    }
}
string Osoba::getNazwisko(){
    return TabNazwiska;
}
void Osoba::setIndex(int Index){
    if(Index>=100000 && Index<=999999)
    {
        TabIndex=Index;
        cout << "Ustawiono Index\n";
    }
    else
    {
        cout << "Niepoprawny index\n";
    }
}
int Osoba::getIndex(){
    return TabIndex;
}

void dodajOsobe(Osoba *TabOsob, string nazwisko)
{
    for (int i=0; i<10; i++){
        if (TabOsob[i].getNazwisko()=="")
        {
            TabOsob[i].setNazwisko(nazwisko);
            return;
        }
    }
}

void ustawObecnosc(Osoba *TabOsob, bool *TabObecnosc, string nazwisko, bool obecnosc)
{
    for (int i=0; i<10; i++){
        if (TabOsob[i].getNazwisko()==nazwisko)
        {
            TabObecnosc[i]=obecnosc;
            cout << "Ustawiono obecnosc\n";
            return;
        }
    }
}

void zmienNazwisko(Osoba *TabOsob, string nazwisko, string nowenazwisko)
{
    for (int i=0; i<10; i++){
        if (TabOsob[i].getNazwisko()==nazwisko)
        {
            TabOsob[i].setNazwisko(nowenazwisko);
            return;
        }
    }
}

void UsunOsobe(Osoba *TabOsob, string nazwisko, bool *TabObecnosc)
{
    for (int i=0; i<10; i++){
        if (TabOsob[i].getNazwisko()==nazwisko)
        {
            for (int j=i+1; j<10; j++)
            {
                TabOsob[j-1].setNazwisko(TabOsob[j].getNazwisko());
                TabOsob[j-1].setImie(TabOsob[j].getImie());
                TabOsob[j-1].setIndex(TabOsob[j].getIndex());
                TabObecnosc[j-1]=TabObecnosc[j];
            }
            return;
        }
    }
}

void ustawIndex(Osoba *TabOsob, string nazwisko, int Index)
{
    for (int i=0; i<10; i++){
        if (TabOsob[i].getNazwisko()==nazwisko)
        {
            TabOsob[i].setIndex(Index);
            return;
        }
    }
}

void ustawImie(Osoba *TabOsob, string nazwisko, string imie)
{
    for (int i=0; i<10; i++){
        if (TabOsob[i].getNazwisko()==nazwisko)
        {
            TabOsob[i].setImie(imie);
            return;
        }
    }
}

void wyswietlliste (Osoba *TabOsob, bool *TabObecnosc)
{
    for (int i=0; i<10; i++){
        if (TabOsob[i].getNazwisko()!="")
        {
            cout << TabOsob[i].getIndex() << " " << TabOsob[i].getImie() << " " << TabOsob[i].getNazwisko() << " " << TabObecnosc[i] << "\n";
        }
    }
    return;
}
int main() {


    
    bool TabObecnosc[10];
    Osoba TabOsob[10];
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
            dodajOsobe(TabOsob, nazwisko);
            break;
        case 2:
            cout << "Podaj Nazwisko i Obecnosc (0,1): ";
            cin >> nazwisko >> obecnosc;
            ustawObecnosc(TabOsob, TabObecnosc, nazwisko, obecnosc);
            break;
        case 3:
            wyswietlliste(TabOsob, TabObecnosc);
            break;
        case 4:
            cout << "Podaj Nazwisko i Index: ";
            cin >> nazwisko >> index;
            ustawIndex(TabOsob, nazwisko, index);
            break;
        case 5:
            cout << "Podaj Nazwisko i Imie: ";
            cin >> nazwisko >> imie;
            ustawImie(TabOsob, nazwisko, imie);
            break;
        case 6:
            cout << "Podaj Nazwisko: ";
            cin >> nazwisko >> nowenazwisko;
            zmienNazwisko(TabOsob, nazwisko, nowenazwisko);
            break;
        case 7:
            cout << "Podaj Nazwisko: ";
            cin >> nazwisko;
            UsunOsobe(TabOsob, nazwisko, TabObecnosc);
        default:
            break;
        }
    }
    return 0;
}
