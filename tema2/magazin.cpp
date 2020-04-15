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
    in>>pret>>cost>>stoc;
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
    in>>brand>>tip;
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
    in>>calitate;
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
    in>>tip;
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
    in>>tip;
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
    cin>>an>>brand>>tara;
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
    Produs::citire(in);
    in>>nume;
}
Jucarie& Jucarie::operator=(Jucarie& other)
{
    this->Produs::operator=(other);
    nume = other.nume;
    return *this;
}
