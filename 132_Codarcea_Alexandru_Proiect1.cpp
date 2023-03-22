#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <thread>

using namespace std;

void clearScreen()
{
    system("CLS");
}

void displayMeniuUtilizator()
{
    clearScreen();
    cout << "---Meniu Utilizator---" << endl << endl;
    cout << "1-Introduceti-va datele" << endl;
    cout << "2-Inapoi" << endl;
}

void displayMeniuUtilizator2()
{
    clearScreen();
    cout << "---Meniu Utilizator---" << endl << endl;
    cout << "1-Inapoi la Meniu Utilizator" << endl;
    cout << "2-Inapoi" << endl;
}


void displaySubMeniuUtilizator()
{
    clearScreen();
    cout << "---Meniu Utilizator---" << endl << endl;

    cout << "1-Alegeti-va Antrenorul Personal" << endl;
    cout << "2-Alegeti-va Abonamentul" << endl;
    cout << "3-Vedeti potentialul maxim de masa musculara al dumneavoastra" << endl;
    cout << "4-Vedeti data incheierii abonamentului dumneavoastra" << endl;
    cout << "5-Rezervati Echipament" << endl;
    cout << "6-Returnati Echipament" << endl;
    cout << "7-Inapoi" << endl;
}

void displayMeniuAdmin()
{
    clearScreen();
    cout << "---Meniu Admin---" << endl << endl;
    cout << "Introduceti Parola: ";
}

void displaySubMeniuAdmin()
{
    clearScreen();
    cout << "---Meniu Admin---" << endl << endl;
    cout << "1-Adauga Membru" << endl;
    cout << "2-Adauga Antrenor" << endl;
    cout << "3-Adauga Abonament" << endl;
    cout << "4-Adauga Echipament" << endl;
    cout << "5-Vezi Lista de Membrii" << endl;
    cout << "6-Vezi Lista de Antrenori" << endl;
    cout << "7-Vezi Lista de Abonamente" << endl;
    cout << "8-Vezi Lista de Echipamente" << endl;
    cout << "9-Sterge Membru" << endl;
    cout << "10-Sterge Antrenor" << endl;
    cout << "11-Sterge Abonament" << endl;
    cout << "12-Sterge Echipament" << endl;
    cout << "13-Schimba Salariu Antrenor" << endl;
    cout << "14-Schimba Status Mentenanta Echipament" << endl;
    cout << "15-Inapoi" << endl;

}

void pauza(int secunde)
{
    this_thread::sleep_for(chrono::seconds(secunde));
}


struct data
{
    int zi;
    int luna;
    int an;

};

class Antrenor;
class Abonament;

class Membru
{

private:
    const int id;
    static int contorId;
    char* nume;
    char sex;
    bool natural;
    int anulNasterii;
    float inaltime;
    float kg;
    string grupaPreferata;
    Antrenor* antrenorPersonal;
    Abonament* abonament;

public:
    ///constructorii
    Membru();
    Membru(char* nume, char sex, bool natural, int anulNasterii, float inaltime,float kg, string grupaPreferata, Antrenor* antrenorPersonal, Abonament* abonament);
    Membru(const Membru& obj);
    Membru(bool natural);
    Membru(char *nume);


    ///operatorii

    Membru& operator=(const Membru& obj);
    friend ostream& operator<<(ostream& out, const Membru& obj);
    friend istream& operator>>(istream& in, Membru& obj);
    float operator[](int);
    Membru& operator++();
    Membru operator++(int);
    Membru operator+(const Membru& obj);
    Membru operator+(int);
    friend Membru operator+(int, Membru obj);
    friend Membru operator+ (const Membru& obj1, const Antrenor& obj2); ///Membru+Antrenor (adunarea intre clase diferie)
    friend Membru operator+ (const Antrenor& obj1, const Membru& obj2); ///Antrenor+Membru (adunarea intre clase diferie)
    Membru operator-(const Membru& obj);
    Membru operator-(int);
    friend Membru operator-(int, Membru obj);
    bool operator==(const Membru&);
    bool operator<(const Membru& obj);
    bool operator>(const Membru& obj);
    operator int();

    ///functia utila
    void potential()
    {
        if(this->natural==true)
        {
            float maxim=this->inaltime-100;
            cout << "Greutatea ideala pentru potentialul dumneavoastra maxim de masa musculara este : " << maxim << " kg." << endl;
            if (maxim-this->kg<0)
                cout<< "Trebuie sa mai slabiti " << this->kg-maxim << " kg." << endl;
            else
                cout<< "Trebuie sa mai puneti " << maxim-this->kg << " kg de masa musculara." << endl;

        }
        else
        {
            float maxim=this->inaltime-80;
            cout << "Greutatea ideala pentru potentialul dumneavoastra maxim de masa musculara este : " << maxim <<" kg." << endl;
            if (maxim-this->kg<0)
                cout<< "Trebuie sa mai slabiti " << this->kg-maxim << " kg. " << endl;
            else
                cout<< "Trebuie sa mai puneti " << maxim-this->kg << " kg de masa musculara. " << endl;

        }
    }

    ///getteri & setteri
    int static getContorId();
    int getId();
    const char* getNume();
    char getSex();
    bool getNatural();
    int getAnulNasterii();
    float getInaltime();
    float getKg();
    string getGrupaPreferata();
    Antrenor* getAntrenorPersonal();
    Abonament* getAbonament();

    void settNume(const char* nume);
    void settSex(char sex);
    void settNatural(bool natural);
    void settAnulNasterii(int anulNasterii);
    void settInaltime(float inaltime);
    void settKg(float kg);
    void settGrupaPreferata(string grupaPreferata);
    void settAntrenorPersonal(Antrenor* antrenor);
    void settAbonament(Abonament* abonament);



    ///destructor
    ~Membru();
};


class Antrenor
{

    const int id;
    static int contorId;
    char* nume;
    char sex;
    int nrAniDeActivitate;
    int* aniDeActivitate;
    bool natural;
    double salariu;
    string specializare;

public:

    ///constructorii
    Antrenor();
    Antrenor(char* nume, char sex, bool natural, int nrAniDeActivitate, int* aniDeActivitate, double salariu, string specializare);
    Antrenor(const Antrenor& obj);
    Antrenor(bool natural);
    Antrenor(char *nume);
    ///operatorii
    Antrenor& operator=(const Antrenor& obj);
    friend ostream& operator<<(ostream& out, const Antrenor& obj);
    friend istream& operator>>(istream& in, Antrenor& obj);
    int operator[](int);
    Antrenor& operator++();
    Antrenor operator++(int);
    Antrenor operator+(const Antrenor& obj);
    Antrenor operator+(int);
    friend Antrenor operator+(int, Antrenor obj);
    Antrenor operator-(const Antrenor& obj);
    Antrenor operator-(int);
    friend Antrenor operator-(int, Antrenor obj);
    bool operator==(const Antrenor&);
    bool operator<(const Antrenor& obj);
    bool operator>(const Antrenor& obj);
    operator int();

