#include <iostream>
#include <string>

using namespace std;

class Osoba{
    private:
        int TabIndex;
        string TabImie;
        string TabNazwiska;
    public:
        bool setImie(string imie);
        string getImie();
        bool setNazwisko(string nazwisko);
        string getNazwisko();
        bool setIndex(int index);
        int getIndex();
};

class ListaObecnosci{
    private:
        Osoba *tabosob[10];
        bool tabobecnosc[10];
        int wypelnienie=0;
    public:
        void dodajOsobe(string imie, string nazwisko, int index);
        void ustawObecnosc(string nazwisko, bool obecnosc);
        void zmienNazwisko(string nazwisko, string nowenazwisko);
        void ustawIndex(string nazwisko, int index);
        void ustawImie(string nazwisko, string imie);
        void usunOsobe(string nazwisko);
        void wyswietlListe();
};

class Interfejs {
    private:
        ListaObecnosci lista;
        void pokazMenu();
        void obsluzWybor(int wybor);
    public:
        void uruchom();
};

bool Osoba::setImie(string imie){
    if(imie.length() > 1)
    {
        TabImie = imie;
        return true;
    }
    return false;
}
string Osoba::getImie(){
    return TabImie;
}
bool Osoba::setNazwisko(string nazwisko){
    if(nazwisko.length() > 1)
    {
        TabNazwiska = nazwisko;
        return true;
    }
    return false;
}
string Osoba::getNazwisko(){
    return TabNazwiska;
}
bool Osoba::setIndex(int Index){
    if(Index >= 100000 && Index <= 999999)
    {
        TabIndex = Index;
        return true;
    }
    return false;
}
int Osoba::getIndex(){
    return TabIndex;
}

void ListaObecnosci::dodajOsobe(string imie, string nazwisko, int index)
{
    if (wypelnienie >= 10) {
        cout << "Lista pelna\n";
        return;
    }

    Osoba *osoba = new Osoba();
    if (!osoba->setImie(imie)) {
        cout << "Niepoprawne imie\n";
        delete osoba;
        return;
    }
    if (!osoba->setNazwisko(nazwisko)) {
        cout << "Niepoprawne nazwisko\n";
        delete osoba;
        return;
    }
    if (!osoba->setIndex(index)) {
        cout << "Niepoprawny index\n";
        delete osoba;
        return;
    }

    tabosob[wypelnienie] = osoba;
    tabobecnosc[wypelnienie] = false;
    wypelnienie++;
    cout << "Dodano osobe\n";
}

void ListaObecnosci::ustawObecnosc(string nazwisko, bool obecnosc)
{
    for (int i = 0; i < wypelnienie; i++) {
        if (tabosob[i]->getNazwisko() == nazwisko) {
            tabobecnosc[i] = obecnosc;
            cout << "Ustawiono obecnosc\n";
            return;
        }
    }
    cout << "Osoba nie znaleziona\n";
}

void ListaObecnosci::zmienNazwisko(string nazwisko, string nowenazwisko)
{
    for (int i = 0; i < wypelnienie; i++) {
        if (tabosob[i]->getNazwisko() == nazwisko) {
            if (tabosob[i]->setNazwisko(nowenazwisko)) {
                cout << "Zmieniono nazwisko\n";
            } else {
                cout << "Niepoprawne nazwisko\n";
            }
            return;
        }
    }
    cout << "Osoba nie znaleziona\n";
}

void ListaObecnosci::ustawIndex(string nazwisko, int index)
{
    for (int i = 0; i < wypelnienie; i++) {
        if (tabosob[i]->getNazwisko() == nazwisko) {
            if (tabosob[i]->setIndex(index)) {
                cout << "Ustawiono index\n";
            } else {
                cout << "Niepoprawny index\n";
            }
            return;
        }
    }
    cout << "Osoba nie znaleziona\n";
}

void ListaObecnosci::ustawImie(string nazwisko, string imie)
{
    for (int i = 0; i < wypelnienie; i++) {
        if (tabosob[i]->getNazwisko() == nazwisko) {
            if (tabosob[i]->setImie(imie)) {
                cout << "Ustawiono imie\n";
            } else {
                cout << "Niepoprawne imie\n";
            }
            return;
        }
    }
    cout << "Osoba nie znaleziona\n";
}

void ListaObecnosci::usunOsobe(string nazwisko)
{
    for (int i = 0; i < wypelnienie; i++) {
        if (tabosob[i]->getNazwisko() == nazwisko) {
            delete tabosob[i];
            for (int j = i + 1; j < wypelnienie; j++) {
                tabosob[j - 1] = tabosob[j];
                tabobecnosc[j - 1] = tabobecnosc[j];
            }
            wypelnienie--;
            cout << "Usunieto osobe\n";
            return;
        }
    }
    cout << "Osoba nie znaleziona\n";
}

void ListaObecnosci::wyswietlListe()
{
    for (int i = 0; i < wypelnienie; i++) {
        cout << tabosob[i]->getIndex() << " " << tabosob[i]->getImie() << " " << tabosob[i]->getNazwisko() << " " << tabobecnosc[i] << "\n";
    }
}

void Interfejs::pokazMenu()
{
    cout << "MENU (Wybierz 1-7)\n";
    cout << "1. Dodaj osobe\n";
    cout << "2. Ustaw obecnosc\n";
    cout << "3. Pokaz liste\n";
    cout << "4. Ustaw index\n";
    cout << "5. Ustaw imie\n";
    cout << "6. Zmien nazwisko\n";
    cout << "7. Usun osobe\n";
    cout << "0. Wyjdz\n";
}

void Interfejs::obsluzWybor(int wybor)
{
    string nazwisko, nowenazwisko, imie;
    bool obecnosc;
    int index;

    switch (wybor) {
    case 1:
        cout << "Podaj Imie, Nazwisko, Index: ";
        cin >> imie >> nazwisko >> index;
        lista.dodajOsobe(imie, nazwisko, index);
        break;
    case 2:
        cout << "Podaj Nazwisko i Obecnosc (0,1): ";
        cin >> nazwisko >> obecnosc;
        lista.ustawObecnosc(nazwisko, obecnosc);
        break;
    case 3:
        lista.wyswietlListe();
        break;
    case 4:
        cout << "Podaj Nazwisko i Index: ";
        cin >> nazwisko >> index;
        lista.ustawIndex(nazwisko, index);
        break;
    case 5:
        cout << "Podaj Nazwisko i Imie: ";
        cin >> nazwisko >> imie;
        lista.ustawImie(nazwisko, imie);
        break;
    case 6:
        cout << "Podaj Nazwisko i Nowe Nazwisko: ";
        cin >> nazwisko >> nowenazwisko;
        lista.zmienNazwisko(nazwisko, nowenazwisko);
        break;
    case 7:
        cout << "Podaj Nazwisko: ";
        cin >> nazwisko;
        lista.usunOsobe(nazwisko);
        break;
    case 0:
        cout << "Koniec programu\n";
        break;
    default:
        cout << "Nieprawidlowy wybor\n";
        break;
    }
}

void Interfejs::uruchom()
{
    int wybor = -1;

    while (wybor != 0) {
        pokazMenu();
        cin >> wybor;
        obsluzWybor(wybor);
    }
}

int main() {
    Interfejs interfejs;
    interfejs.uruchom();
    return 0;
}
