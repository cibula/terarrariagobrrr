#include <iostream>
#include <string>
using namespace std;

class Predmet {

private:
    int broj;
    string vrsta;
public:
    virtual double Cena() = 0;
    void PodesiVrstu(string s) {

        vrsta = s;

    }

    void Povecaj() {

        broj++;

    }

    void Povecaj(int k) {

        while(k--) {

            broj++;

        }

    }

    int Kolicina() {

        return broj;

    }

    string Vrsta() {

        return vrsta;

    }

};

class Alat : public Predmet {

private:
    int demidz;
    int izdrzljivost;
    int efikasnost;
public:
    double Cena() {

        return demidz * izdrzljivost * efikasnost * 0.2;

    }

    Alat operator+(const Alat& a) {

        Alat alat;
        alat.demidz = this->demidz + a.demidz;
        alat.izdrzljivost = this->izdrzljivost + a.izdrzljivost;
        alat.efikasnost = this->efikasnost + a.efikasnost;
        return alat;

    }

    Alat operator-(const Alat& a) {

        Alat alat;
        alat.demidz = this->demidz - a.demidz;
        alat.izdrzljivost = this->izdrzljivost - a.izdrzljivost;
        alat.efikasnost = this->efikasnost - a.efikasnost;
        return alat;

    }

    Alat operator*(const Alat& a) {

        Alat alat;
        alat.demidz = this->demidz * a.demidz;
        alat.izdrzljivost = this->izdrzljivost * a.izdrzljivost;
        alat.efikasnost = this->efikasnost * a.efikasnost;
        return alat;

    }

    Alat operator/(const Alat& a) {

        Alat alat;
        alat.demidz = this->demidz / a.demidz;
        alat.izdrzljivost = this->izdrzljivost / a.izdrzljivost;
        alat.efikasnost = this->efikasnost / a.efikasnost;
        return alat;

    }

    Alat() {

        PodesiVrstu("");
        demidz = 0;
        izdrzljivost = 0;
        efikasnost = 0;

    }

    Alat(const Alat& a) {

        demidz = a.demidz;
        izdrzljivost = a.izdrzljivost;
        efikasnost = a.efikasnost;

    }

    Alat(string s) {

        PodesiVrstu(s);
        demidz = 0;
        izdrzljivost = 0;
        efikasnost = 0;

    }

    Alat(string s, int d, int i, int e) {

        PodesiVrstu(s);
        demidz = d;
        izdrzljivost = i;
        efikasnost = e;

    }

    Alat(Alat* a, Alat* b) {

        string ime = a->Vrsta() + "o" + b->Vrsta();
        PodesiVrstu(ime);
        Alat tmp = *a;
        tmp = tmp + *b;
        demidz = tmp.demidz;
        tmp = *a;
        tmp = tmp - *b;
        izdrzljivost = abs(tmp.izdrzljivost);
        tmp = *a;
        tmp = tmp * (*b);
        efikasnost = tmp.efikasnost;

    }

    void PodesiDemidz(int d) {

        demidz = d;

    }

    void PodesiIzdrzljivost(int i) {

        izdrzljivost = i;

    }

    void PodesiEfikasnost(int e) {

        efikasnost = e;

    }

    int Demidz() {

        return demidz;

    }

    int Izdrzljivost() {

        return izdrzljivost;

    }

    int Efikasnost() {

        return efikasnost;

    }

    friend ostream& operator<<(ostream& os, const Alat& alat);

};

class Oruzje : public Predmet {

private:
    int demidz;
    int izdrzljivost;
    int crit;
public:
    double Cena() {

        return demidz * izdrzljivost * crit * 0.2;

    }

    Oruzje operator+(const Oruzje& a) {

        Oruzje oruzje;
        oruzje.demidz = this->demidz + a.demidz;
        oruzje.izdrzljivost = this->izdrzljivost + a.izdrzljivost;
        oruzje.crit = this->crit + a.crit;
        return oruzje;

    }

    Oruzje operator-(const Oruzje& a) {

        Oruzje oruzje;
        oruzje.demidz = this->demidz - a.demidz;
        oruzje.izdrzljivost = this->izdrzljivost - a.izdrzljivost;
        oruzje.crit = this->crit - a.crit;
        return oruzje;

    }

    Oruzje operator*(const Oruzje& a) {

        Oruzje oruzje;
        oruzje.demidz = this->demidz * a.demidz;
        oruzje.izdrzljivost = this->izdrzljivost * a.izdrzljivost;
        oruzje.crit = this->crit * a.crit;
        return oruzje;

    }

    Oruzje operator/(const Oruzje& a) {

        Oruzje oruzje;
        oruzje.demidz = this->demidz / a.demidz;
        oruzje.izdrzljivost = this->izdrzljivost / a.izdrzljivost;
        oruzje.crit = this->crit / a.crit;
        return oruzje;

    }

    Oruzje(const Oruzje& o) {

        demidz = o.demidz;
        izdrzljivost = o.izdrzljivost;
        crit = o.crit;

    }

    Oruzje() {

        PodesiVrstu("");
        demidz = 0;
        izdrzljivost = 0;
        crit = 0;

    }

