#include "parc.h"
#include <bits/stdc++.h>
ostream & operator <<(ostream & out,Masina& ob)
{
    ob.afisare(out);
    return out;
}
istream & operator >>(istream & in,Masina& ob)
{
    ob.citire(in);
    return in;
}
void Masina::afisare(ostream & out)
{
    if(nume == ""){
        out<<"masina nu exista!!";
        return;
    }
    out<<"nume:"<<nume<<" pret:"<<pret<<" Litraj:"<<litraj<<" Lungime:"<<lungime;
}
void Masina::citire(istream &in)
{
    try{
    cout<<"Lungime:";in>>lungime;
    check();
    cout<<"Nume:";in>>nume;cout<<"pret:";in>>pret;cout<<"Litraj:";in>>litraj;
    }catch(LungimeGresita a){
    cout<<a.what();
    lungime = 0;
    }
}
void Compacta::citire(istream &in)
{
    Masina::citire(in);
    cout<<"tip:";in>>tip;
}
void Compacta::afisare(ostream& out)
{
    Masina::afisare(out);
    out<<" tip:"<<tip;
}
Masina::~Masina(){}
void Monovolum::discount(unsigned luna)
{
    pret = pret*(100-vechime*3)/100;
    if(luna>=6&&luna<=9)
        pret = pret*90/100;
}
void Monovolum::citire(istream &in)
{
    Masina::citire(in);
    cout<<"vechime:";cin>>vechime;
}
void Monovolum::afisare(ostream& out)
{
    Masina::afisare(out);
    if(vechime==0)
        out<<"sh:nu";
    else
        out<<"sh:da\nani vechime:"<<vechime<<'\n';
}
User* User::instance = nullptr;

