// komis aut uzywanych
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//dekalaracja klas na potrzeby deklaracji vetorow
class Pojazd;
class Osobowe;
class Ciezarowe;
class Klient;

//deklaracja vectorow
vector < Osobowe > Os;
vector < Ciezarowe > Ci;
vector < Klient > Kl;

// klasa podstawowa auto
class Pojazd
{
    protected:
        string wlasciciel="komis";
    public:
        string marka;
        string model;
        float poj_silnika;
        int przebieg;
        int rocznik;
        int cena;
        bool sprawnosc; //True = sprawny, False = niesprawny

        Pojazd(string xmarka, string xmodel, float xpoj_silnika, int xprzebieg, int xrocznik, int xcena, bool xsprawnosc) :
            marka(xmarka), model(xmodel), poj_silnika(xpoj_silnika), przebieg(xprzebieg), rocznik(xrocznik), cena(xcena), sprawnosc(xsprawnosc){}

        void dodaj_pojazd()
        {
            cout << "\nPodaj marke:";
            cin >> marka;
            cout << "\nPodaj model:";
            cin >> model;
            cout << "\nPodaj pojemnosc silnika: ";
            cin >> poj_silnika;
            cout << "\nPodaj przebieg: ";
            cin >> przebieg;
            cout << "\nPodaj rocznik: ";
            cin >> rocznik;
            cout << "\nPodaj cena: ";
            cin >> cena;
            cout <<  "\nCzy auto jest sprawne (Tak = '1', Nie = '0'): ";
            cin >> sprawnosc;

        }
        virtual void usun_pojazd();
        virtual void sprawdz_pojazd();
        virtual void podaj_cene();

};

class Osobowe : public Pojazd
{
    public:
        int miejsca_siedzace;
        int poj_bagaznik;
        Osobowe(string marka, string model, float poj_silnika, int przebieg, int rocznik, int cena, bool sprawnosc, int xmiejsca_siedzace, int xpoj_bagaznik)
            : Pojazd(marka, model, poj_silnika, przebieg, rocznik, cena, sprawnosc)
            {
            miejsca_siedzace = xmiejsca_siedzace;
            poj_bagaznik = xpoj_bagaznik;
            }

        void dodaj_pojazd()
            {
            Pojazd::dodaj_pojazd();
            cout << "\nPodaj ilosc miejsc siedzacych: ";
            cin >> miejsca_siedzace;
            cout << "Podaj pojemosc bagazika: ";
            cin >> poj_bagaznik;
            }
};

class Ciezarowe : public Pojazd
{
    public:
        int ladownosc;
        int dlugosc;

        Ciezarowe(string marka, string model, float poj_silnika, int przebieg, int rocznik, int cena, bool sprawnosc, int xladownosc, int xdlugosc)
            : Pojazd(marka, model, poj_silnika, przebieg, rocznik, cena, sprawnosc)
            {
            ladownosc = xladownosc;
            dlugosc = xdlugosc;
            }

            void dodaj_pojazd()
            {
            Pojazd::dodaj_pojazd();
            cout << "\nPodaj ladownosc: ";
            cin >> ladownosc;
            cout << "Podaj dlugosc: ";
            cin >> dlugosc;
            }

};

class Klient
{
    private:
        string imie;
        string nazwisko;
        int wiek;
    public:
        int upust=0; //procent upustu za ilosc kupionych aut;
        int kupione=0;

    void dodaj_klienta()
    {
        cout << "\nPodaj imie: ";
        cin >> imie;
        cout << "\nPodaj nazwisko: ";
        cin >> nazwisko;
        cout << "\nPodaj wiek: ";
        cin >> wiek;
    }

};

int main()
{

    return 0;
}