    Oruzje(string s) {

        PodesiVrstu(s);
        demidz = 0;
        izdrzljivost = 0;
        crit = 0;

    }

    Oruzje(string s,int d, int i, int c) {

        PodesiVrstu(s);
        demidz = d;
        izdrzljivost = i;
        crit = c;

    }

    Oruzje(Oruzje* a, Oruzje* b) {

        string ime = a->Vrsta() + "o" + b->Vrsta();
        PodesiVrstu(ime);
        Oruzje tmp = *a;
        tmp = tmp + *b;
        demidz = tmp.demidz;
        tmp = *a;
        tmp = tmp - *b;
        izdrzljivost = abs(tmp.izdrzljivost);
        tmp = *a;
        tmp = tmp * (*b);
        crit = tmp.crit;

    }

    void PodesiDemidz(int d) {

        demidz = d;

    }

    void PodesiIzdrzljivost(int i) {

        izdrzljivost = i;

    }

    void PodesiCrit(int c) {

        crit = c;

    }

    int Demidz() {

        return demidz;

    }

    int Izdrzljivost() {

        return izdrzljivost;

    }

    int Crit() {

        return crit;

    }

    friend ostream& operator<<(ostream& os, const Oruzje& oruzje);

};

class Slot {

private:
    bool prazan;
    bool tip;
    Alat alat;
    Oruzje oruzje;
public:
    bool Prazan() {

        return prazan;

    }

    Slot() {

        prazan = 0;

    }

    Slot(Oruzje* o) {

        oruzje = *o;
        prazan = 0;
        tip = 0;

    }

    Slot(Alat* a) {

        alat = *a;
        prazan = 0;
        tip = 1;

    }

    Oruzje SlotOruzje() {

        return oruzje;

    }

    Alat SlotAlat() {

        return alat;

    }

    bool Tip() {

        return tip;

    }

    friend ostream& operator<<(ostream& os, const Slot& slot);

};

typedef struct lista
{

    struct lista* head;
    struct lista* next;
    Slot* value;

} lista;

class Inventory {

private: 
    lista* niz = new lista;
    bool pun;
    int broj_kvadratica;
    int prvi_prazan;
public:
    Inventory() {

        pun = 0;
        broj_kvadratica = 50;
        prvi_prazan = 0;
        niz->head = niz;
        lista* tmp = new lista;

        for (int i = 1; i < broj_kvadratica; i++) {

            lista* novi_clan = new lista;
            tmp->next = novi_clan;
            tmp = tmp->next;

        }

    }

    bool Pun() {

        return pun;

    }

    void Ubaci(Alat* p) {

        lista* tmp = niz;

        for (int i = 0; i < broj_kvadratica; i++) {

            if (tmp->value->Prazan()) continue;

            if (tmp->value->Tip() == 1) continue;

            Alat q = tmp->value->SlotAlat();

            if (q.Vrsta() == p->Vrsta()) {

                tmp->value->SlotAlat().Povecaj();
                return;

            }

            tmp = tmp->next;

        }

        if (Pun()) return;

        int poz = -1;
        tmp = niz;

        for (int i = 0; i < broj_kvadratica && poz == -1; i++) {

            if (tmp->value->Prazan()) poz = i;
            tmp = tmp->next;

        }

        tmp = niz;

        for (int i = 0; i < poz; i++) {

            tmp = tmp->next;

        }

        tmp->value = new Slot(p);

        if (poz + 1 == broj_kvadratica) pun = 1;

    }

    void Ubaci(Oruzje* p) {

        lista* tmp = niz;

        for (int i = 0; i < broj_kvadratica; i++) {

            if (tmp->value->Prazan()) continue;

            if (tmp->value->Tip() == 1) continue;

            Oruzje q = tmp->value->SlotOruzje();

            if (q.Vrsta() == p->Vrsta()) {

                tmp->value->SlotOruzje().Povecaj();
                return;

            }

            tmp = tmp->next;

        }

        if (Pun()) return;

        int poz = -1;
        tmp = niz;

        for (int i = 0; i < broj_kvadratica && poz == -1; i++) {

            if (tmp->value->Prazan()) poz = i;
            tmp = tmp->next;

        }

        tmp = niz;

        for (int i = 0; i < poz; i++) {

            tmp = tmp->next;

        }

        tmp->value = new Slot(p);
        if (poz + 1 == broj_kvadratica) pun = 1;

    }

    void Izbaci(int k) {

        lista* tmp = niz;
        for (int i = 1; i < k; i++) tmp = tmp->next;
        tmp->value = new Slot();

    }

};

ostream& operator<<(ostream& os, const Slot& slot) {

    os << "prazan: " << slot.prazan;

}

ostream& operator<<(ostream& os, const Alat& alat) {

    os << "demidz: " << alat.demidz << endl;
    os << "izdrzljivost: " << alat.izdrzljivost << endl;
    os << "efikasnost: " << alat.efikasnost;

}

ostream& operator<<(ostream& os, const Oruzje& oruzje) {

    os << "demidz: " << oruzje.demidz << endl;
    os << "izdrzljivost: " << oruzje.izdrzljivost << endl;
    os << "crit: " << oruzje.crit;

}
