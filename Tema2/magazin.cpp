#include "magazin.h"
#include <bits/stdc++.h>
using namespace std;
ostream & operator <<(ostream & out,Produs& ob)
{
    ob.afisare(out);
    return out;
}
istream & operator >>(istream & in,Produs& ob)
{
    ob.citire(in);
    return in;
}
Produs& Produs::operator =(const Produs &other)
{
    pret = other.pret;
    cost = other.cost;
    stoc = other.stoc;
    unitate_masura = other.unitate_masura;
    caracteristici = other.caracteristici;
    return *this;
}
void Produs::afisare(ostream & out)
{
    out<<"Pret:"<<pret<<" Cost:"<<cost<<" Stoc disponibil:"<<stoc;
}
void Produs::citire(istream &in)
{
    cout<<"pret:";in>>pret;cout<<"cost:";in>>cost;
    do{
    try{
    cout<<"stoc:";in>>stoc;
    if(!stoc)
        throw(stoc);
    }
    catch(...){cout<<"Stocul nu poate sa fie 0!!!\n";}
    }while(!stoc);
    caracteristici.clear();
    caracteristici.push_back(nume_produs());
}
Produs::Produs(Produs& other)
{
    pret = other.pret;
    cost = other.cost;
    stoc = other.stoc;
    unitate_masura = other.unitate_masura;
    caracteristici = other.caracteristici;
}
unsigned Produs::match(vector <string> aux)
{
    unsigned c=0;
    for(auto i:aux)
        for(auto j:caracteristici)
            if(i==j)
                c++;
    return c;

}
Produs::~Produs(){}
float Produs::sell(unsigned nr)
{
    if(stoc >= nr){
        stoc -= nr;
        return (pret-cost)*nr;
    }
    else
        return -1;
}
void Varza::afisare(ostream & out)
{
    out<<"Produs:"<<nume_produs();
    out<<'\n';
    Produs::afisare(out);
    out<<'\n';
}
void Bere::afisare(ostream & out)
{
    out<<"Produs:"<<nume_produs();
    out<<'\n';
    Produs::afisare(out);
    out<<"\nBrand:"<<brand<<" Tip:"<<tip<<endl;
}
void Bere::citire(istream &in)
{
    Produs::citire(in);
    cout<<"brand:";in>>brand;cout<<"tip:";in>>tip;
    caracteristici.push_back(brand);caracteristici.push_back(tip);
}
Bere& Bere::operator =(Bere& other)
{
    this->Produs::operator=(other);
    brand = other.brand;
    tip = other.tip;
    return *this;
}
void Faina::afisare(ostream &out)
{
    out<<"Produs:"<<nume_produs();
    out<<'\n';
    Produs::afisare(out);
    out<<"\nCalitate:"<<calitate<<'\n';
}
void Faina::citire(istream &in)
{
    Produs::citire(in);
    cout<<"calitate:";in>>calitate;
    caracteristici.push_back(calitate);
}
Faina& Faina::operator=(Faina& other)
{
    this->Produs::operator=(other);
    calitate = other.calitate;
    return *this;
}
void Cartofi::afisare(ostream &out)
{
    out<<"Produs:"<<nume_produs();
    out<<'\n';
    Produs::afisare(out);
    out<<"\nTip:"<<tip<<'\n';
}
void Cartofi::citire(istream &in)
{
    Produs::citire(in);
    cout<<"tip:";in>>tip;
    caracteristici.push_back(tip);
}
Cartofi& Cartofi::operator=(Cartofi& other)
{
    this->Produs::operator=(other);
    tip = other.tip;
    return *this;
}
void Vin::afisare(ostream &out)
{
    Produs::afisare(out);
    out<<"\nTip:"<<tip<<'\n';
}
void Vin::citire(istream &in)
{
    Produs::citire(in);
    cout<<"tip:";in.ignore();getline(in,tip);
    istringstream iss(tip);
    vector<string> results(istream_iterator<string>{iss},istream_iterator<string>());
    caracteristici.insert(caracteristici.begin(),results.begin(),results.end());
}
Vin& Vin::operator=(Vin& other)
{
    this->Produs::operator=(other);
    tip = other.tip;
    return *this;
}
Vin::~Vin(){}
void Varsat::afisare(ostream &out)
{
    out<<"Produs:"<<nume_produs();
    out<<'\n';
    Vin::afisare(out);
}

void Soi::afisare(ostream &out)
{
    out<<"Produs:"<<nume_produs();
    out<<'\n';
    Vin::afisare(out);
    out<<"An fabricatie:"<<an<<" Nume:"<<brand<<" Tara origine:"<<tara<<'\n';
}

void Soi::citire(istream &in)
{
    Vin::citire(in);
    cout<<"an:";in>>an;cout<<"brand:";in>>brand;cout<<"tara:";in>>tara;
    caracteristici.push_back(an);caracteristici.push_back(brand);caracteristici.push_back(tara);
}
Soi& Soi::operator=(Soi& other)
{
    this->Vin::operator=(other);
    an = other.an;
    brand = other.brand;
    tara = other.tara;
    return *this;
}
void Jucarie::afisare(ostream &out)
{
    Produs::afisare(out);
    out<<"\nNume Jucarie:"<<nume<<'\n';
}
void Jucarie::citire(istream &in)
{
    stoc = 1;
    cout<<"pret:";in>>pret;
    cout<<"cost:";in>>cost;
    cout<<"nume:";in>>nume;
    caracteristici.push_back(nume);
}
Jucarie& Jucarie::operator=(Jucarie& other)
{
    this->Produs::operator=(other);
    nume = other.nume;
    return *this;
}