    ///functia utila

    void vechimeInDomeniu()
    {
        int maxim=aniDeActivitate[0],minim=aniDeActivitate[0];
        for(int i=1; i<this->nrAniDeActivitate; i++)
        {
            if(maxim<aniDeActivitate[i])
                maxim=aniDeActivitate[i];
            if(minim>aniDeActivitate[i])
                minim=aniDeActivitate[i];

        }
        cout<<"Vechimea in domeniu a antrenorului " << this->nume << " este de " << maxim-minim+1 << " ani.";
    }
    ///getteri & setteri
    int static getContorId();
    int getId();
    const char* getNume();
    char getSex();
    bool getNatural();
    int getNrAniDeActivitate();
    double getSalariu();
    string getSpecializare()const;
    const int* getAniDeActivitate();

    void settNume(const char* nume);
    void settSex(char sex);
    void settNatural(bool natural);
    void settNrAniDeActivitate(int nrAniDeActivitate);
    void settSalariu(double salariu);
    void settSpecializare(string specializare);
    void settAniDeActivitate(int nrAniDeActivitate, int* aniDeActivitate);

    ///destructor
    ~Antrenor();

};

///ANTRENOR
int Antrenor::contorId = 0;

///constructorii
Antrenor::Antrenor():id(contorId++)
{
    nume=new char[strlen("Anonim")+1];
    strcpy(nume,"Anonim");
    sex='X';
    natural=true;
    nrAniDeActivitate=0;
    specializare="Spate";
    aniDeActivitate=NULL;
    salariu=0;


}
Antrenor::Antrenor(char* nume, char sex, bool natural, int nrAniDeActivitate, int* aniDeActivitate, double salariu, string specializare):id(contorId++)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->sex=sex;
    this->natural=natural;
    this->nrAniDeActivitate=nrAniDeActivitate;
    this->aniDeActivitate = new int[nrAniDeActivitate];
    for(int i=0; i<nrAniDeActivitate; i++)
        this->aniDeActivitate[i]= aniDeActivitate[i];
    this->salariu=salariu;
    this->specializare=specializare;

}

Antrenor::Antrenor(const Antrenor& obj):id(contorId++)
{
    this->nume=new char[strlen(obj.nume)+1];
    strcpy(this->nume,obj.nume);
    this->sex=obj.sex;
    this->natural=obj.natural;
    this->nrAniDeActivitate=obj.nrAniDeActivitate;
    this->salariu=obj.salariu;
    this->specializare=obj.specializare;
    this->aniDeActivitate = new int[obj.nrAniDeActivitate];
    for(int i=0; i<obj.nrAniDeActivitate; i++)
        this->aniDeActivitate[i]= obj.aniDeActivitate[i];

}

Antrenor::Antrenor(bool natural):id(contorId++)
{
    this->natural=natural;
    this->nume=new char[strlen("Anonim")+1];
    strcpy(this->nume,"Anonim");
    this->sex='X';
    this->nrAniDeActivitate=0;
    this->salariu=0;
    this->specializare="Spate";
    this->aniDeActivitate=NULL;


}

Antrenor::Antrenor(char* nume):id(contorId++)
{

    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->sex='X';
    this->nrAniDeActivitate=0;
    this->salariu=0;
    this->specializare="Spate";
    this->aniDeActivitate=NULL;
    this->natural=true;





}

///getteri & setteri
Antrenor::getContorId()
{
    return Antrenor::contorId;
};
Antrenor::getId()
{
    return this->id;
};
const char* Antrenor::getNume()
{
    return this->nume;
};
char Antrenor::getSex()
{
    return this->sex;
};
bool Antrenor::getNatural()
{
    return this->natural;
};
Antrenor::getNrAniDeActivitate()
{
    return this->nrAniDeActivitate;
};
const int* Antrenor::getAniDeActivitate()
{
    return this->aniDeActivitate;
};
double Antrenor::getSalariu()
{
    return this->salariu;
};
string Antrenor::getSpecializare()const
{
    return this->specializare;
};

void Antrenor::settSex(char sex)
{
    this->sex=sex;
}
void Antrenor::settNatural(bool natural)
{
    this->natural=natural;
}
void Antrenor::settNrAniDeActivitate(int nrAniDeActivitate)
{
    this->nrAniDeActivitate=nrAniDeActivitate;
}
void Antrenor::settSalariu(double salariu)
{
    this->salariu=salariu;
}
void Antrenor::settSpecializare(string specializare)
{
    this->specializare=specializare;
}
void Antrenor::settAniDeActivitate(int nrAniDeActivitate, int* aniDeActivitate)
{
    if(this->aniDeActivitate != NULL)
    {
        delete[] this->aniDeActivitate;
        this->aniDeActivitate = NULL;
    }
    this->nrAniDeActivitate = nrAniDeActivitate;
    this->aniDeActivitate = new int[nrAniDeActivitate];
    for(int i = 0 ; i < this->nrAniDeActivitate; i++)
        this->aniDeActivitate[i] = aniDeActivitate[i];
}
void Antrenor::settNume(const char* nume)
{
    if (this->nume!=NULL)
    {
        delete[] nume;
    }
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
}

///operatorii
Antrenor& Antrenor::operator=(const Antrenor& obj)
{
    if (this!=&obj)
    {
        if(this->nume!=NULL)
        {
            delete [] this->nume;
            this->nume=NULL;
        }

        this->nume=new char[strlen(obj.nume)+1];
        strcpy(this->nume,obj.nume);

        this->sex=obj.sex;
        this->natural=obj.natural;
        this->nrAniDeActivitate=obj.nrAniDeActivitate;
        this->salariu=obj.salariu;
        this->specializare=obj.specializare;
        if(this->aniDeActivitate!=NULL)
        {
            delete [] this->aniDeActivitate;
            this->aniDeActivitate=NULL;
        }
        this->aniDeActivitate=new int[obj.nrAniDeActivitate];
        for(int i = 0; i < obj.nrAniDeActivitate; i++)
            this->aniDeActivitate[i] = obj.aniDeActivitate[i];


    }
    return *this;

}


ostream& operator<<(ostream& out, const Antrenor& obj)
{
    out << "Informatii antrenor: " << endl;
    out << "ID: " << obj.id << endl;
    out << "Nume: " << obj.nume << endl;
    out << "Sex: " << obj.sex << endl;
    out << "Natural: " << (obj.natural ? "Da" : "Nu") << endl;
    out << "Total Ani De Activitate: " << obj.nrAniDeActivitate << endl;
    out<< "Ani De Activitate: ";
    for(int i = 0; i < obj.nrAniDeActivitate; i++)
        out << obj.aniDeActivitate[i] << ",";
    out<<endl;
    out << "Salariu: "<<obj.salariu<<endl;
    out << "Specializare: " << obj.specializare<<endl;
    out<<endl;
    return out;

}



