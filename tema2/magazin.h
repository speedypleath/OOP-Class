#ifndef MAGAZIN_H_INCLUDED
#define MAGAZIN_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
class Produs
{
    float pret;
    float cost;
    unsigned stoc;
    std::string unitate_masura;
protected:
    vector <string> caracteristici;
public:
    Produs(float p=0,float c=0, unsigned s=0,std::string u=""):pret(p),cost(c),stoc(s),unitate_masura(u){}
    Produs(Produs& other);
    virtual void afisare(ostream & out);
    virtual void citire(istream & in);
    virtual string nume_produs() = 0;
    Produs& operator =(const Produs &other);
    friend ostream & operator <<(ostream & out,Produs& ob); ///stiu ca nu e nevoie sa fie friend dar daca nu fac asta nu o pot pune in magazin.cpp
    friend istream & operator >>(istream & in,Produs& ob);
    unsigned match(vector <string> aux);
    unsigned get_stoc(){return stoc;}
    float profit(){return pret/cost;}
    float get_pret(){return pret;}
    void remake(){stoc++;}
    virtual ~Produs() = 0;
    float sell(unsigned nr);
};
class Varza: public Produs
{
public:
    Varza(float p=0,float c=0, unsigned s=0):Produs(p,c,s,"Buc"){caracteristici.push_back(nume_produs());}
    Varza(Varza &other):Produs(other){}
    string nume_produs() override {return "varza";}
    void afisare(ostream & out) override;
};
class Bere: public Produs
{
    std::string brand;
    std::string tip;
public:
    Bere(float p=0,float c=0, unsigned s=0,std::string b="",std::string t=""):Produs(p,c,s,"Buc"),brand(b),tip(t){caracteristici.push_back(nume_produs());caracteristici.push_back(b);caracteristici.push_back(t);}
    Bere(Bere &other):Produs(other),brand(other.brand),tip(other.tip){}
    string nume_produs() override {return "bere";}
    void afisare(ostream & out) override;
    void citire(istream & in) override;
    Bere& operator =(Bere& other);
};
class Faina: public Produs
{
    string calitate;
public:
    Faina(float p=0,float c=0, unsigned s=0, string cal="I"):Produs(p,c,s,"kg"),calitate(cal){caracteristici.push_back(nume_produs());caracteristici.push_back(cal);}
    Faina(Faina &other):Produs(other),calitate(other.calitate){}
    string nume_produs() override {return "faina";}
    void afisare (ostream &out) override;
    void citire(istream &in) override;
    Faina& operator=(Faina &other);
};
class Cartofi: public Produs
{
    string tip;
public:
    Cartofi(float p=0,float c=0, unsigned s=0, string t="rosii"):Produs(p,c,s,"kg"),tip(t){caracteristici.push_back(nume_produs());caracteristici.push_back(t);}
    Cartofi(Cartofi &other):Produs(other),tip(other.tip){}
    string nume_produs() override {return "cartofi";}
    void afisare(ostream &out) override;
    void citire(istream &in) override;
    Cartofi& operator=(Cartofi &other);
};
class Vin: public Produs
{
    string tip;
public:
    Vin(float p=0,float c=0, unsigned s=0, string t="rosu sec",string u=""):Produs(p,c,s,u),tip(t){
        caracteristici.push_back(nume_produs());
        istringstream iss(tip);
        vector<string> results(istream_iterator<string>{iss},istream_iterator<string>());
        caracteristici.insert(caracteristici.begin(),results.begin(),results.end());
        }
    Vin(Vin &other):Produs(other),tip(other.tip){}
    virtual string nume_produs() override {return "vin";}
    void afisare(ostream &out) override;
    void citire(istream &in) override;
    Vin& operator=(Vin &other);
    virtual ~Vin() = 0;
};
class Varsat: public Vin
{
public:
    Varsat(float p=0,float c=0, unsigned s=0, string t="rosu sec"):Vin(p,c,s,t,"Vol"){caracteristici.push_back("varsat");}
    Varsat(Varsat &other):Vin(other){}
    virtual string nume_produs() override {return Vin::nume_produs()+" varsat";}
    void afisare(ostream &out) override;
};
class Soi: public Vin
{
    string an;
    string tara;
    string brand;
public:
    Soi(float p=0,float c=0, unsigned s=0, string t="rosu sec",string a=0,string ta="",string b=""):Vin(p,c,s,t,"Buc"),an(a),tara(ta),brand(b){caracteristici.push_back("soi");caracteristici.push_back(a);caracteristici.push_back(ta);caracteristici.push_back(b);}
    Soi(Soi &other):Vin(other){}
    virtual string nume_produs() override {return Vin::nume_produs()+" de soi";}
    void afisare(ostream &out) override;
    void citire(istream &in) override;
    Soi& operator=(Soi &other);
};
class Jucarie: public Produs
{
    string nume;
public:
    Jucarie(float p=0,float c=0, string t="Papusa",string u="buc", unsigned s=1):Produs(p,c,1,"Buc"),nume(t){caracteristici.push_back(nume_produs());caracteristici.push_back(t);}
    Jucarie(Jucarie &other):Produs(other),nume(other.nume){}
    virtual string nume_produs() override {return "jucarie";}
    void afisare(ostream &out) override;
    void citire(istream &in) override;
    Jucarie& operator=(Jucarie &other);
};
#endif // MAGAZIN_H_INCLUDED