istream& operator >>(istream& in, Antrenor& obj)
{

    cout << "Nume: ";
    char aux[100];
    in >> aux;
    if(obj.nume != NULL)
    {
        delete[] obj.nume;
    }
    obj.nume = new char[strlen(aux)+1];
    strcpy(obj.nume, aux);

    cout << "Sex (M sau F): ";
    in >> obj.sex;

    cout << "Natural (0 sau 1): ";
    in >> obj.natural;

    cout << "Total Ani De Activitate: ";
    in >> obj.nrAniDeActivitate;
    cout<<"Ani De Activitate:";
    if(obj.aniDeActivitate != NULL)
    {
        delete[] obj.aniDeActivitate;
        obj.aniDeActivitate = NULL;
    }

    obj.aniDeActivitate = new int[obj.nrAniDeActivitate];
    for(int i = 0; i < obj.nrAniDeActivitate; i++)
        in >> obj.aniDeActivitate[i];


    cout << "Salariu: ";
    in >> obj.salariu;

    cout << "Specializare: ";
    cin.ignore(10000, '\n');
    getline(in, obj.specializare);

    cout << endl;
    return in;
}

int Antrenor::operator[](int i)
{
    if(this->aniDeActivitate == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > this->nrAniDeActivitate)
    {
        throw runtime_error("Index invalid");
    }
    else
        return this->aniDeActivitate[i];
}
Antrenor& Antrenor::operator++()
{
    this->salariu++;
    return *this;
}

Antrenor Antrenor::operator++(int)
{
    Antrenor aux(*this);
    ++*this;
    return aux;


}

Antrenor Antrenor::operator+(const Antrenor& obj)
{
    Antrenor aux(*this);
    aux.salariu += obj.salariu;
    return aux;
}

Antrenor Antrenor::operator+(int x)
{
    Antrenor aux(*this);
    aux.salariu += x;
    return aux;
}

Antrenor operator+(int x, Antrenor obj)
{
    return obj+x;
}
Antrenor Antrenor::operator-(const Antrenor& obj)
{
    Antrenor aux(*this);
    aux.salariu -= obj.salariu;
    return aux;
}

Antrenor Antrenor::operator-(int x)
{
    Antrenor aux(*this);
    aux.salariu -= x;
    return aux;
}

Antrenor operator-(int x, Antrenor obj)
{
    return obj-x;
}

bool Antrenor::operator==(const Antrenor& obj)
{
    return this->natural == obj.natural;
}
bool Antrenor::operator<(const Antrenor& obj)
{
    if(this->salariu < obj.salariu) return 1;
    return 0;
}
bool Antrenor::operator>(const Antrenor& obj)
{
    if(this->salariu > obj.salariu) return 1;
    return 0;
}
Antrenor::operator int()
{
    return this->salariu;
}
///destructor
Antrenor::~Antrenor()
{
    if(this->aniDeActivitate != NULL)
    {
        delete[] this->aniDeActivitate;
        this->aniDeActivitate = NULL;
    }

    if (this->nume!=NULL)
    {
        delete[] this->nume;
        this->nume=NULL;
    }
}


class Abonament
{
    string numeAbonament;
    double pret;
    int durata;
    data dataIncepere;
public:
///constructorii
    Abonament();
    Abonament(string numeAbonament, double pret, int durata, data dataIncepere);
    Abonament(string numeAbonament, double pret, int durata);
    Abonament(const Abonament& obj);
    Abonament(double pret);
    Abonament(string numeAbonament);

    ///operatorii
    Abonament& operator=(const Abonament& obj);
    friend ostream& operator<<(ostream& out, const Abonament& obj);
    friend istream& operator>>(istream& in, Abonament& obj);
    int operator[](int);
    Abonament& operator++();
    Abonament operator++(int);
    Abonament operator+(const Abonament& obj);
    Abonament operator+(int);
    friend Abonament operator+(int, Abonament obj);
    Abonament operator-(const Abonament& obj);
    Abonament operator-(int);
    friend Abonament operator-(int, Abonament obj);
    bool operator==(const Abonament&);
    bool operator<(const Abonament& obj);
    bool operator>(const Abonament& obj);
    operator int();

    ///functia utila

    void dataIncheiere()
    {

        tm date = {0, 0, 0, this->dataIncepere.zi, this->dataIncepere.luna-1, this->dataIncepere.an - 1900};

        chrono::system_clock::time_point tp =chrono::system_clock::from_time_t(mktime(&date));
        chrono::duration<int, ratio<86400>> days_to_add(this->durata);
        tp += days_to_add;

        time_t tt = chrono::system_clock::to_time_t(tp);
        tm result = *localtime(&tt);

        result.tm_year += 1900;
        result.tm_mon += 1;

        cout << "Data incheierii abonamentului dumneavoastra este : " << result.tm_mday << "/" << result.tm_mon << "/" << result.tm_year << "." << endl;
    }
    ///getteri & setteri
    double getPret();
    int getDurata();
    int getZi();
    int getLuna();
    int getAn();
    string getNumeAbonament();

    void settPret(double pret);
    void settDurata(int durata);
    void settZi(int zi);
    void settLuna(int luna);
    void settAn(int an);

    ///destructor

    ~Abonament() {};

};

///ABONAMENT

///constructorii
Abonament::Abonament()
{
    numeAbonament="Nimic";
    pret=0;
    durata=30;
    dataIncepere.zi=0;
    dataIncepere.an=0;
    dataIncepere.luna=0;


}
Abonament::Abonament(string numeAbonament, double pret, int durata, data dataIncepere)
{
    this->numeAbonament=numeAbonament;
    this->pret=pret;
    this->durata=durata;
    this->dataIncepere.zi=dataIncepere.zi;
    this->dataIncepere.an=dataIncepere.an;
    this->dataIncepere.luna=dataIncepere.luna;


}
Abonament::Abonament(string numeAbonament, double pret, int durata)
{
    this->numeAbonament=numeAbonament;
    this->pret=pret;
    this->durata=durata;
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm tm = *localtime(&t);
    int zi = tm.tm_mday;
    int luna = tm.tm_mon + 1;
    int an = tm.tm_year + 1900;
    this->dataIncepere.zi=zi;
    this->dataIncepere.luna=luna;
    this->dataIncepere.an=an;

}

Abonament::Abonament(const Abonament& obj)
{
    this->numeAbonament=obj.numeAbonament;
    this->pret=obj.pret;
    this->durata=obj.durata;
    this->dataIncepere.zi=obj.dataIncepere.zi;
    this->dataIncepere.an=obj.dataIncepere.an;
    this->dataIncepere.luna=obj.dataIncepere.luna;

}

Abonament::Abonament(double pret)
{
    this->numeAbonament="Nimic";
    this->pret=pret;
    this->durata=30;
    this->dataIncepere.zi=0;
    this->dataIncepere.an=0;
    this->dataIncepere.luna=0;


}

Abonament::Abonament(string numeAbonament)
{
    this->numeAbonament=numeAbonament;
    this->pret=0;
    this->durata=30;
    this->dataIncepere.zi=0;
    this->dataIncepere.an=0;
    this->dataIncepere.luna=0;


}

///getteri & setteri
string Abonament::getNumeAbonament()
{
    return this->numeAbonament;
}
double Abonament::getPret()
{
    return this->pret;
};
Abonament::getDurata()
{
    return this->durata;
};
Abonament::getZi()
{
    return this->dataIncepere.zi;
};
Abonament::getLuna()
{
    return this->dataIncepere.luna;
};
Abonament::getAn()
{
    return this->dataIncepere.an;
};

void Abonament::settPret(double pret)
{
    this->pret=pret;
};
void Abonament::settDurata(int durata)
{
    this->durata=durata;
};
void Abonament::settZi(int zi)
{
    this->dataIncepere.zi=zi;
};
void Abonament::settLuna(int luna)
{
    this->dataIncepere.luna=luna;
};
void Abonament::settAn(int an)
{
    this->dataIncepere.an=an;
};


///operatorii
Abonament& Abonament::operator=(const Abonament& obj)
{

    this->numeAbonament=obj.numeAbonament;
    this->pret=obj.pret;
    this->durata=obj.durata;
    this->dataIncepere.zi=obj.dataIncepere.zi;
    this->dataIncepere.an=obj.dataIncepere.an;
    this->dataIncepere.luna=obj.dataIncepere.luna;

    return *this;

}


ostream& operator<<(ostream& out, const Abonament& obj)
{
    out << "Informatii abonament: " << endl;
    out << "Nume Abonament: " << obj.numeAbonament << endl;
    out << "Pret: " << obj.pret << endl;
    out << "Durata (in zile): " << obj.durata << endl;
    out << "Data Incepere: " << obj.dataIncepere.zi <<"/"<<obj.dataIncepere.luna<<"/"<<obj.dataIncepere.an<<endl;
    out << endl;
    return out;

}



istream& operator >>(istream& in, Abonament& obj)
{

    cout << "Nume Abonament: ";
    cin.ignore(10000, '\n');
    getline(in, obj.numeAbonament);
    cout << "Pret: ";
    in >> obj.pret;

    cout << "Durata (in zile): ";
    in >> obj.durata;

    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm tm = *localtime(&t);
    int zi = tm.tm_mday;
    int luna = tm.tm_mon + 1;
    int an = tm.tm_year + 1900;
    obj.dataIncepere.zi=zi;
    obj.dataIncepere.luna=luna;
    obj.dataIncepere.an=an;

    cout << endl;
    return in;
}

Abonament::operator[](int i)
{

    if(i < 0 || i > 2)
    {
        throw runtime_error("Index invalid");
    }
    else if (i==0)
        return this->dataIncepere.zi;
    if (i==1)
        return this->dataIncepere.luna;
    if (i==2)
        return this->dataIncepere.an;
}
Abonament& Abonament::operator++()
{
    this->pret++;
    return *this;
}

Abonament Abonament::operator++(int)
{
    Abonament aux(*this);
    ++*this;
    return aux;


}

Abonament Abonament::operator+(const Abonament& obj)
{
    Abonament aux(*this);
    aux.pret += obj.pret;
    return aux;
}

Abonament Abonament::operator+(int x)
{
    Abonament aux(*this);
    aux.pret += x;
    return aux;
}

Abonament operator+(int x, Abonament obj)
{
    return obj+x;
}
Abonament Abonament::operator-(const Abonament& obj)
{
    Abonament aux(*this);
    aux.pret -= obj.pret;
    return aux;
}

Abonament Abonament::operator-(int x)
{
    Abonament aux(*this);
    aux.pret -= x;
    return aux;
}

Abonament operator-(int x, Abonament obj)
{
    return obj-x;
}

bool Abonament::operator==(const Abonament& obj)
{
    return this->numeAbonament == obj.numeAbonament;
}
bool Abonament::operator<(const Abonament& obj)
{
    if(this->pret < obj.pret) return 1;
    return 0;
}
bool Abonament::operator>(const Abonament& obj)
{
    if(this->pret > obj.pret) return 1;
    return 0;
}
Abonament::operator int()
{
    return this->pret;
}


class Echipament
{

    string nume;
    int cantitate;
    bool valabil;
    bool mentenanta;



public:


///constuctorii
    Echipament();
    Echipament(string nume, int cantitate, bool valabil, bool mentenanta);
    Echipament(const Echipament& obj);
    Echipament(bool valabil);
    Echipament(string nume);

    ///operatorii
    Echipament& operator=(const Echipament& obj);
    friend ostream& operator<<(ostream& out, const Echipament& obj);
    friend istream& operator>>(istream& in, Echipament& obj);
    int operator[](int);
    Echipament& operator++();
    Echipament operator++(int);
    Echipament operator+(const Echipament& obj);
    Echipament operator+(int);
    friend Echipament operator+(int, Echipament obj);
    Echipament operator-(const Echipament& obj);
    Echipament operator-(int);
    friend Echipament operator-(int, Echipament obj);
    bool operator==(const Echipament&);
    bool operator<(const Echipament& obj);
    bool operator>(const Echipament& obj);
    operator int();

    ///functii utile
    void rezervare()
    {
        if (this->valabil==true && this->mentenanta==false)
        {
            this->valabil = false;
            cout << "Echipament rezervat cu succes." << endl;
        }
        else
        {
            cout << "Echipament indisponibil la momentul actual." << endl;
        }
    }

    void returnare()
    {
        if (this->valabil==false)
        {
            this->valabil = true;
            cout << "Echipament returnat." << endl;
        }
        else
        {
            cout << "Echipamentul e deja returnat." << endl;
        }
    }



    ///getteri & setteri
    int getCantitate();
    bool getValabil();
    bool getMentenanta();
    string getNume();

    void settValabil(bool valabil);
    void settMentenanta(bool mentenanta);
    void settCantitate(int cantitate);
    void settNume(string nume);



    ///destructor
    ~Echipament() {};

};

///ECHIPAMENT

///constructorii
Echipament::Echipament()
{
    nume="Nimic";
    cantitate=0;
    valabil=false;
    mentenanta=false;

}
Echipament::Echipament(string nume, int cantitate, bool valabil, bool mentenanta)
{
    this->nume=nume;
    this->cantitate=cantitate;
    this->valabil=valabil;
    this->mentenanta=mentenanta;



}

Echipament::Echipament(const Echipament& obj)
{
    this->nume=obj.nume;
    this->cantitate=obj.cantitate;
    this->valabil=obj.valabil;
    this->mentenanta=obj.mentenanta;

}

Echipament::Echipament(bool valabil)
{
    this->nume="Nimic";
    this->cantitate=0;
    this->valabil=valabil;
    this->mentenanta=false;

}

Echipament::Echipament(string nume)
{
    this->nume=nume;
    this->cantitate=0;
    this->valabil=true;
    this->mentenanta=false;


}

///getteri & setteri
string Echipament::getNume()
{
    return this->nume;
};
int Echipament::getCantitate()
{
    return this->cantitate;
};
bool Echipament::getValabil()
{
    return this->valabil;
};
bool Echipament::getMentenanta()
{
    return this->mentenanta;
};

void Echipament::settValabil(bool valabil)
{
    this->valabil=valabil;
};
void Echipament::settMentenanta(bool mentenanta)
{
    this->mentenanta=mentenanta;
};
void Echipament::settNume(string nume)
{
    this->nume=nume;
};
void Echipament::settCantitate(int cantitate)
{
    this->cantitate=cantitate;
};



///operatorii
Echipament& Echipament::operator=(const Echipament& obj)
{

    this->nume=obj.nume;
    this->cantitate=obj.cantitate;
    this->valabil=obj.valabil;
    this->mentenanta=obj.mentenanta;

    return *this;

}


ostream& operator<<(ostream& out, const Echipament& obj)
{
    out << "Informatii echipament: " << endl;
    out << "Nume: " << obj.nume << endl;
    out << "Cantitate: " << obj.cantitate << endl;
    out << "Valabil: " << (obj.valabil ? "Da" : "Nu") << endl;
    out << "Mentenanta: " << (obj.mentenanta ? "Da" : "Nu")<<endl;
    out << endl;
    return out;

}



istream& operator >>(istream& in, Echipament& obj)
{

    cout << "Nume: ";
    cin.ignore(10000, '\n');
    getline(in, obj.nume);
    cout << "Cantitate: ";
    in >> obj.cantitate;

    cout << "Valabil (0 sau 1): ";
    in >> obj.valabil;

    cout << "Mentenanta (0 sau 1): ";
    in >> obj.mentenanta;

    cout << endl;
    return in;
}

Echipament::operator[](int i)
{

    if(i < 0 || i > 1)
    {
        throw runtime_error("Index invalid");
    }
    else if (i==0)
        return this->valabil;
    if (i==1)
        return this->mentenanta;

}
Echipament& Echipament::operator++()
{
    this->cantitate++;
    return *this;
}

Echipament Echipament::operator++(int)
{
    Echipament aux(*this);
    ++*this;
    return aux;


}

Echipament Echipament::operator+(const Echipament& obj)
{
    Echipament aux(*this);
    aux.cantitate += obj.cantitate;
    return aux;
}

Echipament Echipament::operator+(int x)
{
    Echipament aux(*this);
    aux.cantitate += x;
    return aux;
}

Echipament operator+(int x, Echipament obj)
{
    return obj+x;
}
Echipament Echipament::operator-(const Echipament& obj)
{
    Echipament aux(*this);
    aux.cantitate -= obj.cantitate;
    return aux;
}

Echipament Echipament::operator-(int x)
{
    Echipament aux(*this);
    aux.cantitate -= x;
    return aux;
}

Echipament operator-(int x, Echipament obj)
{
    return obj-x;
}

bool Echipament::operator==(const Echipament& obj)
{
    return this->nume == obj.nume;
}
bool Echipament::operator<(const Echipament& obj)
{
    if(this->cantitate < obj.cantitate) return 1;
    return 0;
}
bool Echipament::operator>(const Echipament& obj)
{
    if(this->cantitate > obj.cantitate) return 1;
    return 0;
}
Echipament::operator int()
{
    return this->cantitate;
}


///MEMBRU

int Membru::contorId = 0;

///constructorii

Membru::Membru():id(contorId++)
{
    nume=new char[strlen("Anonim")+1];
    strcpy(nume,"Anonim");
    sex='X';
    natural=true;
    anulNasterii=1857;
    inaltime=180;
    kg=79.6;
    grupaPreferata="Spate";
    abonament=NULL;
    antrenorPersonal=NULL;


}
Membru::Membru(char* nume, char sex, bool natural, int anulNasterii, float inaltime,float kg, string grupaPreferata, Antrenor* antrenorPersonal, Abonament* abonament):id(contorId++)
{
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->sex=sex;
    this->natural=natural;
    this->anulNasterii=anulNasterii;
    this->inaltime=inaltime;
    this->kg=kg;
    this->grupaPreferata=grupaPreferata;
    this->antrenorPersonal=antrenorPersonal;
    this->abonament=abonament;
}

Membru::Membru(const Membru& obj):id(contorId++)
{
    this->nume=new char[strlen(obj.nume)+1];
    strcpy(this->nume,obj.nume);
    this->sex=obj.sex;
    this->natural=obj.natural;
    this->anulNasterii=obj.anulNasterii;
    this->inaltime=obj.inaltime;
    this->kg=obj.kg;
    this->grupaPreferata=obj.grupaPreferata;

    this->antrenorPersonal=obj.antrenorPersonal;
    this->abonament=obj.abonament;
}


Membru::Membru(bool natural):id(contorId++)
{
    this->natural=natural;
    this->nume=new char[strlen("Anonim")+1];
    strcpy(this->nume,"Anonim");
    this->sex='X';
    this->anulNasterii=1857;
    this->inaltime=180;
    this->kg=79;
    this->grupaPreferata="Spate";
    this->antrenorPersonal=NULL;
    this->abonament=NULL;


}

Membru::Membru(char* nume):id(contorId++)
{

    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->sex='X';
    this->natural=true;
    this->anulNasterii=1857;
    this->inaltime=180;
    this->kg=79;
    this->grupaPreferata="Spate";
    this->antrenorPersonal=NULL;
    this->abonament=NULL;



}

///getteri & setteri
Membru::getContorId()
{
    return Membru::contorId;
};
Membru::getId()
{
    return this->id;
};
const char* Membru::getNume()
{
    return this->nume;
};
char Membru::getSex()
{
    return this->sex;
};
bool Membru::getNatural()
{
    return this->natural;
};
Membru::getAnulNasterii()
{
    return this->anulNasterii;
};
float Membru::getInaltime()
{
    return this->inaltime;
};
float Membru::getKg()
{
    return this->kg;
};
string Membru::getGrupaPreferata()
{
    return this->grupaPreferata;
};
Antrenor* Membru::getAntrenorPersonal()
{
    return this->antrenorPersonal;
}
Abonament* Membru::getAbonament()
{
    return this->abonament;
}


void Membru::settNume(const char* nume)
{
    if (this->nume!=NULL)
    {
        delete[] nume;
    }
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
}
void Membru::settSex(char sex)
{
    this->sex=sex;
}
void Membru::settNatural(bool natural)
{
    this->natural=natural;
}
void Membru::settAnulNasterii(int anulNasterii)
{
    this->anulNasterii=anulNasterii;
}
void Membru::settInaltime(float inaltime)
{
    this->inaltime=inaltime;
}
void Membru::settKg(float kg)
{
    this->kg=kg;
}
void Membru::settGrupaPreferata(string grupaPreferata)
{
    this->grupaPreferata=grupaPreferata;
}
void Membru::settAntrenorPersonal( Antrenor* antrenor)
{
    this->antrenorPersonal = antrenor;
}
void Membru::settAbonament(Abonament* abonament)
{
    this->abonament = abonament;
}


///operatorii
Membru& Membru::operator=(const Membru& obj)
{
    if (this!=&obj)
    {
        if(this->nume!=NULL)
        {
            delete [] this->nume;
            this->nume=NULL;
        }

        this->nume=new char[strlen(obj.nume)+1];
        strcpy(this->nume,obj.nume);

        this->sex=obj.sex;
        this->natural=obj.natural;
        this->anulNasterii=obj.anulNasterii;
        this->inaltime=obj.inaltime;
        this->kg=obj.kg;
        this->grupaPreferata=obj.grupaPreferata;


        this->antrenorPersonal=obj.antrenorPersonal;


        this->abonament=obj.abonament;

    }
    return *this;

}


ostream& operator<<(ostream& out, const Membru& obj)
{
    out << "Informatii membru: " << endl;
    out << "ID: " << obj.id << endl;
    out << "Nume: " << obj.nume << endl;
    out << "Sex: " << obj.sex << endl;
    out << "Natural: " << (obj.natural ? "Da" : "Nu") << endl;
    out << "Anul Nasterii: " << obj.anulNasterii << endl;
    out << "Inaltime (in cm): "<<obj.inaltime<<endl;
    out << "Kg: " << obj.kg<<endl;
    out << "Grupa Preferata: " << obj.grupaPreferata<<endl;
    if(obj.antrenorPersonal != NULL)
        out << "Antrenor: " << obj.antrenorPersonal->getNume() << endl;
    else out << "Antrenor: Anonim"<<endl;
    if(obj.abonament != NULL)
        out << "Abonament: " << obj.abonament->getNumeAbonament() << endl;
    else out << "Abonament: Neverificat" << endl;
    out << endl;
    return out;

}



istream& operator >>(istream& in, Membru& obj)
{

    cout << "Nume: ";
    char aux[100];
    in >> aux;
    if(obj.nume != NULL)
    {
        delete[] obj.nume;
    }
    obj.nume = new char[strlen(aux)+1];
    strcpy(obj.nume, aux);

    cout << "Sex (M sau F): ";
    in >> obj.sex;

    cout << "Natural (0 sau 1): ";
    in >> obj.natural;

    cout << "Anul Nasterii: ";
    in >> obj.anulNasterii;

    cout << "Inaltime (in cm): ";
    in >> obj.inaltime;

    cout << "Kg: ";
    in >> obj.kg;

    cout << "Grupa Preferata: ";
    cin.ignore(10000, '\n');
    getline(in, obj.grupaPreferata);

    cout << endl;
    return in;
}

float Membru::operator[](int i)
{

    if(i < 1 || i > 2)
    {
        throw runtime_error("Index invalid");
    }
    else if (i==1)
        return this->inaltime;
    if (i==2)
        return this->kg;
}
Membru& Membru::operator++()
{
    this->kg++;
    return *this;
}

Membru Membru::operator++(int)
{
    Membru aux(*this);
    ++*this;
    return aux;


}

Membru Membru::operator+(const Membru& obj)
{
    Membru aux(*this);
    aux.kg += obj.kg;
    return aux;
}

Membru Membru::operator+(int x)
{
    Membru aux(*this);
    aux.kg += x;
    return aux;
}

Membru operator+(int x, Membru obj)
{
    return obj+x;
}
Membru Membru::operator-(const Membru& obj)
{
    Membru aux(*this);
    aux.kg -= obj.kg;
    return aux;
}

Membru Membru::operator-(int x)
{
    Membru aux(*this);
    aux.kg -= x;
    return aux;
}

Membru operator-(int x, Membru obj)
{
    return obj-x;
}

bool Membru::operator==(const Membru& obj)
{
    return this->natural == obj.natural;
}
bool Membru::operator<(const Membru& obj)
{
    if(this->kg < obj.kg) return 1;
    return 0;
}
bool Membru::operator>(const Membru& obj)
{
    if(this->kg > obj.kg) return 1;
    return 0;
}
Membru::operator int()
{
    return this->kg;
}


Membru operator+ (const Membru& obj1, const Antrenor& obj2)
{
    Membru temp(obj1);
    string x;
    x=obj2.getSpecializare();
    temp.grupaPreferata=temp.grupaPreferata+","+x;
    return temp;
}
Membru operator+ (const Antrenor& obj1, const Membru& obj2)
{
    Membru temp(obj2);
    string x;
    x=obj1.getSpecializare();
    temp.grupaPreferata=temp.grupaPreferata+ "," +x;
    return temp;
}
///destructor
Membru::~Membru()
{

    if (this->nume!=NULL)
    {
        delete[] this->nume;
        this->nume=NULL;
    }


    this->abonament=NULL;


    this->antrenorPersonal=NULL;
}







int main()

{


    vector <Echipament> listaEchipamente(7);
    Echipament B1("Banda de alergat", 7, true, false);
    listaEchipamente[0]=B1;
    Echipament B2("Hack squat", 1,  true,  false);
    listaEchipamente[1]=B2;
    Echipament B3("Aparat Lat pulldown", 2,  true,  false);
    listaEchipamente[2]=B3;
    Echipament B4("Bench Press", 3,  true,  false);
    listaEchipamente[3]=B4;
    Echipament B5("Bicicleta", 10,  true,  false);
    listaEchipamente[4]=B5;
    Echipament B6("Presa pentru picioare", 2,  true,  false);
    listaEchipamente[5]=B6;
    Echipament B7("Aparat Lat Row", 4,  true,  false);
    listaEchipamente[6]=B7;
    vector <Abonament> listaAbonamente(4);
    Abonament A1 ("Bronze", 200, 30);
    listaAbonamente[0]=A1;
    Abonament A2 ("Silver", 275, 31);
    listaAbonamente[1]=A2;
    Abonament A3 ("Gold", 325, 32);
    listaAbonamente[2]=A3;
    Abonament A4 ("Platinum", 445, 33);
    listaAbonamente[3]=A4;
    vector <Membru> listaMembrii;
    vector <Antrenor> listaAntrenori(5);


    int v0[]= {1999,2000,2001,2002,2016,2005,2006,2007,2008,2004,2022,2023};
    Antrenor A("Chris Bumstead",'M',false,12,v0, 7000, "Spate");
    listaAntrenori[0]=A;

    int v1[]= {2000,2001,2002,2004,2022,2023};
    Antrenor B( "Alex Eubank",  'M',  true,  6,  v1,  5500,  "Piept");
    listaAntrenori[1]=B;

    int v2[]= {2013,2014,2015,2016,2017,2018,2019,2020,2021,2022,2023};
    Antrenor C( "David Laid",  'M',  true, 10,  v2,  10000,  "Abdomen");
    listaAntrenori[2]=C;

    int v3[]= {2000,2005,2006,2007,2008,2004,2022,2023};
    Antrenor D( "Courtney King",  'F',  false,  8,  v3,  2000,  "Umeri");
    listaAntrenori[3]=D;

    int v4[]= {2021,2022,2023};
    Antrenor E( "Erin Maloney",  'F',  true, 3,  v4, 3500,  "Biceps Femural");
    listaAntrenori[4]=E;


    int k=0;
    int p=0;

    cout << "Bine ati venit la World Class! Alegeti-va functia:" << endl;

    while (true)
    {
        int comanda;
        cout << "\n1-Utilizator/Client";
        cout << "\n2-Admin";
        cout << "\n3-Stop";
        cout << endl;
        cin >> comanda;

        switch (comanda)
        {
        case 1:
        {
            if(p==0)
                displayMeniuUtilizator();
            else
                displayMeniuUtilizator2();

            int comanda2;
            cin >> comanda2;
            switch (comanda2)
            {
            case 1:
            {
                if(p==0)
                {
                    clearScreen();
                    Membru client;
                    cin>>client;
                    listaMembrii.push_back(client);
                    clearScreen();
                }
                else
                    clearScreen();
                while (true)
                {
                    displaySubMeniuUtilizator();
                    if(k<2)
                    {
                        cout<<endl;
                        cout<< "Ajutor : Va rugam sa va selectati Antrenorul Personal si Abonamentul pentru a putea accesa celelalte comenzi."<<endl;
                    }
                    int comanda4;
                    cin >> comanda4;
                    switch (comanda4)
                    {


                    case 1:
                    {
                        clearScreen();
                        for(int i=0; i<listaAntrenori.size(); i++)
                        {
                            cout<<listaAntrenori[i];
                            listaAntrenori[i].vechimeInDomeniu();
                            cout<<endl<<endl<<endl;
                        }
                        cout<<"Introduceti ID-ul antrenorului dorit: ";
                        int id;
                        cin>>id;
                        for(int i=0; i<listaAntrenori.size(); i++)
                            if(id==listaAntrenori[i].getId())
                            {
                                listaMembrii[0].settAntrenorPersonal(&listaAntrenori[i]);


                                break;
                            }
                        k++;
                        p++;
                        clearScreen();
                        break;
                    }
                    case 2:
                    {
                        clearScreen();

                        for(int i=0; i<listaAbonamente.size(); i++)
                            cout<<i<<"."<<listaAbonamente[i]<<endl;
                        cout<<"Introduceti nr-ul abonamentului dorit (data de incepere se va actualiza automat cu data curenta, in momentul selectarii): ";
                        int nr;
                        cin>>nr;
                        for(int i=0; i<listaAbonamente.size(); i++)
                            if(nr==i)
                            {
                                listaMembrii[0].settAbonament(&listaAbonamente[i]);
                                auto now = chrono::system_clock::now();
                                time_t t = chrono::system_clock::to_time_t(now);
                                tm tm = *localtime(&t);
                                int zi = tm.tm_mday;
                                int luna = tm.tm_mon + 1;
                                int an = tm.tm_year + 1900;
                                listaAbonamente[i].settZi(zi);
                                listaAbonamente[i].settLuna(luna);
                                listaAbonamente[i].settAn(an);


                                break;
                            }
                        clearScreen();
                        k++;
                        p++;
                        break;
                    }
                    case 3:
                    {
                        if(k<2)
                        {
                            clearScreen();
                            break;
                        }
                        else
                        {
                            clearScreen();
                            listaMembrii[0].potential();
                            cout<<endl;
                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');
                            clearScreen();
                            break;
                        }


                    }
                    case 4:
                    {
                        if(k<2)
                        {
                            clearScreen();
                            break;
                        }
                        else
                        {
                            clearScreen();
                            listaMembrii[0].getAbonament()->dataIncheiere();
                            cout<<endl;
                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');
                            clearScreen();
                            break;
                        }


                    }
                    case 5:
                    {
                        if(k<2)
                        {
                            clearScreen();
                            break;
                        }
                        else

                        {
                            clearScreen();
                            for(int i=0; i<listaEchipamente.size(); i++)
                                cout<<i<<"."<<listaEchipamente[i]<<endl;
                            cout<<"Introduceti nr-ul echipamentului pe care doriti sa-l rezervati: ";
                            int nr;
                            cin>>nr;
                            for(int i=0; i<listaEchipamente.size(); i++)
                                if(nr==i)
                                {
                                    clearScreen();
                                    listaEchipamente[i].rezervare();



                                }
                            cout<<endl;
                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');
                            clearScreen();
                            break;

                        }


                    }
                    case 6:
                    {
                        if(k<2)
                        {
                            clearScreen();
                            break;
                        }
                        else

                        {
                            clearScreen();
                            for(int i=0; i<listaEchipamente.size(); i++)
                                cout<<i<<"."<<listaEchipamente[i]<<endl;
                            cout<<"Introduceti nr-ul echipamentului pe care doriti sa-l returnati: ";
                            int nr;
                            cin>>nr;
                            for(int i=0; i<listaEchipamente.size(); i++)
                                if(nr==i)
                                {
                                    clearScreen();
                                    listaEchipamente[i].returnare();



                                }
                            cout<<endl;
                            cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                            cin.ignore();
                            while(cin.get() != '\n');
                            clearScreen();
                            break;

                        }


                    }
                    case 7:
                    {
                        clearScreen();
                        p++;
                        break;
                    }


                    default:
                    {
                        clearScreen();
                        cout << "Comanda invalida. Folositi o comanda valida." << endl;
                        break;
                    }

                    }


                    if (comanda4==7)
                    {
                        p++;
                        break;
                    }




                }
            }
            case 2:
            {
                clearScreen();

                break;
            }

            default:
            {
                clearScreen();
                cout << "Comanda invalida. Folositi o comanda valida." << endl;
                break;
            }
            }
            break;
        }
        case 2:
        {
            displayMeniuAdmin();
            string parola;
            char c;
            while ((c = getch()) != '\r')   // se citesc caractere pana se apasa enter
            {
                if (c == '\b' && !parola.empty())   // ca sa mearga backspace
                {
                    parola.pop_back();
                    cout << "\b \b"; // sa stearga si '*' din consola cand apesi backspace
                }
                else if (c != '\b')     // sa ignore backspace, sa nu il ia ca si caracter
                {
                    parola += c;
                    cout << "*";
                }
            }
            cout << endl;
            if (parola == "1234")
            {
                while (true)
                {
                    displaySubMeniuAdmin();
                    int comanda3;
                    cin >> comanda3;
                    switch (comanda3)
                    {


                    case 1:
                    {
                        clearScreen();
                        Membru A;
                        cin >> A;
                        listaMembrii.push_back(A);
                        clearScreen();
                        break;
                    }
                    case 2:
                    {
                        clearScreen();
                        Antrenor A;
                        cin >> A;
                        listaAntrenori.push_back(A);
                        clearScreen();
                        break;
                    }
                    case 3:
                    {
                        clearScreen();
                        Abonament A;
                        cin >> A;
                        listaAbonamente.push_back(A);
                        clearScreen();
                        break;
                    }
                    case 4:
                    {
                        clearScreen();
                        Echipament A;
                        cin >> A;
                        listaEchipamente.push_back(A);
                        clearScreen();
                        break;
                    }
                    case 5:
                    {
                        clearScreen();
                        if(listaMembrii.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaMembrii.size(); i++)
                            cout<<listaMembrii[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clearScreen();
                        break;

                    }
                    case 6:
                    {
                        clearScreen();
                        if(listaAntrenori.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaAntrenori.size(); i++)
                            cout<<listaAntrenori[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clearScreen();
                        break;

                    }
                    case 7:
                    {
                        clearScreen();
                        if(listaAbonamente.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaAbonamente.size(); i++)
                            cout<<listaAbonamente[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clearScreen();
                        break;

                    }
                    case 8:
                    {
                        clearScreen();
                        if(listaEchipamente.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaEchipamente.size(); i++)
                            cout<<listaEchipamente[i]<<endl;
                        cout<<"Apasa 'enter' pentru a reveni la meniu."<<endl;
                        cin.ignore();
                        while(cin.get() != '\n');
                        clearScreen();
                        break;



                    }
                    case 9:
                    {
                        clearScreen();
                        if(listaMembrii.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaMembrii.size(); i++)
                            cout<<listaMembrii[i]<<endl;
                        cout<<"Introduceti ID-ul membrului pe care doriti sa-l eliminati: ";
                        int id;
                        cin>>id;
                        for(int i=0; i<listaMembrii.size(); i++)
                            if(id==listaMembrii[i].getId())
                                listaMembrii.erase(listaMembrii.begin()+i);

                        clearScreen();
                        break;
                    }
                    case 10:
                    {
                        clearScreen();
                        if(listaAntrenori.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaAntrenori.size(); i++)
                            cout<<listaAntrenori[i]<<endl;
                        cout<<"Introduceti ID-ul antrenorului pe care doriti sa-l eliminati: ";
                        int id;
                        cin>>id;
                        for(int i=0; i<listaAntrenori.size(); i++)
                            if(id==listaAntrenori[i].getId())
                                listaAntrenori.erase(listaAntrenori.begin()+i);

                        clearScreen();
                        break;
                    }
                    case 11:
                    {

                        clearScreen();
                        if(listaAbonamente.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaAbonamente.size(); i++)
                            cout<<i<<"."<<listaAbonamente[i]<<endl;
                        cout<<"Introduceti nr-ul abonamentului pe care doriti sa-l stergeti: ";
                        int nr;
                        cin>>nr;
                        for(int i=0; i<listaAbonamente.size(); i++)
                            if(nr==i)
                            {
                                listaAbonamente.erase(listaAbonamente.begin()+i);


                                break;
                            }
                        clearScreen();
                        break;

                    }
                    case 12:
                    {

                        clearScreen();
                        if(listaEchipamente.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaEchipamente.size(); i++)
                            cout<<i<<"."<<listaEchipamente[i]<<endl;
                        cout<<"Introduceti nr-ul echipamentului pe care doriti sa-l stergeti: ";
                        int nr;
                        cin>>nr;
                        for(int i=0; i<listaEchipamente.size(); i++)
                            if(nr==i)
                            {
                                listaEchipamente.erase(listaEchipamente.begin()+i);


                                break;
                            }
                        clearScreen();
                        break;

                    }


                    case 13:
                    {
                        clearScreen();
                        if(listaAntrenori.size()==0)
                        {
                            clearScreen();
                            break;
                        }
                        for(int i=0; i<listaAntrenori.size(); i++)
                            cout<<listaAntrenori[i]<<endl;
                        cout<<"Introduceti ID-ul antrenorului caruia doriti sa ii schimbati salariul: ";
                        int id;
                        cin>>id;
                        cout<<endl;
                        cout<<"Introduceti '+' daca doriti sa mariti salariul antrenorului respectiv sau '-' daca doriti sa miscorati salariul antrenorului respectiv: ";
                        char x;
                        cin>>x;
                        cout<<endl;
                        cout<<"Introduceti suma cu care doriti sa modificati salariul: ";
                        int suma;
                        cin>>suma;
                        cout<<endl;
                        for(int i=0; i<listaAntrenori.size(); i++)
                            if(id==listaAntrenori[i].getId())
                            {
                                if(x=='+')
                                    listaAntrenori[i]=listaAntrenori[i]+suma;
                                if(x=='-')
                                    listaAntrenori[i]=listaAntrenori[i]-suma;
                            }

                        clearScreen();
                        break;
                    }
                    case 14:
                    {
                        clearScreen();
                        for(int i=0; i<listaEchipamente.size(); i++)
                            cout<<i<<"."<<listaEchipamente[i]<<endl;
                        cout<<"Introduceti nr-ul echipamentului caruia doriti sa ii schimbati starea de mentenanta: ";
                        int nr;
                        cin>>nr;
                        cout<<endl;
                        cout<<"Introduceti noua stare de mentenanta (0 sau 1) a echipamentului: ";
                        bool stare;
                        cin>>stare;
                        for(int i=0; i<listaEchipamente.size(); i++)
                            if(nr==i)
                            {
                                clearScreen();
                                listaEchipamente[i].settMentenanta(stare);



                            }

                        clearScreen();
                        break;
                    }

                    case 15:
                    {
                        clearScreen();
                        break;
                    }


                    default:
                    {
                        clearScreen();
                        cout << "Comanda invalida. Folositi o comanda valida." << endl;
                        break;
                    }

                    }


                    if (comanda3==15)
                        break;
                }


            }
            else
            {
                cout<<endl;
                cout << "Acces restrictionat. Parola incorecta." << endl;
                pauza(3);
                clearScreen();
            }
            break;
        }
        case 3:
        {

            break;
        }
        default:
        {
            clearScreen();
            cout << "Comanda invalida. Folositi o comanda valida." << endl;
            break;
        }
        }
        if(comanda==3)
        {
            clearScreen();
            break;

        }
    }
    cout<<"La revedere! -Echipa World Class" << endl;

    return 0;


}
